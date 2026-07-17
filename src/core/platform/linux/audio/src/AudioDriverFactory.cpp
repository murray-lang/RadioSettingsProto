#include "audio/AudioDriverFactory.h"

#include <audio/AudioSink.h>
#include "audio/AudioInputDriver.h"
#include <regex>
#include "audio/RtAudioOutputDriverT.h"

ResultCode
AudioDriverFactory::createInputDriver(const Config::Audio::Fields& config, AudioSink* pSink,
                                      AudioInputDriver** ppDriver)
{
  const RtAudio::Api api = apiFromConfig(config);
  if (api == RtAudio::UNSPECIFIED) {
    return ResultCode::ERR_AUDIO_UNKNOWN_API;
  }
  RtAudio::DeviceInfo deviceInfo;
  ResultCode rc = findInputDevice(api, config.searchExpression, &deviceInfo);
  if (rc != ResultCode::OK) return rc;

  AudioDriverBase::Format format{};
  getInputFormat(config, deviceInfo, format);
  // format.channelCount = pConfig->getChannelCount();
  format.sampleFormat = AudioFormat::FLOAT32;
  format.bytesPerFrame = sizeof(float) * format.channelCount;
  *ppDriver = new AudioInputDriver(deviceInfo, format, pSink);
  return ResultCode::OK;
}

ResultCode
AudioDriverFactory::createOutputDriver(const Config::Audio::Fields& config, AudioOutputDriver** ppDriver)
{
  const RtAudio::Api api = apiFromConfig(config);
  RtAudio::DeviceInfo deviceInfo;
  ResultCode rc = findOutputDevice(api, config.searchExpression, &deviceInfo);
  if (rc != ResultCode::OK) return rc;
  AudioDriverBase::Format format{};
  getOutputFormat(config, deviceInfo, format);
  if (format.sampleFormat == AudioFormat::FLOAT32) {
    *ppDriver = new RtAudioOutputDriverT<float>(deviceInfo, format);
  }
  else if (format.sampleFormat == AudioFormat::SINT32 || format.sampleFormat == AudioFormat::SINT24) {
    *ppDriver = new RtAudioOutputDriverT<int32_t>(deviceInfo, format);
  }
  else if (format.sampleFormat == AudioFormat::SINT16) {
    *ppDriver = new RtAudioOutputDriverT<int16_t>(deviceInfo, format);
  }
  else if (format.sampleFormat == AudioFormat::SINT8) {
    *ppDriver = new RtAudioOutputDriverT<int8_t>(deviceInfo, format);
  }
  else {
    return ResultCode::ERR_AUDIO_UNKNOWN_FORMAT;
  }
  return ResultCode::OK;
}

RtAudio::Api AudioDriverFactory::apiFromConfig(const Config::Audio::Fields& config)
{
  return apiFromConfig(config.soundApi);
}

RtAudio::Api AudioDriverFactory::apiFromConfig(const Config::Audio::ShortString& configApi)
{
  if (configApi == "alsa") {
    return RtAudio::Api::LINUX_ALSA;
  }
  else if (configApi == "oss") {
    return RtAudio::Api::LINUX_OSS;
  }
  else if (configApi == "pulse") {
    return RtAudio::Api::LINUX_PULSE;
  }
  else if (configApi == "jack") {
    return RtAudio::Api::UNIX_JACK;
  }
  return RtAudio::Api::UNSPECIFIED;
}

ResultCode AudioDriverFactory::findInputDevice(
  RtAudio::Api api,
  const Config::Audio::LongString& searchExpression,
  RtAudio::DeviceInfo* pDeviceInfo
)
{
  RtAudio audio(api);
  auto deviceIds = audio.getDeviceIds();
  if (deviceIds.empty()) {
    return ResultCode::ERR_AUDIO_NO_INPUT_DEVICES;
  }
  for (auto& deviceId : deviceIds) {
    RtAudio::DeviceInfo info = audio.getDeviceInfo(deviceId);
    // Only consider devices with input channels
    if (info.inputChannels > 0) {
      InfoString name(info.name.c_str());
      // qDebug() << "Found input device: " << QString::fromStdString(name);
      size_t pos = name.find(searchExpression);
      if (pos != InfoString::npos) {
        *pDeviceInfo = info;
        return ResultCode::OK;
      }
    }
  }
  return ResultCode::ERR_AUDIO_NO_MATCHING_INPUT_DEVICE;
}

