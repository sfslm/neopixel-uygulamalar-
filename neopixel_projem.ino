#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h> 
#endif

#define PIN      6
#define NUMPIXELS 12


Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

           
int ringStart = 0; 
int ringSize = 1; 
unsigned long eskiZaman=0;
unsigned long yeniZaman;

void setup() {
pixels.begin();
}

void loop() {
  yeniZaman=millis();
//pixels.setBrightness(10);//parlaklığı ayarlayabiliriz. Max 255
 
  for(int i=0;i<NUMPIXELS;i++){
    pixels.clear();
  }

  for(int i = 0; i< ringSize; i++) {
    
    pixels.setPixelColor((ringStart + i) % NUMPIXELS, pixels.Color(50,0,0));    
}
  pixels.show();  
    
 if(yeniZaman-eskiZaman >1000){
  ringStart = (ringStart + 1) % NUMPIXELS; 
 
  if(ringStart == 0) {
    ringSize++;
    
    if(ringSize >= NUMPIXELS) {
      ringSize = 1; 
        
    }
  }
  eskiZaman = yeniZaman; 
}
}
