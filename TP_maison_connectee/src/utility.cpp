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
void openWindow()
{
    winServo.write(117);
}

void closeWindow()
{
    winServo.write(0);
}

void initWindow()
{
    if (winServo.read() < 58) // 58 = fenêtre à mi chemin (normalement)
    {
        closeWindow();
    }
    else
    {
        openWindow();
    }
}

void updateLed()
{
    if (LED_BLINK)
    {
        if (LED_STATE)
        {
            digitalWrite(PIN_LED, HIGH);
        }
        else
        {
            digitalWrite(PIN_LED, LOW);
        }
        LED_STATE = !LED_STATE;
    }
}

void enableFan()
{
    digitalWrite(PIN_FAN1, LOW);
    analogWrite(PIN_FAN2, 180);
}

void disableFan()
{
    digitalWrite(PIN_FAN1, LOW);
    digitalWrite(PIN_FAN2, LOW);
}

void updateLCD()
{
    lcd.clear();
    if (ALARM_RAIN)
    {
        lcd.println("Pluie en cours");
    }
    if (ALARM_GAS)
    {
        lcd.println("Fuite de gaz");
    }
    if(ALARM_GAS == false && ALARM_RAIN == false)
    {
        lcd.println("Tout va bien! :)");
    }
    
}

void updateBuzzer()
{
    if (ALARM_GAS)
    {
        tone(PIN_BUZZER, 294, 250, 0);
        
    }
    else if (ALARM_RAIN)
    {
        tone(PIN_BUZZER, 440, 250, 0);
        
    }
    
}
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
    return 440 * pow(2, (n - 69) / 12);
}