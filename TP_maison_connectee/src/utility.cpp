#include "main.h"

// READ
int readTemperatureSensor()
{
    return analogRead(PIN_TEMPERATURE_SENSOR);
}

int readGasSensor()
{
    return analogRead(PIN_GAS_SENSOR);
}

bool readButtonIn()
{
    return digitalRead(PIN_BUTTON_IN) == HIGH;
}

int readSteamSensor()
{
    return analogRead(PIN_STEAM_SENSOR);
}

// WRITE