#pragma once

#include <vector>
#include <string>
#include <memory>
#include <mmdeviceapi.h>
#include <audioclient.h>
#include <functiondiscoverykeys_devpkey.h>
#include <comdef.h>

// Link required libraries
#pragma comment(lib, "ole32.lib")

// Base selection interface
class CSelectionInterface
{
public:
    virtual ~CSelectionInterface() {}
    virtual void Enumerate(std::vector<std::string>& names, std::vector<std::string>& descriptions, std::string& defaultDevice) = 0;
    virtual std::string GetDev() = 0;
    virtual void SetDev(std::string sNewDev) = 0;
};

// Sound input interface
class CSoundInInterface : public CSelectionInterface
{
public:
    virtual ~CSoundInInterface() {}
    virtual bool Init(int iSampleRate, size_t iNewBufferSize) = 0;
    virtual bool Read(std::vector<uint16_t>& data) = 0;
    virtual void Close() = 0;
    virtual std::string GetVersion() = 0;
};

// Sound output interface
class CSoundOutInterface : public CSelectionInterface
{
public:
    virtual ~CSoundOutInterface() {}
    virtual bool Init(int sampleRate, size_t bufferSize) = 0;
    virtual bool Write(std::vector<uint16_t>& data) = 0;
    virtual void Close() = 0;
    virtual std::string GetVersion() = 0;
};

// Helper function to convert wide string to UTF-8
inline std::string WideToUtf8(const wchar_t* wstr)
{
    if (!wstr) return "";
    int size = WideCharToMultiByte(CP_UTF8, 0, wstr, -1, nullptr, 0, nullptr, nullptr);
    if (size <= 0) return "";
    std::vector<char> buffer(size);
    WideCharToMultiByte(CP_UTF8, 0, wstr, -1, buffer.data(), size, nullptr, nullptr);
    return std::string(buffer.data());
}

// WASAPI Sound Input Implementation
class CWASAPISoundIn : public CSoundInInterface
{
private:
    IMMDeviceEnumerator* pEnumerator;
    IMMDevice* pDevice;
    IAudioClient* pAudioClient;
    IAudioCaptureClient* pCaptureClient;
    WAVEFORMATEX* pWaveFormat;
    
    std::string currentDevice;
    int sampleRate;
    size_t bufferSize;
    UINT32 bufferFrameCount;
    bool initialized;

    void Cleanup()
    {
        if (pCaptureClient) {
            pCaptureClient->Release();
            pCaptureClient = nullptr;
        }
        if (pAudioClient) {
            pAudioClient->Stop();
            pAudioClient->Release();
            pAudioClient = nullptr;
        }
        if (pWaveFormat) {
            CoTaskMemFree(pWaveFormat);
            pWaveFormat = nullptr;
        }
        if (pDevice) {
            pDevice->Release();
            pDevice = nullptr;
        }
        initialized = false;
    }

public:
    CWASAPISoundIn() : pEnumerator(nullptr), pDevice(nullptr), pAudioClient(nullptr),
                       pCaptureClient(nullptr), pWaveFormat(nullptr),
                       sampleRate(0), bufferSize(0), bufferFrameCount(0), initialized(false)
    {
        CoInitializeEx(nullptr, COINIT_MULTITHREADED);
        HRESULT hr = CoCreateInstance(__uuidof(MMDeviceEnumerator), nullptr,
                                     CLSCTX_ALL, __uuidof(IMMDeviceEnumerator),
                                     (void**)&pEnumerator);
    }

    virtual ~CWASAPISoundIn()
    {
        Close();
        if (pEnumerator) {
            pEnumerator->Release();
        }
        CoUninitialize();
    }

