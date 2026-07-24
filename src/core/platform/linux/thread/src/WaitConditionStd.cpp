#include "thread/WaitCondition.h"
#include <chrono>

void WaitCondition::wakeOne()
{
    m_cv.notify_one();
}

void WaitCondition::wakeAll()
{
    m_cv.notify_all();
}

std::mutex& WaitCondition::getStdMutex(Mutex* mutex)
{
    // Access the private m_mutex member of Mutex (allowed via friend declaration)
    return mutex->m_mutex;
}

void WaitCondition::wait(Mutex* mutex)
{
    // Create a unique_lock adopting the already-locked mutex
    std::unique_lock<std::mutex> lock(getStdMutex(mutex), std::adopt_lock);

    // Wait (this unlocks the mutex atomically and re-locks when woken)
    m_cv.wait(lock);

    // Release the lock without unlocking (caller expects mutex to still be locked)
    lock.release();
}

bool WaitCondition::waitFor(Mutex* mutex, uint32_t timeoutMs)
{
    // Create a unique_lock adopting the already-locked mutex
    std::unique_lock<std::mutex> lock(getStdMutex(mutex), std::adopt_lock);

    // Wait with timeout
    bool result = m_cv.wait_for(lock, std::chrono::milliseconds(timeoutMs))
                  == std::cv_status::no_timeout;

    // Release the lock without unlocking (caller expects mutex to still be locked)
    lock.release();

    return result;
}
