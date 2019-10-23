// Rainbow seizure simulator

#include <FastLED.h>

#define LED_PIN 7
#define COLOR_ORDER GRB
#define CHIPSET WS2811
#define NUM_LEDS 150
CRGB leds[NUM_LEDS];
#define seizureTime 25
#define BRIGHTNESS 20

void setup() {
  FastLED.addLeds<CHIPSET, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);
}

void loop() {
  for(int i = 0; i < NUM_LEDS; i = i + 1){
    leds[i]=CHSV(random8(),255,255);
  }
  delay(seizureTime);
  FastLED.show();
  for(int i = 0; i < NUM_LEDS; i = i + 1){
    leds[i]=CRGB::Black;
  }
  delay(seizureTime);
  FastLED.show();

}