    void Enumerate(std::vector<std::string>& names, std::vector<std::string>& descriptions, std::string& defaultDevice) override
    {
        names.clear();
        descriptions.clear();
        defaultDevice.clear();

        if (!pEnumerator) return;

        // Get default device
        IMMDevice* pDefaultDevice = nullptr;
        if (SUCCEEDED(pEnumerator->GetDefaultAudioEndpoint(eCapture, eConsole, &pDefaultDevice))) {
            LPWSTR pwszID = nullptr;
            if (SUCCEEDED(pDefaultDevice->GetId(&pwszID))) {
                defaultDevice = WideToUtf8(pwszID);
                CoTaskMemFree(pwszID);
            }
            pDefaultDevice->Release();
        }

        // Enumerate all capture devices
        IMMDeviceCollection* pCollection = nullptr;
        if (FAILED(pEnumerator->EnumAudioEndpoints(eCapture, DEVICE_STATE_ACTIVE, &pCollection))) {
            return;
        }

        UINT count = 0;
        pCollection->GetCount(&count);

        for (UINT i = 0; i < count; i++) {
            IMMDevice* pEndpoint = nullptr;
            if (SUCCEEDED(pCollection->Item(i, &pEndpoint))) {
                LPWSTR pwszID = nullptr;
                if (SUCCEEDED(pEndpoint->GetId(&pwszID))) {
                    names.push_back(WideToUtf8(pwszID));
                    CoTaskMemFree(pwszID);
                }

                IPropertyStore* pProps = nullptr;
                if (SUCCEEDED(pEndpoint->OpenPropertyStore(STGM_READ, &pProps))) {
                    PROPVARIANT varName;
                    PropVariantInit(&varName);
                    if (SUCCEEDED(pProps->GetValue(PKEY_Device_FriendlyName, &varName))) {
                        descriptions.push_back(WideToUtf8(varName.pwszVal));
                        PropVariantClear(&varName);
                    }
                    pProps->Release();
                }
                pEndpoint->Release();
            }
        }
        pCollection->Release();
    }

    std::string GetDev() override
    {
        return currentDevice;
    }

    void SetDev(std::string sNewDev) override
    {
        if (initialized) {
            Close();
        }
        currentDevice = sNewDev;
    }

    bool Init(int iSampleRate, size_t iNewBufferSize) override
    {
        if (initialized) {
            Close();
        }

        sampleRate = iSampleRate;
        bufferSize = iNewBufferSize;

        if (!pEnumerator) return false;

        // Get the device
        if (currentDevice.empty()) {
            // Use default device
            if (FAILED(pEnumerator->GetDefaultAudioEndpoint(eCapture, eConsole, &pDevice))) {
                return false;
            }
        } else {
            // Use specified device
            int size = MultiByteToWideChar(CP_UTF8, 0, currentDevice.c_str(), -1, nullptr, 0);
            std::vector<wchar_t> wdevice(size);
            MultiByteToWideChar(CP_UTF8, 0, currentDevice.c_str(), -1, wdevice.data(), size);
            if (FAILED(pEnumerator->GetDevice(wdevice.data(), &pDevice))) {
                return false;
            }
        }

        // Activate audio client
        if (FAILED(pDevice->Activate(__uuidof(IAudioClient), CLSCTX_ALL, nullptr, (void**)&pAudioClient))) {
            Cleanup();
            return false;
        }

        // Get the device format
        if (FAILED(pAudioClient->GetMixFormat(&pWaveFormat))) {
            Cleanup();
            return false;
        }

        // Set our desired format (16-bit stereo PCM)
        pWaveFormat->wFormatTag = WAVE_FORMAT_PCM;
        pWaveFormat->nChannels = 2;
        pWaveFormat->nSamplesPerSec = sampleRate;
        pWaveFormat->wBitsPerSample = 16;
        pWaveFormat->nBlockAlign = (pWaveFormat->nChannels * pWaveFormat->wBitsPerSample) / 8;
        pWaveFormat->nAvgBytesPerSec = pWaveFormat->nSamplesPerSec * pWaveFormat->nBlockAlign;
        pWaveFormat->cbSize = 0;

        // Calculate buffer duration (in 100-nanosecond units)
        REFERENCE_TIME requestedDuration = (REFERENCE_TIME)((double)bufferSize * 10000000.0 / (double)sampleRate);

        // Initialize audio client in shared mode
        if (FAILED(pAudioClient->Initialize(AUDCLNT_SHAREMODE_SHARED, 0, requestedDuration, 0, pWaveFormat, nullptr))) {
            Cleanup();
            return false;
        }

        // Get the actual buffer size
        if (FAILED(pAudioClient->GetBufferSize(&bufferFrameCount))) {
            Cleanup();
            return false;
        }

        // Get the capture client
        if (FAILED(pAudioClient->GetService(__uuidof(IAudioCaptureClient), (void**)&pCaptureClient))) {
            Cleanup();
            return false;
        }

        // Start capturing
        if (FAILED(pAudioClient->Start())) {
            Cleanup();
            return false;
        }

        initialized = true;
        return true;
    }

