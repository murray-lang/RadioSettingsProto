#include "thread/WaitCondition.h"

WaitCondition::WaitCondition()
    : m_waiters(0)
{
#if configSUPPORT_STATIC_ALLOCATION
    m_semaphore = xSemaphoreCreateCountingStatic(UINT32_MAX, 0, &m_buffer);
#else
    m_semaphore = xSemaphoreCreateCounting(UINT32_MAX, 0);
#endif
    configASSERT(m_semaphore != nullptr);
}

WaitCondition::~WaitCondition()
{
    if (m_semaphore != nullptr)
    {
        vSemaphoreDelete(m_semaphore);
    }
}

void WaitCondition::wakeOne()
{
    // Only signal if there are waiters
    if (m_waiters > 0)
    {
        xSemaphoreGive(m_semaphore);
    }
}

void WaitCondition::wakeAll()
{
    // Signal all waiters
    uint32_t waiters = m_waiters;
    for (uint32_t i = 0; i < waiters; i++)
    {
        xSemaphoreGive(m_semaphore);
    }
}

SemaphoreHandle_t WaitCondition::getSemaphoreHandle(Mutex* mutex)
{
    // Access the private m_handle member of Mutex (allowed via friend declaration)
    return mutex->m_handle;
}

void WaitCondition::wait(Mutex* mutex)
{
    // Increment waiter count
    m_waiters++;

    // Unlock the mutex
    mutex->unlock();

    // Wait on the semaphore (blocks until wakeOne() or wakeAll() is called)
    xSemaphoreTake(m_semaphore, portMAX_DELAY);

    // Decrement waiter count
    m_waiters--;

    // Re-lock the mutex before returning
    mutex->lock();
}

bool WaitCondition::waitFor(Mutex* mutex, uint32_t timeoutMs)
{
    // Increment waiter count
    m_waiters++;

    // Unlock the mutex
    mutex->unlock();

    // Wait on the semaphore with timeout
    BaseType_t result = xSemaphoreTake(m_semaphore, pdMS_TO_TICKS(timeoutMs));

    // Decrement waiter count
    m_waiters--;

    // Re-lock the mutex before returning
    mutex->lock();

    return result == pdTRUE;
}
