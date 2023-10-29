#include <LiquidCrystal.h>

LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

String variables[2] = { "amplitud_polar", "fase_polar" };
float datos[2] = { 0, 0 };

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  pedir_datos();
  conversion_a_rectangular();
}

void loop() {
}

void pedir_datos() {
  for (int i = 0; i < 2; i++) {
    Serial.print("Ingrese el valor de ");
    Serial.print(variables[i]);
    Serial.println(": ");

    while (!Serial.available()) {
    }

    datos[i] = Serial.parseFloat();

    Serial.print("Dato guardado en ");
    Serial.print(variables[i]);
    Serial.print(": ");
    Serial.println(datos[i]);
  }
}

float conversion_a_rectangular() {
  float amplitud_polar = datos[0];
  float fase_polar = datos[1];

  float x = amplitud_polar * (cos(fase_polar * PI / 180));
  float y = amplitud_polar * (sin(fase_polar * PI / 180));

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("i: ");
  lcd.print(x);
  lcd.setCursor(0, 1);
  lcd.print("j: ");
  lcd.print(y);
}
