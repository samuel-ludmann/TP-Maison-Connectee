#include "main.h"

void loopTheme2(unsigned long currentMillis, long interval)
{
    static unsigned long previousMillis = 0;

    if (currentMillis - previousMillis <= interval)
        return;
    previousMillis = currentMillis;

    // GESTION DE L'ALARME DE PLUIE
    if (readSteamSensor() >= 3000 && ALARM_RAIN == false)
    {
        ALARM_RAIN = true;
        if (WINDOW_STATE == true)
        {
            closeWindow();
        }
    }
    // else if (readSteamSensor() <= 1000 && ALARM_RAIN == true)
    // {
    //     ALARM_RAIN = false;
    // }

    // GESTION DE LA COMMANDE DE LA FENETRE
    int servoState = winServo.read();
    bool buttonState = readButtonIn();

    if (buttonState == true && servoState <=10)
    {
        openWindow();
    }
    else if (buttonState == true && servoState >=90)
    {
        closeWindow();
    }
    
}