#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

int tiempo[] = {0, 0, 0, 0}; // Decimas Segundos Minutos Horas

int indice = 0;

bool state = 0;

bool mode = 0;
bool flag;

unsigned long timeDiference;
unsigned long timeNow;
int range = 200;

void watch()
{
  lcd.setCursor(2, 1);
  for (int i = 3; i >= 0; i--)
  {
    if (tiempo[i] < 10)
    {
      lcd.print("0");
      if (i == 0)
        lcd.print((String)tiempo[i] + " ");
      else
        lcd.print((String)tiempo[i] + ":");
    }
    else if (i == 0)
      lcd.print((String)tiempo[i] + " ");
    else
      lcd.print((String)tiempo[i] + ":");
  }
}

ISR(TIMER1_COMPA_vect)
{
  tiempo[0]++;

  if (tiempo[0] > 99)
  {
    tiempo[1]++;
    tiempo[0] = 0;
    if (tiempo[1] > 59)
    {
      tiempo[2]++;
      tiempo[1] = 0;
      if (tiempo[2] > 59)
      {
        tiempo[3]++;
        tiempo[2] = 0;
      }
    }
  }
}

void botonOne()
{
  if (millis() > timeDiference + range)
  {
    state = !state;
    if (state == 1)
      TIMSK1 = (1 << OCIE1A);
    if (state == 0)
      TIMSK1 = (0 << OCIE1A);

    timeDiference = millis();
  }
}

void botonTwo()
{
  if (millis() > timeDiference + range)
  {
    for (int i = 0; i < 4; i++)
      tiempo[i] = 0;
    timeDiference = millis();
  }
}

void setup()
{
  attachInterrupt(digitalPinToInterrupt(2), botonOne, RISING);
  attachInterrupt(digitalPinToInterrupt(3), botonTwo, RISING);

  lcd.begin(16, 2);
  cli();
  TCCR1A = 0;
  TCCR1B = 0;
  OCR1A = 155.25;
  TCCR1B |= (1 << WGM12);
  TCCR1B |= (1 << CS12);
  TCCR1B |= (1 << CS10);
  TIMSK1 = (0 << OCIE1A);
  sei();
}

void loop()
{
  watch();
}