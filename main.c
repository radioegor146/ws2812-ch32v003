#include <ch32v00x.h>
#include <debug.h>
#include <memory.h>

#include "ws2812/ws2812.h"

#include "mcu_config.h"

/*
 *   ---------------
 *   | *           |
 * --| -      SWIO |--
 * --| GND    2812 |--
 * --| -         - |--
 * --| VCC       - |--
 *   |             |
 *   ---------------
 */

#define NUMBER_OF_LEDS 7

void InitGPIOPin(GPIO_TypeDef* gpio, uint16_t pin, GPIOSpeed_TypeDef speed,
                 GPIOMode_TypeDef mode) {
  GPIO_InitTypeDef init = {0};
  init.GPIO_Pin = pin;
  init.GPIO_Speed = speed;
  init.GPIO_Mode = mode;
  GPIO_Init(gpio, &init);
}

void InitWS2812() {
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
  InitGPIOPin(WS2812_PORT, WS2812_PIN, GPIO_Speed_50MHz, GPIO_Mode_Out_PP);
  GPIO_WriteBit(WS2812_PORT, WS2812_PIN, 0);
}

int main(void) {
  Delay_Init();
  InitWS2812();

  Color colors[NUMBER_OF_LEDS];

  while (1) {
    for (size_t i = 0; i < NUMBER_OF_LEDS; i++) {
      memset(colors, 0x00, sizeof(colors));
      colors[i].r = 0xFF;
      colors[(i + 1) % NUMBER_OF_LEDS].g = 0xF;
      colors[(i + 2) % NUMBER_OF_LEDS].b = 0xF;
      WriteWS2812(colors, NUMBER_OF_LEDS, WS2812_PORT, WS2812_PIN);
      Delay_Us(10000);
    }
  }
}
