#pragma once
#include <cstdint>

class Runnable
{
public:

  // struct ThreadRequirements
  // {
  //   uint32_t stackSize;
  //   uint32_t priority;
  //   bool shared;
  // };

  virtual ~Runnable() = default;

  // Default results for systems that don't need their own threads
  // [[nodiscard]] virtual const ThreadRequirements* getThreadRequirements() const { return nullptr; };

  virtual void run() {} // Not shared
  // virtual void quit() {} // Relevant only to run()
  // virtual bool tick() { return false; } // called when shared thread
};
