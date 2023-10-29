#define pin_B1 13
#define pin_B2 12
#define pin_B3 11
#define pin_B4 10

#define pin_L1 7
#define pin_L2 6
#define pin_L3 5
#define pin_L4 4

char estado_luces[5] = "0000";

void leer_estados() {
  char *ptr = estado_luces;

  *ptr = digitalRead(pin_B1) + '0';
  *(ptr + 1) = digitalRead(pin_B2) + '0';
  *(ptr + 2) = digitalRead(pin_B3) + '0';
  *(ptr + 3) = digitalRead(pin_B4) + '0';
}

void activar_luces() {
  char *ptr = estado_luces;

  digitalWrite(pin_L1, (*ptr == '1'));
  digitalWrite(pin_L2, (*(ptr + 1) == '1'));
  digitalWrite(pin_L3, (*(ptr + 2) == '1'));
  digitalWrite(pin_L4, (*(ptr + 3) == '1'));
}

void setup() {
  pinMode(pin_B1, INPUT);
  pinMode(pin_B2, INPUT);
  pinMode(pin_B3, INPUT);
  pinMode(pin_B4, INPUT);

  pinMode(pin_L1, OUTPUT);
  pinMode(pin_L2, OUTPUT);
  pinMode(pin_L3, OUTPUT);
  pinMode(pin_L4, OUTPUT);
}

void loop() {
  leer_estados();
  activar_luces();
}
