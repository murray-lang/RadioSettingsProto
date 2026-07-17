#ifndef LINUX_AUDIO_DRIVER_FACTORY_H
#define LINUX_AUDIO_DRIVER_FACTORY_H

#include <ResultCode.h>
#include <config/struct/AudioConfig.h>
#include <audio/AudioSink.h>

#include "AudioInputDriver.h"
#include "AudioOutputDriver.h"

#ifdef USE_ETL
#include <etl/string.h>

using InfoString = etl::string<80>;
#else
using InfoString = std::string;
#endif

class AudioDriverFactory
{
  // static const RtAudio::Api defaultApi = RtAudio::Api::LINUX_ALSA;
public:
  static ResultCode createInputDriver(const Config::Audio::Fields& config, AudioSink* pSink, AudioInputDriver** ppDriver);
  static ResultCode createOutputDriver(const Config::Audio::Fields& config, AudioOutputDriver** ppDriver);
  static RtAudio::Api apiFromConfig(const Config::Audio::Fields& config);
  static RtAudio::Api apiFromConfig(const Config::Audio::ShortString& configApi);
  static ResultCode findInputDevice(
    RtAudio::Api api,
    const Config::Audio::LongString& searchExpression,
    RtAudio::DeviceInfo* pDeviceInfo
  );
  static ResultCode findOutputDevice(
    RtAudio::Api api,
    const Config::Audio::LongString& searchExpression,
    RtAudio::DeviceInfo* pDeviceInfo
    );
  static ResultCode findDefaultInputDevice(RtAudio::Api api, RtAudio::DeviceInfo* pDeviceInfo);
  static ResultCode findDefaultOutputDevice(RtAudio::Api api, RtAudio::DeviceInfo* pDeviceInfo);
  static void getInputFormat(
    const Config::Audio::Fields& config,
    const RtAudio::DeviceInfo& deviceInfo,
    AudioDriverBase::Format& format
    );
  static void getOutputFormat(
    const Config::Audio::Fields& config,
    const RtAudio::DeviceInfo& deviceInfo,
    AudioDriverBase::Format& format
    );
  static uint32_t getBytesPerChannel(AudioFormat rtFormat);
  static bool isRtAudioFormatSupported(RtAudioFormat format, const RtAudio::DeviceInfo& deviceInfo);
  static RtAudioFormat getDefaultRtAudioFormat(const RtAudio::DeviceInfo& deviceInfo);
  static RtAudioFormat getRtAudioFormatFromConfigOrDefault(
    const Config::Audio::Fields& config,
    const RtAudio::DeviceInfo& deviceInfo
    );
  static RtAudioFormat getRtAudioFormatFromConfig(const Config::Audio::Fields& config);
  static RtAudioFormat getRtAudioFormatFromConfig(const Config::Audio::ShortString& configFormat);
};

#endif // LINUX_AUDIO_DRIVER_FACTORY_H
