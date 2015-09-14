// NeoPixel Effects library Chase effect test (c) 2015 Nolan Moore
// released under the GPLv3 license to match the AdaFruit NeoPixel library

#include "NeoPixelEffects.h"
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN            A0
#define NUMPIXELS      144

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

Effect effectType = CHASE;  // Effect
int rangeStart = 0;         // # pixel (> 0 and < NUMPIXELS - 2)
int rangeEnd = 47;          // # pixel (> 1 and < NUMPIXELS - 1)
int areaOfEffect = 10;       // # pixels (> 0 and < rangeEnd - rangeStart)
unsigned long updateDelay = 500;   // millis
int redValue = 200;           // 0 to 255
int greenValue = 75;       // 0 to 255
int blueValue = 0;          // 0 to 255
EffectColor white = {150, 150, 150};

NeoPixelEffects chaseEffect = NeoPixelEffects(&pixels, effectType, rangeStart, rangeEnd, areaOfEffect, updateDelay, white);

void setup() {
  pixels.begin();
  Serial.begin(9600);
}

void loop() {
  chaseEffect.update();
}
