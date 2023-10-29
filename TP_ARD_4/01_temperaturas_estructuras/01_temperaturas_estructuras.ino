struct Habitacion {
  String nombre;
  int pin_sensor;
  float temperatura;
};

Habitacion habitaciones[4] = {
  { "Cocina", A0, 0 },
  { "Living", A1, 0 },
  { "Dor1", A2, 0 },
  { "Dor2", A3, 0 }
};

void leer_sensores() {
  for (int i = 0; i < 4; i++) {
    habitaciones[i].temperatura = ((analogRead(habitaciones[i].pin_sensor) * 5000.0) / 1023) / 10;
    Serial.print("Temperatura de ");
    Serial.print(habitaciones[i].nombre);
    Serial.print(": ");
    Serial.print(habitaciones[i].temperatura);
    Serial.println(" C");
  }
}

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (millis() % 10000 == 0) leer_sensores();
}
