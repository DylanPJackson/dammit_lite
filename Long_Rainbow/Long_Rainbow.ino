#include <FastLED.h>

#define LED_PIN 7
#define COLOR_ORDER GRB
#define CHIPSET WS2811
#define NUM_LEDS 150
CRGB leds[NUM_LEDS];
#define maxOn 50
#define maxOff 50
#define brightness 32

void setup() {
  FastLED.addLeds<CHIPSET, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS);

}

void loop() {
  for(int i = 0; i < NUM_LEDS; i = i + 1){
    if(i <= 30){
      leds[i]=CRGB::Red;
      delay(maxOn);
      FastLED.setBrightness(brightness);
      FastLED.show();
    } else if (i <= 60 && i > 30){
      leds[i]=CRGB::Yellow;
      delay(maxOn);
      FastLED.setBrightness(brightness);
      FastLED.show();
    } else if (i <= 90 && i > 60){
      leds[i]=CRGB::Green;
      delay(maxOn);
      FastLED.setBrightness(brightness);
      FastLED.show();
    } else if (i <= 120 && i > 90){
      leds[i]=CRGB::Blue;
      delay(maxOn);
      FastLED.setBrightness(brightness);
      FastLED.show();
    } else if (i <= 150 && i > 120){
      leds[i]=CRGB::Purple;
      delay(maxOn);
      FastLED.setBrightness(brightness);
      FastLED.show();
    } 
  }
  for(int i = NUM_LEDS; i >= 0; i = i - 1){
    leds[i]=CRGB::Black;
    delay(maxOff);
    FastLED.setBrightness(brightness);
    FastLED.show();
  }
}
