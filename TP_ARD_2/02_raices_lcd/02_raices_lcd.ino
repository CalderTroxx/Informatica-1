#include <LiquidCrystal.h>

LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

char variables[3] = {'a', 'b', 'c'};
float datos[3] = {0, 0, 0};

void setup()
{
    Serial.begin(9600);
    lcd.begin(16, 2)
        pedir_datos();
    calcular_raices();
}

void loop()
{
}

void pedir_datos()
{
    for (int i = 0; i < 3; i++)
    {
        Serial.print("Ingrese el valor de ");
        Serial.print(variables[i]);
        Serial.println(": ");

        while (!Serial.available())
        {
        }

        datos[i] = Serial.parseFloat();

        Serial.print("Dato guardado en ");
        Serial.print(variables[i]);
        Serial.print(": ");
        Serial.println(datos[i]);
    }
}

void calcular_raices()
{
    float a = datos[0];
    float b = datos[1];
    float c = datos[2];

    float d = pow(b, 2) - 4 * a * c;
    Serial.println("Discriminante: " + String(d));

    if (d < 0)
    {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Discr. Invalido");
    }
    else
    {
        float x1 = (-b + sqrt(d)) / (2 * a);
        float x2 = (-b - sqrt(d)) / (2 * a);

        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Raiz N1: ");
        lcd.print(x1);
        lcd.setCursor(0, 1);
        lcd.print("Raiz N2: ");
        lcd.print(x2);
    }
}
