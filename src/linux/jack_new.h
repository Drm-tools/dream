#ifndef JACK_AUDIO_1_H
#define JACK_AUDIO_1_H

#include <jack/jack.h>
#include <vector>
#include <string>
#include <queue>
#include <mutex>
#include <cstring>
#include "../sound/soundinterface.h"

class CSoundInJack : public CSoundInInterface
{
public:
    CSoundInJack();
    virtual ~CSoundInJack();

    // CSelectionInterface
    virtual void Enumerate(std::vector<std::string>& names, std::vector<std::string>& descriptions, std::string& defaultDevice) override;
    virtual std::string GetItemName() override;
    virtual void SetItem(std::string sNewDev) override;

    // CSoundInInterface
    virtual bool Init(int iSampleRate, int iNewBufferSize, bool) override;
    virtual bool Read(CVector<short>& psData, CParameter&) override;
    virtual void Close() override;
    virtual std::string GetVersion() override;
    virtual CSoundInInterface* GetItem() override { return this; }

private:
    static int process_callback(jack_nframes_t nframes, void* arg);
    void ProcessAudio(jack_nframes_t nframes);

    jack_client_t* client_;
    jack_port_t* input_port_;
    std::string device_name_;
    size_t buffer_size_;
    int sample_rate_;
    
    std::queue<std::vector<int16_t>> audio_queue_;
    std::mutex queue_mutex_;
    bool initialized_;
};

// JACK Output Implementation
class CSoundOutJack : public CSoundOutInterface
{
public:
    CSoundOutJack();
    virtual ~CSoundOutJack();

    // CSelectionInterface
    virtual void Enumerate(std::vector<std::string>& names, std::vector<std::string>& descriptions, std::string& defaultDevice) override;
    virtual std::string GetItemName() override;
    virtual void SetItem(std::string sNewDev) override;

    // CSoundOutInterface
    virtual bool Init(int sampleRate, int bufferSize, bool) override;
    virtual bool Write(CVector<short>& psData) override;
    virtual void Close() override;
    virtual std::string GetVersion() override;
    virtual CSoundOutInterface* GetItem() override { return this; }

private:
    static int process_callback(jack_nframes_t nframes, void* arg);
    void ProcessAudio(jack_nframes_t nframes);

    jack_client_t* client_;
    jack_port_t* output_port_;
    std::string device_name_;
    size_t buffer_size_;
    int sample_rate_;
    
    std::queue<std::vector<int16_t>> audio_queue_;
    std::mutex queue_mutex_;
    bool initialized_;
};


#endif // JACK_AUDIO_H
