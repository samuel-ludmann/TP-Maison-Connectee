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




// MONITORING
void printDebug()
{
    Serial.println("");

    Serial.print("TEMPERATURE_SENSOR : ");
    Serial.println(readTemperatureSensor());

    Serial.print("GAS_SENSOR : ");
    Serial.println(readGasSensor());

    Serial.print("BUTTON_IN : ");
    Serial.println(readButtonIn());
    
    Serial.print("STEAM_SENSOR: ");
    Serial.println(readSteamSensor());

    Serial.println("");
}