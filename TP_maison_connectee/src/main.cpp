#include "main.h"


LiquidCrystal_I2C lcd(0x27,16,2);
xht11 xht(PIN_STEAM_SENSOR);
bool ALARM_RAINING = false;


void setup()
{
  
  Serial.begin(9600);
  Wire.begin();

  lcd.init();
  lcd.backlight();
  
  pinMode(PIN_GAS_SENSOR, INPUT);
  pinMode(PIN_BUTTON_IN, INPUT);
  pinMode(PIN_STEAM_SENSOR, INPUT);
  
}


void loop()
{
  printDebug();
  delay(500);
}
