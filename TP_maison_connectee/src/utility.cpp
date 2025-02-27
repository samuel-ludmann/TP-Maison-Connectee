#include "main.h"

// READ
int readTemperatureSensor()
{
    static unsigned char dht[4] = {0, 0, 0, 0};
    xht.receive(dht);
    return dht[2];
}

bool readGasSensor()
{
    return digitalRead(PIN_GAS_SENSOR) == LOW;
}

bool readButtonIn()
{
    return digitalRead(PIN_BUTTON_IN) == LOW;
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


int getNote(int n)
{
    return 440*pow(2, (n-69)/12);
}