#include <LiquidCrystal.h>


LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

char variables[2] = { 'x', 'y' };
float datos[2] = { 0, 0 };

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  pedir_datos();
  conversion_a_polar();
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

float conversion_a_polar() {
  float x = datos[0];
  float y = datos[1];
  
  float amplitud_polar = sqrt(pow(x, 2) + pow(y, 2));
  float fase_polar = atan(y / x) * (180 / PI);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("A. Polar: ");
  lcd.print(amplitud_polar);
  lcd.setCursor(0, 1);
  lcd.print("F. Polar: ");
  lcd.print(fase_polar);
}
