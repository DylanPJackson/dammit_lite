#include <FastLED.h>

#define LED_PIN 7
#define COLOR_ORDER GRB
#define CHIPSET WS2811
#define NUM_LEDS 150
CRGB leds[NUM_LEDS];
#define seizureTime 25

void setup() {
  FastLED.addLeds<CHIPSET, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS);

}

void loop() {
  for(int i = 0; i < NUM_LEDS; i = i + 1){
    leds[i].setRGB(0, 34, 93);
    FastLED.show();
  }

}
