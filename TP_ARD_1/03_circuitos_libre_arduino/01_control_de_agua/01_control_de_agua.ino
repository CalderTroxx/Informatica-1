#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

int agua;
int aguaAnterior;
int temp = 50;
int tempDeseada = 25;

unsigned long timeDiference;
unsigned long timeNow;
int range = 200;

bool mode = 1;
bool flag = 0;

bool flag_mostrar = 0;

void boton() {
  if (millis() > timeDiference + range) {
    if (millis() - timeNow < 400) {
      tempDeseada++;
      mode = !mode;
      //lcd.clear();
    }
    tempDeseada--;
    if (tempDeseada <= 0)tempDeseada = 50;
    timeNow = millis();
    timeDiference = millis();
  }
}
void boton2() {
  if (millis() > timeDiference + range) {
    if (millis() - timeNow < 300) {
    }
    tempDeseada++;
    if (tempDeseada > 50)tempDeseada = 50;
    timeNow = millis();
    timeDiference = millis();
  }
}
void aguaFun() {
  imprimir();
  if (agua < 65) {
    while (agua < 95) {
      flag = 1;
      lcd.setCursor(13, 1);
      lcd.print(" ON");
      imprimir();
    }
  } else {
    lcd.setCursor(13, 1);
    lcd.print("OFF");
    flag = 0;
  }
}
void imprimir() {
  agua = analogRead(A0);
  agua = map(agua, 0, 1023, 0, 100);
  if (mode == 0) {
    if (agua != aguaAnterior or flag_mostrar == 0) {
      lcd.setCursor(0, 0);
      lcd.print("TERMOTANQUE    ");
      lcd.setCursor(0, 1);
      if(agua < 10){
        lcd.setCursor(0, 1);
        lcd.print("    ");
        lcd.setCursor(0, 1);
        lcd.print((String) agua + "%");
      }
      if(agua < 100){
        lcd.setCursor(0, 1);
        lcd.print("    ");
        lcd.setCursor(0, 1);
        lcd.print((String) agua + "%");
      }else lcd.print((String) agua + "%");
      
      aguaAnterior = agua;
      flag_mostrar = 1;
    }
    lcd.setCursor(5, 1);
    lcd.print((String)temp + (char)67);
    lcd.setCursor(13, 1);
  }
}
ISR (TIMER1_COMPA_vect) {
  if (agua < 95 and flag == 1 or temp > tempDeseada) {
    temp--;
  }
  else if (temp < tempDeseada) {
    temp++;
  }
}
void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);
  agua = analogRead(A0);
  agua = map(agua, 0, 1023, 0, 100);
  aguaAnterior = agua;
  attachInterrupt(digitalPinToInterrupt(3), boton, RISING);
  attachInterrupt(digitalPinToInterrupt(2), boton2, RISING);
  pinMode(A0, INPUT);
  cli();
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1 = 0;
  OCR1A = 15624;
  TCCR1B |= (1 << WGM12);
  TCCR1B |= (1 << CS12) | (1 << CS10);
  TIMSK1 |= (1 << OCIE1A);
  sei();
}
void loop() {
  if (mode == 0)aguaFun();
  else {
    lcd.setCursor(0, 0);
    lcd.print("SELECCIONE TEMP");
    lcd.setCursor(0, 1);
    if (tempDeseada < 10)lcd.print((String)tempDeseada + " ");
    else lcd.print((String) tempDeseada + "                           ");
  }
}