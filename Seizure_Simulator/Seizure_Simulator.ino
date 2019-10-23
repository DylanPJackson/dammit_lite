//Seizure simulator
// Change seizureTime to alter the seizure intensity
// To change color, go to where setRGB is and change the three 
// rgb values there.

#include <FastLED.h>

#define LED_PIN 7
#define COLOR_ORDER GRB
#define CHIPSET WS2811
#define NUM_LEDS 150
CRGB leds[NUM_LEDS];
#define seizureTime 25
#define brightness 32

void setup() {
  FastLED.addLeds<CHIPSET, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS);
}

void loop() {
  CHSV randomFirst = CHSV(random8(), 255, 255);
  for(int i = 0; i < NUM_LEDS; i = i + 1){
    leds[i] = randomFirst;
  }
  delay(seizureTime);
  FastLED.setBrightness(brightness);
  FastLED.show();
  for(int i = 0; i < NUM_LEDS; i = i + 1){
    leds[i]=CRGB::Black;
  }
  delay(seizureTime);
   FastLED.setBrightness(brightness);
  FastLED.show();
}
