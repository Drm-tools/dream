
#include <queue>
#include <mutex>
#include <cstring>
#include "jack.h"

// ============================================================================
// CJackSoundIn Implementation
// ============================================================================

CJackSoundIn::CJackSoundIn()
    : client_(nullptr)
    , input_port_(nullptr)
    , device_name_("default")
    , buffer_size_(0)
    , sample_rate_(0)
    , initialized_(false)
{
}

CJackSoundIn::~CJackSoundIn()
{
    Close();
}

void CJackSoundIn::Enumerate(std::vector<std::string>& names, std::vector<std::string>& descriptions, std::string& defaultDevice)
{
    names.clear();
    descriptions.clear();
    
    // Need a temporary client to query ports
    jack_client_t* temp_client = nullptr;
    jack_status_t status;
    temp_client = jack_client_open("temp_enum", JackNullOption, &status);
    
    if (!temp_client) {
        defaultDevice = "";
        return;
    }
    
    // Get all capture ports (physical outputs that we can capture from)
    const char** ports = jack_get_ports(temp_client, nullptr, JACK_DEFAULT_AUDIO_TYPE, 
                                       JackPortIsOutput);
    
    if (ports) {
        for (int i = 0; ports[i] != nullptr; i++) {
            names.push_back(ports[i]);
            
            // Try to get port alias as friendly name
            jack_port_t* port = jack_port_by_name(temp_client, ports[i]);
            if (port) {
                char aliases[2][jack_port_name_size()];
                int num_aliases = jack_port_get_aliases(port, aliases);
                if (num_aliases > 0) {
                    descriptions.push_back(aliases[0]);
                } else {
                    descriptions.push_back(ports[i]);
                }
            } else {
                descriptions.push_back(ports[i]);
            }
        }
        jack_free(ports);
    }
    
    // Set default to first physical capture port if available
    const char** physical_ports = jack_get_ports(temp_client, nullptr, JACK_DEFAULT_AUDIO_TYPE,
                                                 JackPortIsPhysical | JackPortIsOutput);
    if (physical_ports && physical_ports[0]) {
        defaultDevice = physical_ports[0];
        jack_free(physical_ports);
    } else if (!names.empty()) {
        defaultDevice = names[0];
    } else {
        defaultDevice = "";
    }
    
    jack_client_close(temp_client);
}

std::string CJackSoundIn::GetItemName()
{
    return device_name_;
}

void CJackSoundIn::SetItem(std::string sNewDev)
{
    if (!initialized_ || !client_ || !input_port_) {
        device_name_ = sNewDev;
        return;
    }
    
    // Disconnect all existing connections to our input port
    const char** connections = jack_port_get_all_connections(client_, input_port_);
    if (connections) {
        for (int i = 0; connections[i] != nullptr; i++) {
            jack_disconnect(client_, connections[i], jack_port_name(input_port_));
        }
        jack_free(connections);
    }
    
    // Connect to the new source port
    if (!sNewDev.empty()) {
        if (jack_connect(client_, sNewDev.c_str(), jack_port_name(input_port_)) == 0) {
            device_name_ = sNewDev;
        }
    } else {
        device_name_ = "";
    }
}

bool CJackSoundIn::Init(int iSampleRate, size_t iNewBufferSize, bool)
{
    if (initialized_) {
        Close();
    }

    sample_rate_ = iSampleRate;
    buffer_size_ = iNewBufferSize;

    // Open JACK client
    jack_status_t status;
    client_ = jack_client_open("audio_capture", JackNullOption, &status);
    if (!client_) {
        return false;
    }

    // Check sample rate
    jack_nframes_t jack_sr = jack_get_sample_rate(client_);
    if ((int)jack_sr != iSampleRate) {
        // JACK is running at different rate - you may want to handle this
    }

    // Register input port
    input_port_ = jack_port_register(client_, "input", JACK_DEFAULT_AUDIO_TYPE, JackPortIsInput, 0);
    if (!input_port_) {
        jack_client_close(client_);
        client_ = nullptr;
        return false;
    }

    // Set process callback
    jack_set_process_callback(client_, process_callback, this);

    // Activate client
    if (jack_activate(client_) != 0) {
        jack_client_close(client_);
        client_ = nullptr;
        return false;
    }

    // Optionally auto-connect to system capture ports
    const char** ports = jack_get_ports(client_, nullptr, nullptr, JackPortIsPhysical | JackPortIsOutput);
    if (ports && ports[0]) {
        jack_connect(client_, ports[0], jack_port_name(input_port_));
        device_name_ = ports[0];  // Store the connected port name
    }
    if (ports) {
        jack_free(ports);
    }

    initialized_ = true;
    return true;
}

