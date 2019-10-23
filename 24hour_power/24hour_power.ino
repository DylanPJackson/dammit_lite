// Currently only on small scale, but the principle and method of execution are done
// The following description can be adapted to whatever time length and number of colors desired. 
// Just need to have a high enough IQ. 

// The animation starts off at all black, then fades into black and blue. Then the black
// changes into another color. Then the blue changes to another color. This can easily be adapted
// to a 24 color scheme. 
// The trick of the whole thing is to first make it so that it can start smoothly from all black,
// add in just one color, but when you loop back around the time with modulo, you don't need to 
// go back to that original color with black. It is instead the last added color with the first color

// Mess with UPDATES_PER_SECOND to define how smooth/blocky the animation is
// Mess with startIndex to define how fast the animation moves
// Mess with colorIndex to define the length of each segment of the animation
// Mess with currentTime to determine how long it takes to loop through all the colors

#include <FastLED.h>
#define LED_PIN 7
#define COLOR_ORDER GRB
#define CHIPSET WS2811
#define NUM_LEDS 150
#define BRIGHTNESS 220

#define UPDATES_PER_SECOND 20
#define INTERVAL 100

boolean firstTime;
CRGB leds[NUM_LEDS];
CRGBPalette16 currentPalette;
CRGBPalette16 targetPalette;
TBlendType    currentBlending;

// The color for each hour of the day 
CRGB black;
CRGB zero;
CRGB one;
CRGB two;
CRGB three; 
CRGB four;
CRGB five;
CRGB six;
CRGB seven;
CRGB eight;
CRGB nine;
CRGB ten;
CRGB eleven;
CRGB twelve;
CRGB thirteen;
CRGB fourteen;
CRGB fifteen;
CRGB sixteen;
CRGB seventeen;
CRGB eighteen;
CRGB nineteen;
CRGB twenty;
CRGB twentyone;
CRGB twentytwo;
CRGB twentythree;

void setup() {
  delay(3000);
  FastLED.addLeds<CHIPSET, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.setBrightness(BRIGHTNESS);
  black = 0x000000;
  //CRGB yellow = 0xffff00;
  //CRGB purple = 0x461B7E;
  //CRGB blue = 0x0000ff;
  //CRGB balanceBrown = 0xb27644;
  //CRGB balanceRed = 0xbd2b2b;
  setHourColours();
  CRGB redd = 0x8B0000;
  setCurrentPalette(black, black);
  setTargetPalette(black, redd);
  currentBlending = LINEARBLEND;
  firstTime = true;
}

void loop() {

    setUpMarissa();

    uint8_t maxChanges = 24;
    nblendPaletteTowardPalette( currentPalette, targetPalette, maxChanges);
    
    static uint8_t startIndex = 0;
    startIndex = startIndex + 1; /* motion speed */
    
    FillLEDsFromPaletteColors( startIndex);
    
    FastLED.show();
    FastLED.delay(1000 / UPDATES_PER_SECOND);

}

void FillLEDsFromPaletteColors( uint8_t colorIndex)
{
    uint8_t brightness = BRIGHTNESS;
    
    for( int i = 0; i < NUM_LEDS; i++) {
        leds[i] = ColorFromPalette( currentPalette, colorIndex, brightness, currentBlending);
        colorIndex += 2; /* length of segments */
    }
}

void SetupPalettetoPalette()
{
  unsigned long currentTime = (millis() / 10000) % 86400;
  // Check ensures that the first time through passes and then fades correctly for future
    if(currentTime == 82800){
    setTargetPalette(black, twentythree);
  } else if(currentTime == 79200){
    setTargetPalette(black, twentytwo);
  } else if(currentTime == 75600){
    setTargetPalette(black, twentyone);
  } else if(currentTime == 72000){
    setTargetPalette(black, twenty);
  } else if(currentTime == 68400){
    setTargetPalette(black, nineteen);
  } else if(currentTime == 64800){
    setTargetPalette(black, eighteen);
  } else if(currentTime == 61200){
    setTargetPalette(black, seventeen);
  } else if(currentTime == 57600){
    setTargetPalette(black, sixteen);
  } else if(currentTime == 54000){
    setTargetPalette(black, fifteen);
  } else if(currentTime == 50400){
    setTargetPalette(black, fourteen);
  } else if(currentTime == 46800){
    setTargetPalette(black, thirteen);
  } else if(currentTime == 43200){
    setTargetPalette(black, twelve);
  } else if(currentTime == 39600){
    setTargetPalette(black, eleven);
  } else if(currentTime == 36000){
    setTargetPalette(black, ten);
  } else if(currentTime == 32400){
    setTargetPalette(black, nine);
  } else if(currentTime == 28800){
    setTargetPalette(black, eight);
  } else if(currentTime == 25200){
    setTargetPalette(black, seven);
  } else if(currentTime == 21600){
    setTargetPalette(black, six);
  } else if(currentTime == 18000){
    setTargetPalette(black, five);
  } else if(currentTime == 14400){
    setTargetPalette(black, four);
  } else if(currentTime == 10800){
    setTargetPalette(black, three);
  } else if(currentTime == 7200){
    setTargetPalette(black, two);
  } else if(currentTime == 3600){
    setTargetPalette(black, one);
  } else if(currentTime == 0){
    setTargetPalette(black, zero);
  }
}

void setCurrentPalette(CRGB colour1, CRGB colour2){
  currentPalette = CRGBPalette16(
                                   colour1,  colour2,  colour1,  colour2,
                                   colour1,  colour2,  colour1,  colour2,
                                   colour1, colour2, colour1, colour2,
                                   colour1, colour2, colour1,  colour2 );
}

