#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd (0x27, 2, 1, 0, 4, 5, 6, 7);

#define pin_sensor_temperatura A0

int lectura_sensor;
float temperatura;
float temperatura_final;
float temperatura_anterior;

unsigned long tiempo_transcurrido;
int tiempo_de_retardo = 60000;

float fun_temperatura()
{

  if((millis() - tiempo_transcurrido) > tiempo_de_retardo){

    lectura_sensor = analogRead(pin_sensor_temperatura);
    temperatura = ((lectura_sensor * 5000.0) / 1023) / 10;
    tiempo_transcurrido = millis();
    temperatura_anterior = temperatura;
    return temperatura;

  }else{
    return temperatura_anterior;
  }
}

void setup()
{
    lcd.setBacklightPin(3,POSITIVE);
    lcd.setBacklight(HIGH);
    lcd.begin(16, 2);
    lcd.clear();
}

void loop()
{
  temperatura_final = fun_temperatura();

  lcd.setCursor(2, 0);
  lcd.print("Temperatura");
  lcd.setCursor(4, 1);
  lcd.print(temperatura_final);
}