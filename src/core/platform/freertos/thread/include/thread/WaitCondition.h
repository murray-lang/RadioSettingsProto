#pragma once

#include "Mutex.h"
#include "FreeRTOS.h"
#include "semphr.h"
#include <cstdint>

/**
 * @brief Cross-platform wait condition abstraction for FreeRTOS.
 * Similar to QWaitCondition - a signaling primitive that works with an external Mutex.
 * Used to avoid race conditions between checking a condition and waiting.
 */
class WaitCondition
{
public:
    /**
     * @brief Constructor.
     */
    WaitCondition();

    /**
     * @brief Destructor.
     */
    ~WaitCondition();

    // Delete copy operations
    WaitCondition(const WaitCondition&) = delete;
    WaitCondition& operator=(const WaitCondition&) = delete;

    // Delete move operations
    WaitCondition(WaitCondition&&) = delete;
    WaitCondition& operator=(WaitCondition&&) = delete;

    /**
     * @brief Wake one waiting thread.
     */
    void wakeOne();

    /**
     * @brief Wake all waiting threads.
     */
    void wakeAll();

    /**
     * @brief Wait on the wait condition.
     * Atomically unlocks the mutex and waits. Re-locks the mutex before returning.
     * Caller must hold the mutex locked when calling this.
     * @param mutex The mutex protecting the condition being waited on.
     */
    void wait(Mutex* mutex);

    /**
     * @brief Wait on the wait condition with a timeout.
     * Atomically unlocks the mutex and waits. Re-locks the mutex before returning.
     * @param mutex The mutex protecting the condition being waited on.
     * @param timeoutMs Timeout in milliseconds.
     * @return true if woken by signal, false if timeout occurred.
     */
    bool waitFor(Mutex* mutex, uint32_t timeoutMs);

private:
    friend class Mutex;
    SemaphoreHandle_t m_semaphore;
    volatile uint32_t m_waiters;

#if configSUPPORT_STATIC_ALLOCATION
    StaticSemaphore_t m_buffer;
#endif

    // Internal accessor for Mutex to expose SemaphoreHandle_t
    SemaphoreHandle_t getSemaphoreHandle(Mutex* mutex);
};
