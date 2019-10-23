#include <FastLED.h>

#define LED_PIN     5
#define COLOR_ORDER GRB
#define CHIPSET     WS2811
#define NUM_LEDS    150
#define BRIGHTNESS  60

DEFINE_GRADIENT_PALETTE( heatmap_gp ){
    0,      0,   0,   0, // black
    128,  255,   0,   0, //red
    224,  255, 255,   0, // bright yellow
    255,  255, 255, 255 }; // full white
  CRGBPalette16 myPal = heatmap_gp;

CRGB leds[NUM_LEDS];

void setup() {
  delay(3000); // sanity delay
  FastLED.addLeds<CHIPSET, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS);
  FastLED.setBrightness( BRIGHTNESS );
}

void loop() {
  int color = 70;
  for(int i = 0; i < NUM_LEDS; i ++){
    uint8_t heatindex = (color);
    leds[i] = ColorFromPalette( myPal, heatindex);
    FastLED.show();
    //color ++;
  }


}
