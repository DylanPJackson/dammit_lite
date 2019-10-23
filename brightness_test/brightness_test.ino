//Testing brightness adjustments
// Going down to 4 is really about as low as you want to fucking go
// Was originally just a test of brightness. Then I implemented the
// darkness bug. Then I realised you could turn the black to a color,
// so I'm trying to see
// 64 per 150 max (6666FF) blue
//

#include <FastLED.h>
#include <stdlib.h>
#define LED_PIN 7
#define COLOR_ORDER GRB
#define CHIPSET WS2811
#define NUM_LEDS 150
CRGB leds[NUM_LEDS];
#define seizureTime 135
#define brightness 80
#define bugBrightness 255
#define seizureTimeTest 1000


void setup() {
  FastLED.addLeds<CHIPSET, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS);
}

void loop() {
  CHSV randomSecond = CHSV(random16(), 255, 255);
  CHSV randomFirst = CHSV(random8(), 255, 255);
  int trails[5][3] = {{50, 100, 250}, {250, 0, 10}, {100, 200, 150}, {200, 50, 100}, {150, 150, 200}};
  for (int i = 0; i < NUM_LEDS; i = i + 1) {
    if (i != 0) {
      leds[i].setRGB(trails[i%5][0],trails[i%5][1],trails[i%5][2]);
      leds[i] = CRGB::Black;
      leds[i+1].setRGB(trails[i%5][0],trails[i%5][1],trails[i%5][2]);
      leds[i+1]=CRGB::Black;
      leds[i+2].setRGB(trails[i%5][0],trails[i%5][1],trails[i%5][2]);
      leds[i+2]=CRGB::Black;
      leds[i - 3] = randomFirst;
      delay(seizureTime);
      FastLED.setBrightness(brightness);
      FastLED.show();
    } else {
      leds[i].setRGB(trails[i % 5][0], trails[i % 5][1], trails[i % 5][2]);
      delay(seizureTime);
      FastLED.setBrightness(brightness);
      FastLED.show();
    }
  }
  for (int i = NUM_LEDS; i >= 0; i = i - 1) {
    leds[i-1].setRGB(trails[i%5][0],trails[i%5][1],trails[i%5][2]);
    leds[i - 1] = CRGB::Black;
    leds[i-2].setRGB(trails[i%5][0],trails[i%5][1],trails[i%5][2]);
    leds[i - 2] = CRGB::Black;
    leds[i-3].setRGB(trails[i%5][0],trails[i%5][1],trails[i%5][2]);
    leds[i - 3] = CRGB::Black;
    leds[i] = randomSecond;
    delay(seizureTime);
    FastLED.show();
  }

}
