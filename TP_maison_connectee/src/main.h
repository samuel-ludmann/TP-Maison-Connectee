#include <Arduino.h>
#include <Wire.h>
#include <ESP32Servo.h>
#include <LiquidCrystal_I2C.h>

#pragma once

extern LiquidCrystal_I2C lcd;
extern bool ALARM_RAINING;

// READ PINS
#define PIN_TEMPERATURE_SENSOR 17
#define PIN_GAS_SENSOR 23
#define PIN_BUTTON_IN 27
#define PIN_STEAM_SENSOR 34

// WRITE PINS
#define PIN_BUZZER 25

// READ FUNCTIONS
int readTemperatureSensor();
int readGasSensor();
bool readButtonIn();
int readSteamSensor();

// WRITE FUNCTIONS


// MONITORING
void printDebug();