/*

NeoPixel LEDs

modified on 7 May 2019
by Saeed Hosseini @ Electropeak
https://electropeak.com/learn/

*/

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

#define PIN        6
#define NUMPIXELS 12


Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void NeoBlink(int num, int wait)
{
for (int i = 0; i < num; i++)
{
pixels.setPixelColor(i, 35, 35, 35);
}
pixels.show();
delay(wait);
for (int j = 0; j < num; j++)
{
pixels.setPixelColor(j, 0, 255, 0);
}
pixels.show();
delay(wait);
}

void setup()
{
pixels.begin();
pixels.setBrightness(50);
}

void loop()
{
NeoBlink(12, 500);
}
