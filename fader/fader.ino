// Three parameters which seem to affect the length and duration of the segments
// UPDATES_PER_SECOND (Smoothness) : Handles how often the frame is updated. Increase this to make fading more smooth. 
//    the effect has diminishing returns past about 1000 because then each refresh is less than a second. The lower this
//    goes the more choppy it seems
// startIndex (Speed) : Handles the speed at which the pattern traverses leds. Increase to make the sequence repeat faster. > 0 && < 1 does not work
// colorIndex (Length) : Handles the length of the segments. Increase this to lower the length of the segments. Set to 0 or 
//    comment it out to make all leds fade at once
//      Mess around with the palette itself to alter lengths as well

// This does not work how I expect it to. The issue is that it does what I want it to do but I feel like the way it is 
// doing it accomplishes something else. Evidently at each frame, the starting index is incremented by some value and then 
// each LED of leds is set to that index, which is incremented to a new index for each LED. What I feel like this pattern
// should accomplish is nothing at all, since the palette which the colors are indexed from is constant, and changing the 
// increment of that index doesn't actually change anything since the palette has length 16. Anyways, I mean I'm glad it
// does what I want it to do. I just don't understand how at the present time. 

#include <FastLED.h>
#define LED_PIN 7
#define COLOR_ORDER GRB
#define CHIPSET WS2811
#define NUM_LEDS 150
#define BRIGHTNESS 80

#define UPDATES_PER_SECOND 100

CRGB leds[NUM_LEDS];
CRGBPalette16 currentPalette;
TBlendType    currentBlending;

void setup() {
  delay(3000);
  FastLED.addLeds<CHIPSET, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);

  currentPalette = RainbowColors_p;
  currentBlending = LINEARBLEND;
}

void loop() {

    SetupColourtoColourPalette();
    
    static uint8_t startIndex = 0;
    startIndex = startIndex + 1; /* motion speed */
    
    FillLEDsFromPaletteColors( startIndex);
    
    FastLED.show();
    FastLED.delay(1000 / UPDATES_PER_SECOND);

}

void SetupBlackAndWhiteStripedPalette()
{
    // 'black out' all 16 palette entries...
    fill_solid( currentPalette, 16, CRGB::Black);
    // and set every fourth one to white.
    currentPalette[0] = CRGB::White;
    currentPalette[4] = CRGB::White;
    currentPalette[8] = CRGB::White;
    currentPalette[12] = CRGB::White;
    
}

void SetupColourtoColourPalette()
{
  CRGB purple = CHSV( HUE_PURPLE, 255, 255);
  CRGB green  = CHSV( HUE_GREEN, 255, 255);
  CRGB blue = CHSV( HUE_BLUE, 255, 255);
  CRGB pink = CHSV( HUE_PINK, 255, 255);
  CRGB colour1 = blue;
  CRGB colour2 = pink;
  CRGB black  = CRGB::Black;
  currentPalette = CRGBPalette16(
                                   colour1,  colour2,  colour1,  colour2,
                                   colour1,  colour2,  colour1,  colour2,
                                   colour1, colour2, colour1, colour2,
                                   colour1, colour2, colour1,  colour2 );
}

void FillLEDsFromPaletteColors( uint8_t colorIndex)
{
    uint8_t brightness = 255;
    
    for( int i = 0; i < NUM_LEDS; i++) {
        leds[i] = ColorFromPalette( currentPalette, colorIndex, brightness, currentBlending);
        colorIndex += 1; /* length of segments */
    }
}