int CJackSoundIn::process_callback(jack_nframes_t nframes, void* arg)
{
    CJackSoundIn* self = static_cast<CJackSoundIn*>(arg);
    self->ProcessAudio(nframes);
    return 0;
}

void CJackSoundIn::ProcessAudio(jack_nframes_t nframes)
{
    jack_default_audio_sample_t* in = (jack_default_audio_sample_t*)jack_port_get_buffer(input_port_, nframes);
    
    // Convert float samples to int16_t
    std::vector<int16_t> buffer(nframes);
    for (size_t i = 0; i < nframes; i++) {
        float sample = in[i];
        if (sample > 1.0f) sample = 1.0f;
        if (sample < -1.0f) sample = -1.0f;
        buffer[i] = static_cast<int16_t>(sample * 32767.0f);
    }

    // Store in queue
    std::lock_guard<std::mutex> lock(queue_mutex_);
    audio_queue_.push(buffer);
    
    // Limit queue size to prevent unbounded growth
    while (audio_queue_.size() > 100) {
        audio_queue_.pop();
    }
}

bool CJackSoundIn::Read(CVector<short>& data)
{
    std::lock_guard<std::mutex> lock(queue_mutex_);
    
    if (audio_queue_.empty()) {
        data.clear();
        return false;
    }

    const std::vector<int16_t>& buffer = audio_queue_.front();
    data.resize(buffer.size());
    std::memcpy(data.data(), buffer.data(), buffer.size() * sizeof(int16_t));
    audio_queue_.pop();
    
    return true;
}

void CJackSoundIn::Close()
{
    if (client_) {
        jack_deactivate(client_);
        jack_client_close(client_);
        client_ = nullptr;
        input_port_ = nullptr;
    }
    
    std::lock_guard<std::mutex> lock(queue_mutex_);
    while (!audio_queue_.empty()) {
        audio_queue_.pop();
    }
    
    initialized_ = false;
}

std::string CJackSoundIn::GetVersion()
{
    jack_client_t* temp_client = nullptr;
    jack_status_t status;
    temp_client = jack_client_open("temp_version", JackNullOption, &status);
    
    if (!temp_client) {
        return "JACK (version unknown)";
    }
    
    int major, minor, micro, proto;
    jack_get_version(&major, &minor, &micro, &proto);
    
    jack_client_close(temp_client);
    
    char version_str[64];
    snprintf(version_str, sizeof(version_str), "JACK %d.%d.%d (protocol %d)", 
             major, minor, micro, proto);
    
    return std::string(version_str);
}

// ============================================================================
// CJackSoundOut Implementation
// ============================================================================

CJackSoundOut::CJackSoundOut()
    : client_(nullptr)
    , output_port_(nullptr)
    , device_name_("default")
    , buffer_size_(0)
    , sample_rate_(0)
    , initialized_(false)
{
}

CJackSoundOut::~CJackSoundOut()
{
    Close();
}

void CJackSoundOut::Enumerate(std::vector<std::string>& names, std::vector<std::string>& descriptions, std::string& defaultDevice)
{
    names.clear();
    descriptions.clear();
    
    // Need a temporary client to query ports
    jack_client_t* temp_client = nullptr;
    jack_status_t status;
    temp_client = jack_client_open("temp_enum", JackNullOption, &status);
    
    if (!temp_client) {
        defaultDevice = "";
        return;
    }
    
    // Get all playback ports (physical inputs that we can send to)
    const char** ports = jack_get_ports(temp_client, nullptr, JACK_DEFAULT_AUDIO_TYPE,
                                       JackPortIsInput);
    
    if (ports) {
        for (int i = 0; ports[i] != nullptr; i++) {
            names.push_back(ports[i]);
            
            // Try to get port alias as friendly name
            jack_port_t* port = jack_port_by_name(temp_client, ports[i]);
            if (port) {
                char aliases[2][jack_port_name_size()];
                int num_aliases = jack_port_get_aliases(port, aliases);
                if (num_aliases > 0) {
                    descriptions.push_back(aliases[0]);
                } else {
                    descriptions.push_back(ports[i]);
                }
            } else {
                descriptions.push_back(ports[i]);
            }
        }
        jack_free(ports);
    }
    
    // Set default to first physical playback port if available
    const char** physical_ports = jack_get_ports(temp_client, nullptr, JACK_DEFAULT_AUDIO_TYPE,
                                                 JackPortIsPhysical | JackPortIsInput);
    if (physical_ports && physical_ports[0]) {
        defaultDevice = physical_ports[0];
        jack_free(physical_ports);
    } else if (!names.empty()) {
        defaultDevice = names[0];
    } else {
        defaultDevice = "";
    }
    
    jack_client_close(temp_client);
}

std::string CJackSoundOut::GetItemName()
{
    return device_name_;
}

