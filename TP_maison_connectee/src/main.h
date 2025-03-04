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

// READ PINS
#define PIN_LED 12
#define PIN_TEMPERATURE_SENSOR 17
#define PIN_GAS_SENSOR 23
#define PIN_BUTTON_IN 27
#define PIN_STEAM_SENSOR 34

// WRITE PINS
#define PIN_SERVO 5
#define PIN_BUZZER 25
#define PIN_FAN1 19
#define PIN_FAN2 18


// READ FUNCTIONS
int readTemperatureSensor();
bool readGasSensor();
bool readButtonIn();
int readSteamSensor();

// WRITE FUNCTIONS
void openWindow();
void closeWindow();
void initWindow();
void enableFan();
void disableFan();
void updateLCD();
void updateBuzzer();

// MONITORING
void printDebug();
void updateLed();

int getNote(int n);