ResultCode AudioDriverFactory::findOutputDevice(
  RtAudio::Api api,
  const Config::Audio::LongString& searchExpression,
  RtAudio::DeviceInfo* pDeviceInfo
)
{
  RtAudio audio(api);
  auto deviceIds = audio.getDeviceIds();
  if (deviceIds.empty()) {
    return ResultCode::ERR_AUDIO_NO_OUTPUT_DEVICES;
  }
  for (auto& deviceId : deviceIds) {
    RtAudio::DeviceInfo info = audio.getDeviceInfo(deviceId);
    // Only consider devices with input channels
    if (info.outputChannels > 0) {
      InfoString name(info.name);
      size_t pos = name.find(searchExpression);
      if (pos != InfoString::npos) {
        *pDeviceInfo = info;
        return ResultCode::OK;
      }
    }
  }
  return ResultCode::ERR_AUDIO_NO_MATCHING_OUTPUT_DEVICE;
}

ResultCode AudioDriverFactory::findDefaultInputDevice(RtAudio::Api api, RtAudio::DeviceInfo* pDeviceInfo)
{
  RtAudio audio(api);
  auto deviceIds = audio.getDeviceIds();
  if (deviceIds.empty()) {
    return ResultCode::ERR_AUDIO_NO_INPUT_DEVICES;
  }
  for (auto& deviceId : deviceIds) {
    RtAudio::DeviceInfo info = audio.getDeviceInfo(deviceId);
    if (info.isDefaultInput) {
      *pDeviceInfo = info;
      return ResultCode::OK;
    }
  }
  return ResultCode::ERR_AUDIO_NO_DEFAULT_INPUT_DEVICE;
}

ResultCode AudioDriverFactory::findDefaultOutputDevice(RtAudio::Api api, RtAudio::DeviceInfo* pDeviceInfo)
{
  RtAudio audio(api);
  auto deviceIds = audio.getDeviceIds();
  if (deviceIds.empty()) {
    return ResultCode::ERR_AUDIO_NO_OUTPUT_DEVICES;
  }
  for (auto& deviceId : deviceIds) {
    RtAudio::DeviceInfo info = audio.getDeviceInfo(deviceId);
    if (info.isDefaultOutput) {
      *pDeviceInfo = info;
      return ResultCode::OK;
    }
  }
  return ResultCode::ERR_AUDIO_NO_DEFAULT_OUTPUT_DEVICE;
}

void AudioDriverFactory::getInputFormat(const Config::Audio::Fields& config, const RtAudio::DeviceInfo& deviceInfo,
                                        AudioDriverBase::Format& format)
{
  format.sampleFormat = static_cast<AudioFormat>(getRtAudioFormatFromConfigOrDefault(config, deviceInfo));
  if (config.sampleRate == 0) {
    format.sampleRate = deviceInfo.preferredSampleRate;
  }
  else {
    format.sampleRate = static_cast<int>(config.sampleRate);
  }
  if (config.channelCount == 0) {
    format.channelCount = deviceInfo.inputChannels;
  }
  else {
    format.channelCount = static_cast<int>(config.channelCount);
  }
  format.bytesPerFrame = getBytesPerChannel(format.sampleFormat) * format.channelCount;
}

void AudioDriverFactory::getOutputFormat(const Config::Audio::Fields& config, const RtAudio::DeviceInfo& deviceInfo,
                                         AudioDriverBase::Format& format)
{
  format.sampleFormat = static_cast<AudioFormat>(getRtAudioFormatFromConfigOrDefault(config, deviceInfo));
  if (config.sampleRate == 0) {
    format.sampleRate = deviceInfo.preferredSampleRate;
  }
  else {
    format.sampleRate = static_cast<int>(config.sampleRate);
  }
  if (config.channelCount == 0) {
    format.channelCount = deviceInfo.outputChannels;
  }
  else {
    format.channelCount = static_cast<int>(config.channelCount);
  }
  format.bytesPerFrame = getBytesPerChannel(format.sampleFormat) * format.channelCount;
}

