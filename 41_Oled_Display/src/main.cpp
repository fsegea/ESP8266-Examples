#include <Arduino.h>

#include <OLED_I2C.h>

OLED  myOLED(21, 22); // Remember to add the RESET pin if your display requires it...

extern uint8_t SmallFont[];

void setup()
{
  if(!myOLED.begin(SSD1306_128X32))
    while(1);   // In case the library failed to allocate enough RAM for the display buffer...

  myOLED.setFont(SmallFont);
  randomSeed(analogRead(0));
}

void loop()
{
  int y = random(0, myOLED.getDisplayHeight()-8);
  for (int i=128; i>=-(34*6); i--)
  {
    myOLED.print("OLED_I2C Scrolling Text Demo ", i, y);
    myOLED.update();
    delay(50);
  }
}
