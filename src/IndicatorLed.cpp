#include "IndicatorLed.h"
#include "Arduino.h"
#include <Adafruit_NeoPixel.h>

IndicatorLed::IndicatorLed(){}
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
void IndicatorLed::init()
{
    strip.begin();
    strip.setPixelColor(0, 255, 255, 255); 
    strip.setBrightness(32);
    strip.show();
}

void IndicatorLed::update()
{
    if(strip.canShow() && updates)
    {
        strip.setPixelColor(0, colour[0], colour[1], colour[2]);
        strip.show();
        updates = false;
    }
}