    bool Read(std::vector<uint16_t>& data) override
    {
        if (!initialized) return false;

        data.clear();
        size_t samplesNeeded = bufferSize * 2; // stereo
        data.reserve(samplesNeeded);

        while (data.size() < samplesNeeded) {
            UINT32 packetLength = 0;
            if (FAILED(pCaptureClient->GetNextPacketSize(&packetLength))) {
                return false;
            }

            if (packetLength == 0) {
                // No data available, sleep briefly
                Sleep(1);
                continue;
            }

            BYTE* pData = nullptr;
            UINT32 numFramesAvailable = 0;
            DWORD flags = 0;

            HRESULT hr = pCaptureClient->GetBuffer(&pData, &numFramesAvailable, &flags, nullptr, nullptr);
            if (FAILED(hr)) {
                return false;
            }

            if (flags & AUDCLNT_BUFFERFLAGS_SILENT) {
                // Silent buffer, fill with zeros
                data.insert(data.end(), numFramesAvailable * 2, 0);
            } else {
                // Copy the data
                int16_t* pSamples = (int16_t*)pData;
                size_t samplesToCopy = numFramesAvailable * 2; // stereo
                data.insert(data.end(), pSamples, pSamples + samplesToCopy);
            }

            pCaptureClient->ReleaseBuffer(numFramesAvailable);
        }

        // Trim to exact size if we got more than needed
        if (data.size() > samplesNeeded) {
            data.resize(samplesNeeded);
        }

        return true;
    }

    void Close() override
    {
        Cleanup();
    }

    std::string GetVersion() override
    {
        return "WASAPI 1.0";
    }
};

// WASAPI Sound Output Implementation
class CWASAPISoundOut : public CSoundOutInterface
{
private:
    IMMDeviceEnumerator* pEnumerator;
    IMMDevice* pDevice;
    IAudioClient* pAudioClient;
    IAudioRenderClient* pRenderClient;
    WAVEFORMATEX* pWaveFormat;
    
    std::string currentDevice;
    int sampleRate;
    size_t bufferSize;
    UINT32 bufferFrameCount;
    bool initialized;

    void Cleanup()
    {
        if (pRenderClient) {
            pRenderClient->Release();
            pRenderClient = nullptr;
        }
        if (pAudioClient) {
            pAudioClient->Stop();
            pAudioClient->Release();
            pAudioClient = nullptr;
        }
        if (pWaveFormat) {
            CoTaskMemFree(pWaveFormat);
            pWaveFormat = nullptr;
        }
        if (pDevice) {
            pDevice->Release();
            pDevice = nullptr;
        }
        initialized = false;
    }

public:
    CWASAPISoundOut() : pEnumerator(nullptr), pDevice(nullptr), pAudioClient(nullptr),
                        pRenderClient(nullptr), pWaveFormat(nullptr),
                        sampleRate(0), bufferSize(0), bufferFrameCount(0), initialized(false)
    {
        CoInitializeEx(nullptr, COINIT_MULTITHREADED);
        HRESULT hr = CoCreateInstance(__uuidof(MMDeviceEnumerator), nullptr,
                                     CLSCTX_ALL, __uuidof(IMMDeviceEnumerator),
                                     (void**)&pEnumerator);
    }

    virtual ~CWASAPISoundOut()
    {
        Close();
        if (pEnumerator) {
            pEnumerator->Release();
        }
        CoUninitialize();
    }

    void Enumerate(std::vector<std::string>& names, std::vector<std::string>& descriptions, std::string& defaultDevice) override
    {
        names.clear();
        descriptions.clear();
        defaultDevice.clear();

        if (!pEnumerator) return;

        // Get default device
        IMMDevice* pDefaultDevice = nullptr;
        if (SUCCEEDED(pEnumerator->GetDefaultAudioEndpoint(eRender, eConsole, &pDefaultDevice))) {
            LPWSTR pwszID = nullptr;
            if (SUCCEEDED(pDefaultDevice->GetId(&pwszID))) {
                defaultDevice = WideToUtf8(pwszID);
                CoTaskMemFree(pwszID);
            }
            pDefaultDevice->Release();
        }

        // Enumerate all render devices
        IMMDeviceCollection* pCollection = nullptr;
        if (FAILED(pEnumerator->EnumAudioEndpoints(eRender, DEVICE_STATE_ACTIVE, &pCollection))) {
            return;
        }

        UINT count = 0;
        pCollection->GetCount(&count);

        for (UINT i = 0; i < count; i++) {
            IMMDevice* pEndpoint = nullptr;
            if (SUCCEEDED(pCollection->Item(i, &pEndpoint))) {
                LPWSTR pwszID = nullptr;
                if (SUCCEEDED(pEndpoint->GetId(&pwszID))) {
                    names.push_back(WideToUtf8(pwszID));
                    CoTaskMemFree(pwszID);
                }

                IPropertyStore* pProps = nullptr;
                if (SUCCEEDED(pEndpoint->OpenPropertyStore(STGM_READ, &pProps))) {
                    PROPVARIANT varName;
                    PropVariantInit(&varName);
                    if (SUCCEEDED(pProps->GetValue(PKEY_Device_FriendlyName, &varName))) {
                        descriptions.push_back(WideToUtf8(varName.pwszVal));
                        PropVariantClear(&varName);
                    }
                    pProps->Release();
                }
                pEndpoint->Release();
            }
        }
        pCollection->Release();
    }

