#define pin_B1 13
#define pin_B2 12
#define pin_B3 11
#define pin_B4 10

#define pin_L1 7
#define pin_L2 6
#define pin_L3 5
#define pin_L4 4

int pines_sensores[4] = { A0, A1, A2, A3 };

String habitaciones[4] = { "Cocina", "Living", "Dor1", "Dor2" };
char estado_luces[5] = "0000";
float temperaturas[4] = { 0, 0, 0, 0 };

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

void leer_sensores() {
  float *ptr = temperaturas;
  for (int i = 0; i <= 3; i++) {
    *(ptr + i) = ((analogRead(pines_sensores[i]) * 5000.0) / 1023) / 10;
    Serial.print("Temperatura de ");
    Serial.print(habitaciones[i]);
    Serial.print(": ");
    Serial.print(*(ptr + i));
    Serial.println(" C");
  }
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

  Serial.begin(9600);
}

void loop() {
  leer_estados();
  activar_luces();
  if (millis() % 10000 == 0) leer_sensores();
}