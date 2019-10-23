// Causes a single LED to be lit up at one time
// The LED changes between two colors, seizing in between, then
// jumps to the next LED
// Snakes back and forth 


#include <FastLED.h>

#define LED_PIN 5
#define COLOR_ORDER GRB
#define CHIPSET WS2811
#define NUM_LEDS 150
CRGB leds[NUM_LEDS];
#define seizureTime 25

void setup() {
  FastLED.addLeds<CHIPSET, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS);

}

void loop() {
  for(int i = 0; i < NUM_LEDS; i = i +1){
    leds[i]=CHSV(random8(),255,255);
    delay(seizureTime);
    FastLED.show();
    for(int i = 0; i < NUM_LEDS; i = i + 1){
    leds[i]=CRGB::Black;
  }
  delay(seizureTime);
  FastLED.show();
  }
  for(int i = NUM_LEDS; i >= 0; i = i - 1){
    leds[i]=CHSV(random8(),255,255);
    delay(seizureTime);       
    FastLED.show();
    for(int i = 0; i < NUM_LEDS; i = i + 1){
    leds[i]=CRGB::Black;
  }
  delay(seizureTime);
  FastLED.show();
  }
}