    std::string GetDev() override
    {
        return currentDevice;
    }

    void SetDev(std::string sNewDev) override
    {
        if (initialized) {
            Close();
        }
        currentDevice = sNewDev;
    }

    bool Init(int iSampleRate, size_t iNewBufferSize) override
    {
        if (initialized) {
            Close();
        }

        sampleRate = iSampleRate;
        bufferSize = iNewBufferSize;

        if (!pEnumerator) return false;

        // Get the device
        if (currentDevice.empty()) {
            // Use default device
            if (FAILED(pEnumerator->GetDefaultAudioEndpoint(eRender, eConsole, &pDevice))) {
                return false;
            }
        } else {
            // Use specified device
            int size = MultiByteToWideChar(CP_UTF8, 0, currentDevice.c_str(), -1, nullptr, 0);
            std::vector<wchar_t> wdevice(size);
            MultiByteToWideChar(CP_UTF8, 0, currentDevice.c_str(), -1, wdevice.data(), size);
            if (FAILED(pEnumerator->GetDevice(wdevice.data(), &pDevice))) {
                return false;
            }
        }

        // Activate audio client
        if (FAILED(pDevice->Activate(__uuidof(IAudioClient), CLSCTX_ALL, nullptr, (void**)&pAudioClient))) {
            Cleanup();
            return false;
        }

        // Get the device format
        if (FAILED(pAudioClient->GetMixFormat(&pWaveFormat))) {
            Cleanup();
            return false;
        }

        // Set our desired format (16-bit stereo PCM)
        pWaveFormat->wFormatTag = WAVE_FORMAT_PCM;
        pWaveFormat->nChannels = 2;
        pWaveFormat->nSamplesPerSec = sampleRate;
        pWaveFormat->wBitsPerSample = 16;
        pWaveFormat->nBlockAlign = (pWaveFormat->nChannels * pWaveFormat->wBitsPerSample) / 8;
        pWaveFormat->nAvgBytesPerSec = pWaveFormat->nSamplesPerSec * pWaveFormat->nBlockAlign;
        pWaveFormat->cbSize = 0;

        // Calculate buffer duration (in 100-nanosecond units)
        REFERENCE_TIME requestedDuration = (REFERENCE_TIME)((double)bufferSize * 10000000.0 / (double)sampleRate);

        // Initialize audio client in shared mode
        if (FAILED(pAudioClient->Initialize(AUDCLNT_SHAREMODE_SHARED, 0, requestedDuration, 0, pWaveFormat, nullptr))) {
            Cleanup();
            return false;
        }

        // Get the actual buffer size
        if (FAILED(pAudioClient->GetBufferSize(&bufferFrameCount))) {
            Cleanup();
            return false;
        }

        // Get the render client
        if (FAILED(pAudioClient->GetService(__uuidof(IAudioRenderClient), (void**)&pRenderClient))) {
            Cleanup();
            return false;
        }

        // Start playback
        if (FAILED(pAudioClient->Start())) {
            Cleanup();
            return false;
        }

        initialized = true;
        return true;
    }

    bool Write(std::vector<uint16_t>& data) override
    {
        if (!initialized) return false;

        size_t totalFrames = data.size() / 2; // stereo
        size_t framesWritten = 0;

        while (framesWritten < totalFrames) {
            // Get available buffer space
            UINT32 numFramesPadding = 0;
            if (FAILED(pAudioClient->GetCurrentPadding(&numFramesPadding))) {
                return false;
            }

            UINT32 numFramesAvailable = bufferFrameCount - numFramesPadding;
            
            if (numFramesAvailable == 0) {
                // Buffer is full, wait briefly
                Sleep(1);
                continue;
            }

            // Don't write more than we have
            UINT32 framesToWrite = (UINT32)min((size_t)numFramesAvailable, totalFrames - framesWritten);

            BYTE* pData = nullptr;
            HRESULT hr = pRenderClient->GetBuffer(framesToWrite, &pData);
            if (FAILED(hr)) {
                return false;
            }

            // Copy data
            memcpy(pData, &data[framesWritten * 2], framesToWrite * 2 * sizeof(uint16_t));

            if (FAILED(pRenderClient->ReleaseBuffer(framesToWrite, 0))) {
                return false;
            }

            framesWritten += framesToWrite;
        }

        return true;
    }

    void Close() override
    {
        Cleanup();
    }

    std::string GetVersion() override
    {
        return "WASAPI 1.0";
    }
};