uint32_t AudioDriverFactory::getBytesPerChannel(AudioFormat rtFormat)
{
  switch (rtFormat) {
  case AudioFormat::SINT8:
    return 1;
  case AudioFormat::SINT16:
    return 2;
  case AudioFormat::SINT24:
    return 3;
  case AudioFormat::SINT32:
  case AudioFormat::FLOAT32:
    return 4;
  case AudioFormat::FLOAT64:
    return 8;
  default:
    return 0;
  }
}

bool AudioDriverFactory::isRtAudioFormatSupported(RtAudioFormat format, const RtAudio::DeviceInfo& deviceInfo)
{
  return (deviceInfo.nativeFormats & format) != 0;
}

RtAudioFormat AudioDriverFactory::getDefaultRtAudioFormat(const RtAudio::DeviceInfo& deviceInfo)
{
  if (deviceInfo.nativeFormats & static_cast<RtAudioFormat>(AudioFormat::FLOAT32)) {
    return static_cast<RtAudioFormat>(AudioFormat::FLOAT32);
  }
  if (deviceInfo.nativeFormats & static_cast<RtAudioFormat>(AudioFormat::SINT32)) {
    return static_cast<RtAudioFormat>(AudioFormat::SINT32);
  }
  if (deviceInfo.nativeFormats & static_cast<RtAudioFormat>(AudioFormat::SINT24)) {
    return static_cast<RtAudioFormat>(AudioFormat::SINT24);
  }
  if (deviceInfo.nativeFormats & static_cast<RtAudioFormat>(AudioFormat::SINT16)) {
    return static_cast<RtAudioFormat>(AudioFormat::SINT16);
  }
  if (deviceInfo.nativeFormats & static_cast<RtAudioFormat>(AudioFormat::SINT8)) {
    return static_cast<RtAudioFormat>(AudioFormat::SINT8);
  }
  return 0;
}

RtAudioFormat AudioDriverFactory::getRtAudioFormatFromConfigOrDefault(const Config::Audio::Fields& config,
                                                                      const RtAudio::DeviceInfo& deviceInfo)
{
  RtAudioFormat format = getRtAudioFormatFromConfig(config);
  if (format == 0) {
    format = getDefaultRtAudioFormat(deviceInfo);
  } //else {
  // if (!isRtAudioFormatSupported(format, deviceInfo)) {
  //   std::ostringstream stringStream;
  //   stringStream << "The format '" << pConfig->getFormat() << "' is not supported by the device '" << deviceInfo.name << "'";
  //   std::string copyOfStr = stringStream.str();
  //   throw AudioException(copyOfStr);
  // }
  // }
  return format;
}

RtAudioFormat AudioDriverFactory::getRtAudioFormatFromConfig(const Config::Audio::Fields& config)
{
  return getRtAudioFormatFromConfig(config.format);
}

RtAudioFormat AudioDriverFactory::getRtAudioFormatFromConfig(const Config::Audio::ShortString& configFormat)
{
  if (configFormat == "float32") {
    return static_cast<RtAudioFormat>(AudioFormat::FLOAT32);
  }
  if (configFormat == "float64") {
    return static_cast<RtAudioFormat>(AudioFormat::FLOAT64);
  }
  if (configFormat == "sint8") {
    return static_cast<RtAudioFormat>(AudioFormat::SINT8);
  }
  if (configFormat == "sint16") {
    return static_cast<RtAudioFormat>(AudioFormat::SINT16);
  }
  if (configFormat == "sint24") {
    return static_cast<RtAudioFormat>(AudioFormat::SINT24);
  }
  if (configFormat == "sint32") {
    return static_cast<RtAudioFormat>(AudioFormat::SINT32);
  }
  return 0;
}
