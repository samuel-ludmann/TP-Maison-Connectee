#include "main.h"

void loopTheme2()
{
    if (readSteamSensor() >= 3000 && ALARM_RAIN == false)
    {
        ALARM_RAIN = true;
        if (WINDOW_STATE == true)
        {
            closeWindow();
        }
    }
    else if (readSteamSensor() <= 1000 && ALARM_RAIN == true)
    {
        ALARM_RAIN = false;
    }
}