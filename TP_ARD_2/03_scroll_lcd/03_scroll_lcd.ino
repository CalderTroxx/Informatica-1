#include <LiquidCrystal.h>

LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

char texto[70] = "Universidad Tecnologica Nacional Facultad Regional San Francisco     ";
bool isFlag = 0;


void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);

  for (int i = 0; i < strlen(texto); i++) {
    Serial.print(texto[i]);
  }
}

void loop() {
  for (int i = 0; i <= strlen(texto); i++) {
    if (!isFlag) {
      lcd.setCursor(i, 0);
      lcd.print(texto[i]);
      delay(100);
    }
    if (i > 15 or isFlag) {
      isFlag = 1;
      scroll(i);
      lcd.setCursor(16, 0);
      lcd.print(texto[i]);
      delay(100);
    }
  }
}

void scroll(int inicio) {
  lcd.setCursor(0, 0);
  for (int i = inicio - 15; i <= (inicio + 15); i++) lcd.print(texto[i]);
  lcd.print(" ");
}
