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
    const int DEBOUNCE_DELAY = 300;
    static unsigned long lastButtonPressTime = 0;
    
    if (digitalRead(PIN_BUTTON_IN) == LOW)
    {
        unsigned long currentTime = millis();
        if (currentTime - lastButtonPressTime > DEBOUNCE_DELAY)
        {
            lastButtonPressTime = currentTime;
            return true;
        }
    }
    return false;
}

int readSteamSensor()
{
    return analogRead(PIN_STEAM_SENSOR);
}

// WRITE
void openWindow()
{
    Serial.println("openWindow");
    winServo.write(115);
    WINDOW_STATE = true;
}

void closeWindow()
{
    Serial.println("closeWindow");
    winServo.write(0);
    WINDOW_STATE = false;
}

void updateLed(unsigned long currentMillis, long interval)
{
    static unsigned long previousMillis = 0;

    if (currentMillis - previousMillis <= interval)
        return;
    previousMillis = currentMillis;

    if (ALARM_GAS == true || ALARM_RAIN == true)
    {
        if (LED_STATE)
        {
            digitalWrite(PIN_LED, LOW);
        }
        else
        {
            digitalWrite(PIN_LED, HIGH);
        }
        LED_STATE = !LED_STATE;
    }
    else
    {
        digitalWrite(PIN_LED, LOW);
        LED_STATE = false;
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

void updateLCD(unsigned long currentMillis, long interval)
{
    static unsigned long previousMillis = 0;

    if (currentMillis - previousMillis <= interval)
        return;
    previousMillis = currentMillis;

    lcd.clear();
    if (ALARM_GAS)
    {
        Serial.println("LCD: ALARM_GAS");
        lcd.setCursor(0, 0);
        lcd.print("Fuite de gaz");
    }
    if (ALARM_RAIN)
    {
        Serial.println("LCD: ALARM_RAIN");
        lcd.setCursor(0, ALARM_GAS == false ? 0 : 1);
        lcd.print("Pluie en cours");
    }
    if (ALARM_GAS == false && ALARM_RAIN == false)
    {
        Serial.println("LCD: OK");
        lcd.setCursor(0, 0);
        lcd.print("Tout va bien! :)");
    }
}

void updateBuzzer(unsigned long currentMillis, long interval)
{
    static unsigned long previousMillis = 0;

    if (currentMillis - previousMillis <= interval)
        return;
    previousMillis = currentMillis;

    if (ALARM_GAS)
    {
        tone(PIN_BUZZER, 294, 250, TONE_CHANNEL);
    }
    else if (ALARM_RAIN)
    {
        tone(PIN_BUZZER, 440, 250, TONE_CHANNEL);
    }
}
// MONITORING
void printDebug(unsigned long currentMillis, long interval)
{
    static unsigned long previousMillis = 0;

    if (currentMillis - previousMillis <= interval)
        return;
    previousMillis = currentMillis;

    Serial.println("");

    Serial.print("TEMPERATURE_SENSOR : ");
    Serial.println(readTemperatureSensor());

    Serial.print("GAS_SENSOR : ");
    Serial.println(readGasSensor());

    Serial.print("BUTTON_IN : ");
    Serial.println(readButtonIn());

    Serial.print("STEAM_SENSOR: ");
    Serial.println(readSteamSensor());

    Serial.print("SERVO : ");
    Serial.println(winServo.read());

    Serial.println("");
}

void updateButton(unsigned long currentMillis, long interval)
{
    static unsigned long previousMillis = 0;

    if (currentMillis - previousMillis <= interval)
        return;
    previousMillis = currentMillis;

    if ((ALARM_GAS || ALARM_RAIN) && readButtonIn() == true)
    {
            ALARM_GAS = false;

            ALARM_RAIN = false;
    }
}