const int sensorPin = 36;  // Pin del sensor de sonido KY-037, ajusta según tu conexión
int sensorValue = 0;

void setup() {
  Serial.begin(9600);  // Inicializar la comunicación serie a 9600 baudios
}

void loop() {
  // Leer el valor del sensor de sonido
  sensorValue = analogRead(sensorPin);
  
  // Mostrar el valor en el monitor serie
  Serial.print("Valor del sensor de sonido: ");
  Serial.println(sensorValue);
  
  delay(1000);  // Esperar 1 segundo antes de leer el siguiente valor
}
