#include <stddef.h>
#include <string.h>

#include "FreeRTOS.h"

void* liquid_freertos_calloc(size_t nmemb, size_t size) {
  size_t total = nmemb * size;
  void* ptr = pvPortMalloc(total);
  if (ptr) {
    memset(ptr, 0, total);
  }
  return ptr;
}
