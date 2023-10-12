#include <LiquidCrystal.h>

int potes [3] = {A0, A2, A4};
int pins [3] = {11, 9, 10};
int RGB [3] = {0, 0, 0};
int XRGB [3] = {0, 0, 0};
String LED [3] = {"Red", "Green", "Blue"};

unsigned long timer = 5;
bool state = 0;

LiquidCrystal lcd(13, 12, 4, 3, 2, 8);
void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);

  for (int i = 0; i <= 2; i++) {
    pinMode(pins[i], OUTPUT);
    RGB[i] = analogRead(potes[i]) / 4;
    XRGB[i] = RGB[i];
  }

  cli();
  TCCR1A = 0;
  TCCR1B = 0;
  OCR1A = 15624;
  TCCR1B |= (1 << WGM12);
  TCCR1B |= (1 << CS12);
  TCCR1B |= (1 << CS10);
  TIMSK1 = (1 << OCIE1A);
  sei();
}
ISR(TIMER1_COMPA_vect) {
  timer++;
  state = !state;
}
void RGBS() {
  for (int i = 0; i <= 2; i++) {
    RGB[i] = analogRead(potes[i]) / 4;
    //analogWrite(6, 255);
    analogWrite(pins[i], RGB[i]);
  }
}
void mostrar() {
  for (int i = 0; i <= 2; i++) {
    if (XRGB[i] != RGB[i] and abs(XRGB[i] - RGB[i] > 1 or RGB[i] - XRGB[i] > 1)) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(LED[i] + ":");
      if (RGB[i] < 10) {
        lcd.print(RGB[i]);
        lcd.print("  ");
      } else if (RGB[i] < 100) {
        lcd.print(RGB[i]);
        lcd.print("  ");
      } else {
        lcd.print(RGB[i]);
      }
      lcd.setCursor(0, 1);
      lcd.print("#");
      for (int i = 0; i <= 2; i++) {
        lcd.print(RGB[i], HEX);
      }
      XRGB[i] = RGB[i];
      timer = 0;
    } else menu();
  }
}
void menu() {
  Serial.println(state);
  if (timer >= 3) {
    if (state == 0) {
      lcd.setCursor(0, 0);
      lcd.print("   I.P.E.T 50");
    } else if(state == 1){
      lcd.setCursor(0, 0);
      lcd.print("   El Humilde");
    }
    lcd.setCursor(0, 1);
    lcd.print("       ");
  }
}
void loop() {
  mostrar();
  RGBS();
}