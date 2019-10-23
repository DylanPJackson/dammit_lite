#include <FastLED.h>

#define LED_PIN 7
#define COLOR_ORDER GRB
#define CHIPSET WS2811
#define NUM_LEDS 150
#define brightness 50

CRGB leds[NUM_LEDS];

boolean intro;

void setup() {
  Serial.begin(9600);
  FastLED.addLeds<CHIPSET, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS);
  FastLED.setBrightness(brightness);
  intro = true;
}

void loop() {
  String message = "";
  CRGB firstColor;
  CRGB secondColor;
  if (intro) {
    Serial.println(F("\n \n The heiroglyphics above are just noise. \nFor assistance, type 'help'"
                     "\n\n***LED STRIP CUSTOMISER***\nVariables: 2\nFunction: Half || Whole"));
    intro = false;
  } else {
    while (Serial.available()) {
      message += char(Serial.read());
    }
    if (!Serial.available()) {
      if (message != "") {
        if (message == "help") {
          Serial.println(F("\n Testing the creation of simple variables, and future"
                           "concepts. Basic functionality, state that you're going to create a color,"
                           "provide the color, then state that you want to display it"));
          message = "";
        } else if (message == "
                   else {
                   Serial.println(F("Received the following garbage: " ));
                 }
                 }
                 }
                 }

                 }
