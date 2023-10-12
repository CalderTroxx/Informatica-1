#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd (0x27, 2, 1, 0, 4, 5, 6, 7);
void setup()
{
    lcd.setBacklightPin(3,POSITIVE);
    lcd.setBacklight(HIGH);
    lcd.begin(16, 2);
    lcd.clear();
}

void loop()
{
    lcd.setCursor(3, 0);
    lcd.print("Ingenieria");
    lcd.setCursor(4, 1);
    lcd.print("Electronica");
}