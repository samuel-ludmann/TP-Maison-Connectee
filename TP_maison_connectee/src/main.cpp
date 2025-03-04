#include "main.h"

LiquidCrystal_I2C lcd(0x27, 16, 2);
xht11 xht(PIN_TEMPERATURE_SENSOR);
Servo winServo;
bool ALARM_RAIN = true;
bool ALARM_GAS = true;
bool LED_BLINK = true;
bool LED_STATE = true;

void setup()
{

  Serial.begin(9600);
  Wire.begin();

  lcd.init();
  lcd.backlight();

  winServo.attach(PIN_SERVO);
  initWindow();

  // READ
  pinMode(PIN_GAS_SENSOR, INPUT);
  pinMode(PIN_BUTTON_IN, INPUT);
  pinMode(PIN_STEAM_SENSOR, INPUT);

  // WRITE
  pinMode(PIN_BUZZER, OUTPUT);
  pinMode(PIN_LED, OUTPUT);
  pinMode(PIN_FAN1, OUTPUT);
  pinMode(PIN_FAN2, OUTPUT);
  
  delay(200);
}

void loop()
{
  printDebug();
  updateLed();
  updateLCD();
  updateBuzzer();
  delay(2000);
}
