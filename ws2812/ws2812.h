#ifndef WS2812_H_
#define WS2812_H_

#include <stdint.h>
#include <stddef.h>

typedef struct __attribute__((packed)) {
  uint8_t b;
  uint8_t r;
  uint8_t g;
  uint8_t _padding;
} Color;

void WriteWS2812(Color* colors, size_t size, void* port, uint32_t pin);

#endif  // WS2812_H_
