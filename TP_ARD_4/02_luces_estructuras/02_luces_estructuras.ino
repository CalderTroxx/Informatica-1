struct Habitacion {
  String nombre;
  int pin_sensor;
  int pin_interruptor;
  int pin_luz;
  bool estado_luz;
  String estado_luz_texto;
  float temperatura;
};

Habitacion habitaciones[4] = {
  { "Cocina", A0, 13, 7, 0, "OFF", 0 },
  { "Living", A1, 12, 6, 0, "OFF", 0 },
  { "Dor1", A2, 11, 5, 0, "OFF", 0 },
  { "Dor2", A3, 10, 4, 0, "OFF", 0 }
};

void leer_sensores() {
  for (int i = 0; i < 4; i++) {
    habitaciones[i].temperatura = ((analogRead(habitaciones[i].pin_sensor) * 5000.0) / 1023) / 10;
    habitaciones[i].estado_luz = digitalRead(habitaciones[i].pin_interruptor);
    digitalWrite(habitaciones[i].pin_luz, habitaciones[i].estado_luz);
  }
}

void mostrar_habitaciones() {
  leer_sensores();
  for (int i = 0; i < 4; i++) {
    if (habitaciones[i].estado_luz) habitaciones[i].estado_luz_texto = "ON";
    else habitaciones[i].estado_luz_texto = "OFF";
    Serial.println("--------------------");
    Serial.println(habitaciones[i].nombre);
    Serial.print("Estado de luz: ");
    Serial.println(habitaciones[i].estado_luz_texto);
    Serial.print("Temperatura en ");
    Serial.print(habitaciones[i].nombre);
    Serial.print(" ");
    Serial.println(habitaciones[i].temperatura);
    Serial.println("--------------------");
  }
}

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (millis() % 10000 == 0) mostrar_habitaciones();
}
