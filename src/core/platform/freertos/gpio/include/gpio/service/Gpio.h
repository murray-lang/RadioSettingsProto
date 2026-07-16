#ifndef FREERTOS_GPIO_H_
#define FREERTOS_GPIO_H_

#include <gpio/input/GpioInputLinesRequest.h>
#include <gpio/output/GpioOutputLinesRequest.h>

#include <gpio/service/GpioInputLinesSource.h>
#include <gpio/service/GpioOutputLinesSource.h>
#include <thread/Runnable.h>
#include <ResultCode.h>


using GpioConsumerString = etl::string<MAX_GPIO_CONTEXT_LENGTH>;

class Gpio
{
public:
  Gpio() = default;
  ~Gpio() = default;

  static Gpio& getInstance() {
    static Gpio instance; // Only created once, thread-safe since C++11
    return instance;
  }

  // Delete copy and move operations
  Gpio(const Gpio&) = delete;
  Gpio& operator=(const Gpio&) = delete;
  Gpio(Gpio&&) = delete;
  Gpio& operator=(Gpio&&) = delete;

  static bool isPresent() { return true;};
  ResultCode open() { return ResultCode::OK; }
  void close() {}

  ResultCode startInputs();
  void stopInputs();

  // [[nodiscard]] const ThreadRequirements* getThreadRequirements() const override
  // {
  //   return m_inputLinesSource.getThreadRequirements();
  // }
  //
  // void run() override { m_inputLinesSource.run(); }
  // void quit() override { m_inputLinesSource.quit(); }
  // bool tick() override { return m_inputLinesSource.tick(); }

  ResultCode requestInputs(const char * contextId, GpioInputLinesRequestVector& requests);
  ResultCode requestOutputs(const char * contextId, GpioOutputLinesRequest* requests);

  // GpioInputLinesSource& getInputLinesSource() { return m_inputLinesSource; }
  // GpioOutputLinesSource& getOutputLinesSource() { return m_outputLinesSource; }
  void handlePinTransition(GpioLineMask mask, uint32_t timestamp)
  {
    m_inputLinesSource.handlePinTransition(mask, timestamp);
  }

private:
  GpioInputLinesSource m_inputLinesSource;
  GpioOutputLinesSource m_outputLinesSource;


};

#endif // FREERTOS_GPIO_H_