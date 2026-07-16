#pragma once

#include <cstdint>
#include <cstddef>
#include <ResultCode.h>
#include <thread/Runnable.h>

class UsbBase : public Runnable
{

public:
    UsbBase(uint16_t vendorId, uint16_t productId) : m_vendorId(vendorId), m_productId(productId) {}
    UsbBase(UsbBase&& rhs) = default;
    UsbBase& operator=(UsbBase&& rhs) = default;
    ~UsbBase() override = default;
    virtual ResultCode initialise() = 0;
    virtual bool discover() = 0;
    virtual ResultCode open() = 0;
    virtual void close() = 0;
    virtual void exit() = 0;

protected:
    uint16_t m_vendorId;
    uint16_t m_productId;
};

