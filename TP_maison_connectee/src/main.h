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
extern bool ALARM_RAINING;
extern Servo winServo;

// READ PINS
#define PIN_TEMPERATURE_SENSOR 17
#define PIN_GAS_SENSOR 23
#define PIN_BUTTON_IN 27
#define PIN_STEAM_SENSOR 34

// WRITE PINS
#define PIN_SERVO 5
#define PIN_BUZZER 25


// READ FUNCTIONS
int readTemperatureSensor();
bool readGasSensor();
bool readButtonIn();
int readSteamSensor();

// WRITE FUNCTIONS


// MONITORING
void printDebug();


int getNote(int n);
