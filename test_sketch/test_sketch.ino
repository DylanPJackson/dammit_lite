#include <FastLED.h>

#define LED_PIN 5
#define COLOR_ORDER GRB
#define CHIPSET WS2811
#define NUM_LEDS 75
CRGB leds[NUM_LEDS];
#define maxOn 250
#define maxOff 50

void setup() {
  FastLED.addLeds<CHIPSET, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS);

}

void loop() {
  for(int i = 0; i < NUM_LEDS; i = i +1){
    leds[i]=CHSV(random8(),255,255);
    delay(maxOn);
    FastLED.show();
  }
  for(int i = 0; i < NUM_LEDS; i = i + 1){
    leds[i]=CRGB::Black;
    delay(maxOff);
    FastLED.show();
  }

}