void CJackSoundOut::SetItem(std::string sNewDev)
{
    if (!initialized_ || !client_ || !output_port_) {
        device_name_ = sNewDev;
        return;
    }
    
    // Disconnect all existing connections from our output port
    const char** connections = jack_port_get_all_connections(client_, output_port_);
    if (connections) {
        for (int i = 0; connections[i] != nullptr; i++) {
            jack_disconnect(client_, jack_port_name(output_port_), connections[i]);
        }
        jack_free(connections);
    }
    
    // Connect to the new destination port
    if (!sNewDev.empty()) {
        if (jack_connect(client_, jack_port_name(output_port_), sNewDev.c_str()) == 0) {
            device_name_ = sNewDev;
        }
    } else {
        device_name_ = "";
    }
}

bool CJackSoundOut::Init(int sampleRate, size_t bufferSize, bool)
{
    if (initialized_) {
        Close();
    }

    sample_rate_ = sampleRate;
    buffer_size_ = bufferSize;

    // Open JACK client
    jack_status_t status;
    client_ = jack_client_open("audio_playback", JackNullOption, &status);
    if (!client_) {
        return false;
    }

    // Register output port
    output_port_ = jack_port_register(client_, "output", JACK_DEFAULT_AUDIO_TYPE, JackPortIsOutput, 0);
    if (!output_port_) {
        jack_client_close(client_);
        client_ = nullptr;
        return false;
    }

    // Set process callback
    jack_set_process_callback(client_, process_callback, this);

    // Activate client
    if (jack_activate(client_) != 0) {
        jack_client_close(client_);
        client_ = nullptr;
        return false;
    }

    // Optionally auto-connect to system playback ports
    const char** ports = jack_get_ports(client_, nullptr, nullptr, JackPortIsPhysical | JackPortIsInput);
    if (ports && ports[0]) {
        jack_connect(client_, jack_port_name(output_port_), ports[0]);
        device_name_ = ports[0];  // Store the connected port name
    }
    if (ports) {
        jack_free(ports);
    }

    initialized_ = true;
    return true;
}

int CJackSoundOut::process_callback(jack_nframes_t nframes, void* arg)
{
    CJackSoundOut* self = static_cast<CJackSoundOut*>(arg);
    self->ProcessAudio(nframes);
    return 0;
}

void CJackSoundOut::ProcessAudio(jack_nframes_t nframes)
{
    jack_default_audio_sample_t* out = (jack_default_audio_sample_t*)jack_port_get_buffer(output_port_, nframes);
    
    std::lock_guard<std::mutex> lock(queue_mutex_);
    
    if (audio_queue_.empty()) {
        // No data available - output silence
        std::memset(out, 0, nframes * sizeof(jack_default_audio_sample_t));
        return;
    }

    const std::vector<int16_t>& buffer = audio_queue_.front();
    size_t samples_to_copy = std::min((size_t)nframes, buffer.size());
    
    // Convert int16_t to float
    for (size_t i = 0; i < samples_to_copy; i++) {
        out[i] = buffer[i] / 32768.0f;
    }
    
    // Fill remainder with silence if needed
    if (samples_to_copy < nframes) {
        std::memset(out + samples_to_copy, 0, (nframes - samples_to_copy) * sizeof(jack_default_audio_sample_t));
    }
    
    audio_queue_.pop();
}

bool CJackSoundOut::Write(CVector<short>& data)
{
    std::vector<int16_t> buffer(data.size());
    std::memcpy(buffer.data(), data.data(), data.size() * sizeof(int16_t));
    
    std::lock_guard<std::mutex> lock(queue_mutex_);
    audio_queue_.push(buffer);
    
    // Limit queue size
    while (audio_queue_.size() > 100) {
        audio_queue_.pop();
    }
    
    return true;
}

void CJackSoundOut::Close()
{
    if (client_) {
        jack_deactivate(client_);
        jack_client_close(client_);
        client_ = nullptr;
        output_port_ = nullptr;
    }
    
    std::lock_guard<std::mutex> lock(queue_mutex_);
    while (!audio_queue_.empty()) {
        audio_queue_.pop();
    }
    
    initialized_ = false;
}

std::string CJackSoundOut::GetVersion()
{
    jack_client_t* temp_client = nullptr;
    jack_status_t status;
    temp_client = jack_client_open("temp_version", JackNullOption, &status);
    
    if (!temp_client) {
        return "JACK (version unknown)";
    }
    
    int major, minor, micro, proto;
    jack_get_version(&major, &minor, &micro, &proto);
    
    jack_client_close(temp_client);
    
    char version_str[64];
    snprintf(version_str, sizeof(version_str), "JACK %d.%d.%d (protocol %d)", 
             major, minor, micro, proto);
    
    return std::string(version_str);
}
