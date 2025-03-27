#include "main.h"

void loopTheme6(unsigned long currentMillis, long interval)
{
    static unsigned long previousMillis = 0;

    if (currentMillis - previousMillis <= interval)
        return;
    previousMillis = currentMillis;

    // GESTION DE L'ALARME DE GAZ
    if (readGasSensor() && ALARM_GAS == false)
    {
        ALARM_GAS = true;
        if (WINDOW_STATE == false)
        {
            openWindow();
        }
    }
    // else if (readGasSensor() == false && ALARM_GAS == true)
    // {
    //     ALARM_GAS = false;
    // }

    // GESTION VENTILATEUR
    
    int temp = readTemperatureSensor();
    if (temp >= 28 && FAN_STATE == false)
    {
        enableFan();
    }
    else if (temp <= 27 && FAN_STATE == true)
    {
        disableFan();
    }
}