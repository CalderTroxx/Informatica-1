#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

String months [] = {"January", "February", "March", "Aplil", "May", "June", "July", "August", "September", "October", "November", "December"};
int limite [] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int tiempo[] = {0, 0, 12, 10, 2023}; // Segundos Minutos Horas Dias Años

int indiceMes = 0;
int indice = 0;

int potes [] = {A0, A2};
int valores [] = {0, 0};
String sensor [] = {"%", "C"};
bool state = 0;

int botonUno = 2;
int botonDos = 3;

unsigned long timeDiference;
unsigned long timeNow;
int range = 200;

bool mode = 0;
bool parpadeo;
bool flag;


void watch() {
  if (tiempo[0] > 59) {
    tiempo[1]++;
    tiempo[0] = 0;
    if (tiempo[1] > 59) {
      tiempo[2]++;
      tiempo[1] = 0;
      if (tiempo[2] > 24) {
        tiempo[3]++;
        tiempo[2] = 0;
        if (tiempo[3] > limite[indice]) {
          indiceMes++;
          tiempo[3] = 1;
          lcd.clear();
          if (indiceMes > 12) {
            tiempo[4]++;
            indiceMes = 0;
          }
        }
      }
    }
  }

  lcd.setCursor(0, 0);
  lcd.print((String)tiempo[3] + " ");
  lcd.setCursor(3, 0);
  lcd.print(months[indiceMes] + "     ");
  lcd.setCursor(12, 0);
  lcd.print((String)tiempo[4]);

  lcd.setCursor(0, 1);
  for (int i = 2; i >= 0; i--) {
    if (tiempo[i] < 10) {
      lcd.print("0");
      lcd.print((String) tiempo[i] + ":");
    }
    else {
      lcd.print((String) tiempo[i] + ":");
    }
    if (i == 0) {
      lcd.setCursor(8, 1);
      lcd.print(" ");
    }
  }
}
void sensores() {
  for (int i = 0; i < 2; i++) {
    valores [i] = analogRead(potes[i]);
  }
  valores[0] = map(valores[0], 0, 1023, 0, 99);
  valores[1] = map(valores[1], 0, 1023, -10, 60);

  if (state == 0) {
    if (valores[0] < 10) {
      lcd.setCursor(9, 1);
      lcd.print(" " + (String)valores[0] + sensor[0] + "   ");
    } else {
      lcd.setCursor(9, 1);
      lcd.print((String)valores[0] + sensor[0] + "   ");
    }
  } else {
    if (valores[1] < 10) {
      lcd.setCursor(9, 1);
      lcd.print(" " + (String)valores[1] + sensor[1] + "   ");
    } else {
      lcd.setCursor(9, 1);
      lcd.print((String)valores[1] + sensor[1] + "   ");
    }
  }
}
void botonOne() {
  if (millis() > timeDiference + range) {
    if (millis() - timeNow < 300) {
      mode = !mode;
    }
    if (mode == 1) {
      switch (indice) {
        case 0:
          tiempo[3]++;
          if (tiempo[3] > limite[indiceMes])tiempo[3] = 1;
          break;
        case 1:
          indiceMes++;
          if (indiceMes > 11)indiceMes = 0;
          break;
        case 2:
          tiempo[4]++;
          break;
        case 3:
          tiempo[2]++;
          if (tiempo[2] > 23)tiempo[2] = 0;
          break;
        case 4:
          tiempo[1]++;
          if (tiempo[1] > 59)tiempo[1] = 0;
          break;
        default:
          indice = 0;
          break;
      }
    }
    timeNow = millis();
    timeDiference = millis();
  }
}
void botonTwo() {
  if (millis() > timeDiference + range) {
    if (millis() - timeNow < 300) {
      if (mode == 1) {
        indice++;
      }
    }
    if (mode == 1) {
      switch (indice) {
        case 0:
          tiempo[3]--;
          if (tiempo[3] < 1)tiempo[3] = limite[indiceMes];
          break;
        case 1:
          indiceMes--;
          if (indiceMes < 0)indiceMes = 11;
          break;
        case 2:
          tiempo[4]--;
          break;
        case 3:
          tiempo[2]--;
          if (tiempo[2] < 0)tiempo[2] = 23;
          break;
        case 4:
          tiempo[1]--;
          if (tiempo[1] < 0)tiempo[1] = 59;
          break;
        default:
          indice = 0;
          break;
      }
    }
    timeNow = millis();
    timeDiference = millis();
  }
}
void parpadeoFun() {
  if (mode == 1) {
    if (parpadeo == 0) {
      watch();
      sensores();
    } else {
      switch (indice) {
        case 0:
          lcd.setCursor(0, 0);
          lcd.print((char)254);
          lcd.print((char)254);
          break;
        case 1:
          lcd.setCursor(3, 0);
          lcd.print((char)254);
          lcd.print((char)254);
          lcd.print((char)254);
          lcd.print((char)254);
          lcd.print((char)254);
          lcd.print((char)254);
          lcd.print((char)254);
          lcd.print((char)254);
          lcd.print((char)254);
          break;
        case 2:
          lcd.setCursor(12, 0);
          lcd.print((char)254);
          lcd.print((char)254);
          lcd.print((char)254);
          lcd.print((char)254);
          break;
        case 3:
          lcd.setCursor(0, 1);
          lcd.print((char)254);
          lcd.print((char)254);
          break;
        case 4:
          lcd.setCursor(3, 1);
          lcd.print((char)254);
          lcd.print((char)254);
          break;
        default:
          indice = 0;
          break;
      }
    }
  }
}
ISR(TIMER1_COMPA_vect) {
  if (mode == 0) {
    tiempo[0]++;
  } else parpadeo = !parpadeo;
  state = !state;
}
void setup() {
  lcd.begin(16, 2);
  pinMode(botonUno, INPUT);
  pinMode(botonDos, INPUT);
  attachInterrupt(digitalPinToInterrupt(botonUno), botonOne, RISING);
  attachInterrupt(digitalPinToInterrupt(botonDos), botonTwo, RISING);

  cli();
  TCCR1A = 0;
  TCCR1B = 0;
  OCR1A = 15624;
  TCCR1B |= (1 << WGM12);
  TCCR1B |= (1 << CS12);
  TCCR1B |= (1 << CS10);
  TIMSK1 =  (1 << OCIE1A);
  sei();
  Serial.begin(9600);
}
void loop() {
  if (mode == 0) {
    watch();
    sensores();
  } else parpadeoFun();
}