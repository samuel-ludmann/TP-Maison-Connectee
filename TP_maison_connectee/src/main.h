#include <Arduino.h>
#include <Wire.h>
#include <ESP32Servo.h>
#include <LiquidCrystal_I2C.h>

#pragma once

#define PIN_STEAM_SENSOR 34
#define BUZZER 25
#define BUZZER_CHANNEL 0

extern LiquidCrystal_I2C lcd;

extern bool ALARM_RAINING;
bool isRaining();
