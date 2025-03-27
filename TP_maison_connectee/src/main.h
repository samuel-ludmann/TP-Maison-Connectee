#include <Arduino.h>
#include <Wire.h>
#include <ESP32Servo.h>
#include <LiquidCrystal_I2C.h>
#include <xht11.h>
#include <ESP32Tone.h>
#include <math.h>

#pragma once

extern LiquidCrystal_I2C lcd;
extern xht11 xht;
extern bool ALARM_RAIN;
extern Servo winServo;
extern bool ALARM_GAS;
extern bool LED_BLINK;
extern bool LED_STATE;
extern bool WINDOW_STATE;
extern bool FAN_STATE;

// READ PINS
#define PIN_LED 12
#define PIN_TEMPERATURE_SENSOR 17
#define PIN_GAS_SENSOR 23
#define PIN_BUTTON_IN 27
#define PIN_STEAM_SENSOR 34

// WRITE PINS
#define PIN_SERVO 5
#define PIN_FAN2 18
#define PIN_FAN1 19
#define PIN_BUZZER 25


// READ FUNCTIONS
int readTemperatureSensor();
bool readGasSensor();
bool readButtonIn();
int readSteamSensor();

// WRITE FUNCTIONS
void openWindow();
void closeWindow();
void enableFan();
void disableFan();
void updateLCD(unsigned long currentMillis, long interval = 500);
void updateBuzzer(unsigned long currentMillis, long interval = 500);
void updateLed(unsigned long currentMillis, long interval = 500);
void updateButton(unsigned long currentMillis, long interval = 500);

// MONITORING
void printDebug(unsigned long currentMillis, long interval = 500);

// THEMES
void loopTheme2(unsigned long currentMillis, long interval = 500);
void loopTheme6(unsigned long currentMillis, long interval = 500);
