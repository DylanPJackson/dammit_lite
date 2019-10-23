#include <FastLED.h>

#define LED_PIN 7
#define COLOR_ORDER GRB
#define CHIPSET WS2811
#define NUM_LEDS 50
CRGB leds[NUM_LEDS];
#define maxOn 50
#define maxOff 50

void setup() {
  FastLED.addLeds<CHIPSET, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS);

}

void loop() {
  for(int i = 0; i < NUM_LEDS; i = i + 1){
    if(i <= .20 * NUM_LEDS){
      leds[i]=CRGB::Red;
      delay(maxOn);
      FastLED.show();
    } else if (i <= .40 * NUM_LEDS && i > .20 * NUM_LEDS){
      leds[i]=CRGB::Yellow;
      delay(maxOn);
      FastLED.show();
    } else if (i <= .60 * NUM_LEDS && i > .40 * NUM_LEDS){
      leds[i]=CRGB::Green;
      delay(maxOn);
      FastLED.show();
    } else if (i <= .80 * NUM_LEDS && i > .60 * NUM_LEDS){
      leds[i]=CRGB::Blue;
      delay(maxOn);
      FastLED.show();
    } else if (i <= NUM_LEDS && i > .80 * NUM_LEDS){
      leds[i]=CRGB::Purple;
      delay(maxOn);
      FastLED.show();
    }
  }
  for(int i = NUM_LEDS; i >= 0; i = i - 1){
      leds[i]=CHSV(random8(),255,255);
      delay(maxOn);
      FastLED.show();
    }
}
