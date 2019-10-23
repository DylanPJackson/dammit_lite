#include <FastLED.h>

#define LED_PIN 7
#define COLOR_ORDER GRB
#define CHIPSET WS2811
#define NUM_LEDS 150
CRGB leds[NUM_LEDS];
#define seizureTime 100
#define brightness 100

String message;
boolean intro;

// Standard colors
CRGB red = CRGB::Red;
CRGB orange = CRGB::Orange;
CRGB yellow = CRGB::Yellow;
CRGB green = CRGB::Green;
CRGB blue = CRGB::Blue;
CRGB purple = CRGB::Purple;
CRGB black = CRGB::Black;
 
void setup()
{
 Serial.begin(9600); 
 FastLED.addLeds<CHIPSET, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS);
 FastLED.setBrightness(brightness);
 intro = true;
}
 
void loop()
{
  if(intro){
    Serial.println("\n \nDon't mind that garbage up there. Just noise.\nTo understand what's going on, type help"
    "\n\n***LED STRIP CUSTOMISER***\nLED Pin: " + String(LED_PIN) + ""
    "\nNumber of LED's: " + String(NUM_LEDS));
    intro = false;
  } else {
      while(Serial.available()){
    message += char(Serial.read());
  } if(!Serial.available()){
    if(message != ""){
        if(message == "blue"){
          Serial.println("Received blue");
          message="";
          for(int i = 0; i < NUM_LEDS; i++){
            leds[i] = blue;
          }
          FastLED.show();
        } else if(message == "red"){
          Serial.println("Received red");
          message = "";
          for(int i = 0; i < NUM_LEDS; i++){
            leds[i] = red;
          }
          FastLED.show();
        } else if(message == "black"){
          Serial.println("Received black");
           message = "";
          for(int i = 0; i < NUM_LEDS; i++){
            leds[i] = black;
          }
        } else if(message == "orange"){
          Serial.println("Received orange");
          message = "";
          for(int i = 0; i < NUM_LEDS; i++){
            leds[i] = orange;
          }
          FastLED.show();
        } else if(message == "yellow"){
          Serial.println("Received yellow");
          message = "";
          for(int i = 0; i < NUM_LEDS; i++){
            leds[i] = yellow;
          }
          FastLED.show();
        } else if(message == "green"){
          Serial.println("Received green");
          message = "";
          for(int i = 0; i < NUM_LEDS; i++){
            leds[i] = green;
          }
          FastLED.show();
        } else if(message == "purple"){
          Serial.println("Received purple");
          message = "";
          for(int i = 0; i < NUM_LEDS; i++){
            leds[i] = purple;
          }
          FastLED.show();
        } else if(message == "the gays"){
          Serial.println("Received the gays");
          message = "";
          for(int i = 0; i < NUM_LEDS; i = i +1){
            leds[i]=CHSV(random8(),255,255);
          }
          delay(seizureTime);
          FastLED.show();
          for(int i = NUM_LEDS; i >= 0; i = i - 1){      
            for(int i = 0; i < NUM_LEDS; i = i + 1){
            leds[i]=CHSV(random8(),255,255);
          }
          delay(seizureTime);
          FastLED.show();
          }
        } else if(message == "help"){
          Serial.println("\nThis is a text based interface to customise a strip of LED's.\n"
          "As you may have noticed, you'll get cut off sometimes while sending a command. "
          "That's just because the bluetooth module doesn't like to wait too long. "
          "Make sure to keep your commands short, and wait until you've received confirmation before "
          "typing in a new command. Also check to see the TX light go off on the Arduino. If it's still "
          "on, that means it's still sending data back to you, rather than waiting to receive"
          "\n\n**Current Commands**\n'red': turns the whole thing red"
          "\n'black': turns it off\n'the gays': summons the gays");
          message = "";
        }
        else{
            Serial.println("Received the following garbage: " + message);
            message = ""; 
        }
      } 
    }
  }
  delay(5000);
}
