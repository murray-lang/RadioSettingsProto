#pragma once

#include <gpio/input/GpioInputLines.h>
#include <gpio/input/GpioInputLinesRequest.h>

#include <settings/model/SettingUpdate.h>
#include <config/struct/DigitalInputConfig.h>

#include <settings/model/SettingDescriptor.h>
#include <settings/model/SettingUpdateSource.h>

// #ifdef USE_DOTTED_STRING_PATHS
#include <settings/model/ResolveDottedStringFunc.h>
// #endif


#ifdef USE_ETL
#include "etl/string.h"
using IdString = etl::string<MAX_ID_LENGTH>;
#else
#include <string>

using IdString = std::string;
#endif

class DigitalInput : public GpioInputLines, public SettingUpdateSource
{
public:

  explicit DigitalInput();
  ~DigitalInput() override = default;

  // DigitalInput(DigitalInput& rhs)  noexcept;
  // DigitalInput& operator=(const DigitalInput& rhs)  noexcept;

  DigitalInput(DigitalInput&& rhs)  noexcept;
  DigitalInput& operator=(DigitalInput&& rhs)  noexcept;
  virtual ResultCode configure(const Config::DigitalInput::Fields& config, ResolveDottedStringFunc resolver);
  [[nodiscard]] const IdString& getId() const { return m_id; }
  [[nodiscard]] const SettingPath& getSettingPath() const { return m_settingDescriptor.getPath(); }

  GpioInputLinesRequest& getLinesRequest() { return m_linesRequest; }

  void connectSettingUpdateSink(SettingUpdateSink* sink) override;
protected:
  void handleGpioLineEvent(GpioLineEvent* event);

  ResultCode notifySettingUpdate(const SettingUpdate& settingDelta, bool final) override;

  IdString m_id;
  GpioLineEventCallback m_lineEventCallback;
  GpioInputLinesRequest m_linesRequest;
  SettingDescriptor m_settingDescriptor;
  unique_ptr<SettingUpdateSink> m_pSink;
};
