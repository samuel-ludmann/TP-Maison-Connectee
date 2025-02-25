#include "main.h"


LiquidCrystal_I2C lcd(0x27,16,2);
bool ALARM_RAINING = false;
void setup()
{
  
  Serial.begin(9600);
  Wire.begin();

  lcd.init();
  lcd.backlight();
  
  pinMode(PIN_STEAM_SENSOR, INPUT);
  pinMode(BUZZER, OUTPUT);
  
}
void loop()
{
  isRaining();
  delay(100);
}
