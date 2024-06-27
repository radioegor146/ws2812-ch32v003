# ws2812-ch32v003

Implementation of WS2812 protocol for WCH IC CH32V003

Works only with 48MHz clock

# Usage

To use, simply copy folder `ws2812` to your project and compile it

Example: 
```c
// Init array of leds
Color leds[12];

// Write WS2812 data to pin
WriteWS2812(leds, 12, WS2812_PORT, WS2812_PIN);
```

Also, example project is included in repo