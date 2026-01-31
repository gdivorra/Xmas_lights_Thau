#include <Adafruit_NeoPixel.h>  //Incloure llibreria
#define LED_PIN    9   // Pin on es connecta el LED
#define LED_COUNT  200     // Número de LEDs
#define LOOP_SECONDS 300   //Ha de ser múltiple de 6

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

// Convertir 32 bits (hue) a RGB
uint32_t colorFromHue(uint16_t hue) 
{
  return strip.ColorHSV(hue, 255, 255);  
}

void setup() 
{
  strip.begin();
  strip.show(); // Posa tots els Leds a off
  strip.setBrightness(255);
}

void loop() 
{
  for (int j = 0; j < LOOP_SECONDS;) //Fins a LOOP_SECONDS segons
  {
   static uint16_t hue = 0;

   for (int i = 0; i < LED_COUNT; i++)
   {
     uint32_t c = colorFromHue(hue);
     strip.setPixelColor(i, c);
     hue += 65536 * 68 / 15 / LED_COUNT; //32 bits * quants cops es repeteix per tira dividit per num leds
     delay(100);
     strip.show();
   }
   j += 20; //20 segons
  }

  for (int i = 0; i < LOOP_SECONDS;) //Fins a LOOP_SECONDS segons
  {
   strip.show();
   strip.fill(strip.Color(255, 0, 0));
   delay(1000);
   strip.show();
   strip.fill(strip.Color(0,255,0));
   delay(1000);
   strip.show();
   strip.fill(strip.Color(0,0,255));
   delay(1000);
   i += 3; //3 segons
  }

 for (int k = 0; k < LOOP_SECONDS;) //Fins a LOOP_SECONDS segons
 {
   delay(1000);
   strip.show();
   for (int i = 0; i < strip.numPixels(); i += 2)
   for (int j = 1; j < strip.numPixels(); j += 2)
   {
     strip.setPixelColor(i, strip.Color(0,250,0));
     strip.setPixelColor(j, strip.Color(250,0,0));
    }
   delay(1000);
   strip.show();
   for (int i = 1; i < strip.numPixels(); i += 2)
   for (int j = 0; j < strip.numPixels(); j += 2)
   {
     strip.setPixelColor(i, strip.Color(250,0,0));
     strip.setPixelColor(j, strip.Color(0,250,0));
     k += 2; //2 segons
    }
  }
}
