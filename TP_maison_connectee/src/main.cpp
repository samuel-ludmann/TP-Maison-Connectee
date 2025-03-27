#include "main.h"

LiquidCrystal_I2C lcd(0x27, 16, 2);
xht11 xht(PIN_TEMPERATURE_SENSOR);
Servo winServo;
bool ALARM_RAIN = false;
bool ALARM_GAS = false;
bool LED_BLINK = false;
bool LED_STATE = false;
bool WINDOW_STATE = false;
bool FAN_STATE = false;

void setup()
{

  Serial.begin(9600);
  Wire.begin();

  lcd.init();
  lcd.backlight();

  winServo.attach(PIN_SERVO);
  closeWindow();
  
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
  unsigned long currentMillis = millis();

  updateButton(currentMillis, 100);
  loopTheme2(currentMillis, 100);
  loopTheme6(currentMillis, 100);
  printDebug(currentMillis, 2000);
  updateLed(currentMillis, 250);
  updateLCD(currentMillis);
  updateBuzzer(currentMillis, 2000);

  delay(20);
}
