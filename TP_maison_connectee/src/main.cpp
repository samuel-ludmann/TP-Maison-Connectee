#include "main.h"

LiquidCrystal_I2C lcd(0x27, 16, 2);
xht11 xht(PIN_TEMPERATURE_SENSOR);
Servo winServo;
bool ALARM_RAINING = false;

void setup()
{

  Serial.begin(9600);
  Wire.begin();

  lcd.init();
  lcd.backlight();

  winServo.attach(PIN_SERVO);
  winServo.write(176);

  // READ
  pinMode(PIN_GAS_SENSOR, INPUT);
  pinMode(PIN_BUTTON_IN, INPUT);
  pinMode(PIN_STEAM_SENSOR, INPUT);

  // WRITE
  pinMode(PIN_BUZZER, OUTPUT);


  delay(200);
}

void loop()
{
  static bool closeWin = false;
  static bool lastButtonState = false;
  static unsigned long lastDebounceTime = 0;
  const unsigned long debounceDelay = 50;  // Anti-rebond

  bool buttonState = readButtonIn();

  if (buttonState != lastButtonState) {
    lastDebounceTime = millis();  // Reset du timer si changement d'état
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (buttonState && !closeWin) {
      closeWin = true;
    } else if (buttonState && closeWin) {
      closeWin = false;
    }
  }

  lastButtonState = buttonState;  // Sauvegarde de l'état du bouton

  // Contrôle du servo
  if (closeWin) {
    winServo.write(0);  // Position fermée
  } else {
    winServo.write(176);  // Position ouverte
  }

  delay(10);
}
