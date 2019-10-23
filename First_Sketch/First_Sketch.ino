#include <FastLED.h>

#define LED_PIN 5
#define COLOR_ORDER GRB
#define CHIPSET WS2811
#define NUM_LEDS 30
CRGB leds[NUM_LEDS];
#define maxTime 250

void setup() {
  FastLED.addLeds<CHIPSET, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS);

}

void loop() {
  leds[0] = CRGB::Red; 
  FastLED.show(); 
  delay(maxTime);
  leds[1] = CRGB(255,140,0);
  FastLED.show();
  delay(maxTime);
  leds[2] = CRGB::Yellow;
  FastLED.show();
  delay(maxTime);
  leds[3] = CRGB::Green;
  FastLED.show();
  delay(maxTime);
  leds[4] = CRGB::Blue;
  FastLED.show();
  delay(maxTime);
  leds[5] = CRGB::Purple;
  FastLED.show();
  delay(maxTime);
  leds[0] = CRGB::Black; 
  FastLED.show(); 
  delay(maxTime);
  leds[1] = CRGB::Black;
  FastLED.show();
  delay(maxTime);
  leds[2] = CRGB::Black;
  FastLED.show();
  delay(maxTime);
  leds[3] = CRGB::Black;
  FastLED.show();
  delay(maxTime);
  leds[4] = CRGB::Black;
  FastLED.show();
  delay(maxTime);
  leds[5] = CRGB::Black;
  FastLED.show();
  delay(maxTime);
}
