#include <FastLED.h>   // led library
#define LED_PIN     3    // digital pin 3 out
#define NUM_LEDS    32
#define BRIGHTNESS    
CRGB leds[NUM_LEDS];
int a;
int c = 1; // number of leds for soc
int analog=A0; // A0 input voltage from 4.17V to 4.83V
int SOC;
void setup() {
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  Serial.begin(9600);
}
void loop() {
  SOC = analogRead(analog);
  
  c=map(SOC, 825, 980, 0, 31); // maping voltage from 190V (arduino 4.17V (825)) to 220V ( arduino 4.83V (980)) -->>  0-31 led for SOC
  
  if (c<0){  // condition - minimal voltage
    c=0; }
    Serial.println(c); 
  
  for (int i = 31; i >= c; i--) {
    leds[i] = CRGB ( 255, 0, 0); // red light 
    a = 3+i*2;
      FastLED.setBrightness(a); // brightness
    FastLED.show();
    delay(80);
  }
  for (int i = 0; i <= 31; i++) {
    leds[i] = CRGB ( 0, 255, 0);    // green light
    a = 3+i*2;
         FastLED.setBrightness(a);  // brightness

    FastLED.show();
    delay(80);
  }
}

// bimerev