void setTargetPalette(CRGB colour1, CRGB colour2){
  targetPalette = CRGBPalette16(
                                   colour1,  colour2,  colour1,  colour2,
                                   colour1,  colour2,  colour1,  colour2,
                                   colour1, colour2, colour1, colour2,
                                   colour1, colour2, colour1,  colour2 );
}

void setHourColours(){
  zero = 0x4B0082; // midnight
  one = 0x5F1F93;
  two = 0x733EA4;
  three = 0x885DB6;
  four = 0x9C7CC7;
  five = 0xB19CD9; // morning
  six =  0x979FDE;
  seven = 0x7EA2E3;
  eight = 0x65A5E9;
  nine = 0x4BA8EE;
  ten = 0x32ABF4;
  eleven = 0x19AEF9;
  twelve = 0x00B2FF; // noon
  thirteen = 0x22A7E5;
  fourteen = 0x459DCC;
  fifteen = 0x6893B3;
  sixteen = 0x8B8899;
  seventeen = 0xAE7E80;
  eighteen = 0xD17467;
  nineteen = 0xF46A4E; // evening
  twenty = 0xD25458;
  twentyone = 0xB03F62;
  twentytwo = 0x8E2A6D;
  twentythree = 0x6C1577;
}

void setupSimpleVibes(){
  unsigned long currentTime = (millis() / 1000) % 120;
  CRGB red = 0xff0000;
  CRGB orange = 0xffa500;
  CRGB yellow = 0xffff00;
  CRGB green = 0x00ff00;
  CRGB blue = 0x0000ff;
  CRGB purple = 0x461B7E;
  if(firstTime){
    if(currentTime == 20){
      setTargetPalette(blue,yellow);
      firstTime = false;
    }
  } else {
    if(currentTime == 100){
      setTargetPalette(green, red);
  } else if(currentTime == 80){
      setTargetPalette(green, orange);
  } else if(currentTime == 60){
      setTargetPalette(purple, orange);
  } else if(currentTime == 40){
      setTargetPalette(purple, yellow);
  } else if(currentTime == 20){
      setTargetPalette(blue, yellow);
  } else if(currentTime == 0){
      setTargetPalette(blue, red);
  } 
  }
}

// Basically whatever she wants I guess
void setUpMarissa(){
  CRGB redd = 0x8B0000;
  setTargetPalette(black, redd);
}

void setUpKateVibes(){
  unsigned long currentTime = (millis() / 1000) % 80;
  CRGB yellow = 0xffff00;
  CRGB green = 0x00ff00;
  CRGB blue = 0x0000ff;
  CRGB purple = 0x461B7E;
  if(currentTime == 60){
    setTargetPalette(yellow, blue);
  } else if(currentTime == 40){
    setTargetPalette(green, blue);
  } else if(currentTime == 20){
    setTargetPalette(green, purple);
  } else if(currentTime == 0){
    setTargetPalette(yellow, purple);
  }
}

void setUpEzVibes(){
  unsigned long currentTime = (millis() / 1000) % 240;
  CRGB purple = 0x3D0158;
  CRGB orange = 0xFF9900;
  CRGB green = 0x0B6623;
  CRGB pink = 0xFF69B4;
  if(currentTime == 2399){
    setTargetPalette(black, orange);
  }else if(currentTime == 179){
    setTargetPalette(black, pink);
  }else if(currentTime == 119){
    setTargetPalette(black, green);
  }else if(currentTime == 59){
    setTargetPalette(black, zero);
  }
}

void setupWizColours(){
  unsigned long currentTime = (millis() / 1000) % 280;
  // balance
  CRGB balanceBrown = 0xF5E5D8;
  CRGB balanceRed = 0xbd2b2b;
  // life
  CRGB lifeBrown = 0x904e22;
  CRGB lifeGreen = 0x0B3F25;
  // myth
  CRGB mythYellow = 0xFFFF00;
  CRGB mythBlue = 0x0000B2;
  // death
  CRGB deathBlack = CRGB::Black;
  CRGB deathGrey = 0xCCCCCC;
  // storm
  CRGB stormPurple = 0x9F00C5;
  CRGB stormYellow = 0xEBC523;
  // ice
  CRGB iceBlue = 0x2626FF;
  CRGB iceWhite = 0xE6F9FF;
  // fire
  CRGB fireRed = 0xFF0000;
  CRGB fireOrange = 0xFF8000;
  if(currentTime == 270){
    setTargetPalette(black, black);
  } else if(currentTime == 240){
    // fire (Hot)
    setTargetPalette(fireRed, fireOrange);
  } else if(currentTime == 230){
    setTargetPalette(black, black);
  } else if(currentTime == 200){
    // ice (Perfect)
    setTargetPalette(iceBlue, iceWhite);
  } else if(currentTime == 190){
    setTargetPalette(black, black);
  } else if(currentTime == 160){
    // storm (Both could stand to be darker. Transition in is strange)
    setTargetPalette(stormPurple, stormYellow);
  } else if(currentTime == 150){
    setTargetPalette(black, black);
  } else if(currentTime == 120){
    // death (White could be less white. More black)
    setTargetPalette(deathBlack, deathGrey);
  } else if(currentTime == 110){
    setTargetPalette(black, black);
  } else if(currentTime == 80){
    // myth (Spot on. Transition is how I want it. Wonder why the others don't act like this)
    setTargetPalette(mythYellow, mythBlue);
  } else if(currentTime == 70){
    setTargetPalette(black, black);
  } else if(currentTime == 40){
    // life (Colors are totally off for this. Looks more like ice color scheme. Cyan and grey)
    setTargetPalette(lifeBrown, lifeGreen);
  } else if(currentTime == 30){
    setTargetPalette(black, black);
  } else if(currentTime == 0){
    // balance (Now more like white and pink ish but meh whatever)
    setTargetPalette(balanceBrown, balanceRed);
  }
}

