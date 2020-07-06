#define FASTLED_ALLOW_INTERRUPTS 0
#include <FastLED.h>

#define DATA_PIN  7
int brightness = 40;

#define NUM_LEDS_PER_STRIP 144
#define NUM_STRIPS 1
#define NUM_LEDS   NUM_LEDS_PER_STRIP
CRGB leds[NUM_LEDS_PER_STRIP * NUM_STRIPS];

void setup() {
  delay(1000);
  FastLED.addLeds<NUM_STRIPS, WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS_PER_STRIP); // Teensy parallel output mode
  FastLED.setBrightness(brightness);
  FastLED.setMaxPowerInVoltsAndMilliamps(5, 1500);
  fill_solid(leds, NUM_LEDS, CRGB::Black);
  FastLED.show();

}
void loop() {
  cd77_colorwipe_dot(CRGB::Green, 0, NUM_LEDS, 40);
}

void cd77_colorwipe_dot(CRGB color, uint16_t from,  uint16_t to,  uint16_t wait) {
  for (uint16_t i = from; i < to; i++) {
    leds[i] = color;
    FastLED.delay(wait);
    leds[i] = CRGB::Black;
    FastLED.show();
  }
}
