#include <FastLED.h>

#define LED_PIN 5
#define COLOR_ORDER GRB
#define CHIPSET WS2811
#define NUM_LEDS 50
CRGB leds[NUM_LEDS];
#define seizureTime 25

void setup() {
  FastLED.addLeds<CHIPSET, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS);

}

void loop() {
 for(int i = 0; i < NUM_LEDS; i = i + 1){
    leds[i].setRGB(255, 36, 0);
    FastLED.show();
  }
  for(int i = 0; i < NUM_LEDS; i = i + 1){
    if(i != 0){
      leds[i]=CRGB::Black;
      leds[i-1].setRGB(255, 36, 0);
      delay(seizureTime);
      FastLED.show();
    } else {
      leds[i]=CRGB::Black;
    delay(seizureTime);
    FastLED.show(); 
    }
  }
}
