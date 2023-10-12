#include <WiFi.h>

const char* ssid = "iPhone de Santino";
const char* password = "Santienzo04";
const char* serverIP = "192.168.0.4"; // Cambia esto a la dirección IP de tu computadora

const int sensorPin = A0; // Pin del sensor de sonido KY-017

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Conectando a WiFi...");
  }
  Serial.println("Conectado a WiFi");

  delay(1000);
}

void loop() {
  int sensorValue = analogRead(sensorPin); // Leer valor del sensor de sonido
  sendToServer(sensorValue);
  delay(1000); // Esperar 1 segundo antes de enviar el siguiente valor
}

void sendToServer(int value) {
  WiFiClient client;

  if (client.connect(serverIP, 80)) {
    Serial.println("Conectado al servidor");
    client.print("GET /guardar_datos.php?valor=");
    client.print(value);
    client.println(" HTTP/1.1");
    client.println("Host: 172.20.10.3");
    client.println("Connection: close");
    client.println();
    delay(10);
  }
  client.stop();
  Serial.println("Datos enviados al servidor");
}
