
#include <SD.h>
#include <TMRpcm.h>

TMRpcm tmrpcm;

const int pinSensorSonido = 13; // Este es el pin digital al que está conectado el sensor KY-037
const int chipSelect = 5; // Pin CS de la tarjeta SD

void setup() {
  Serial.begin(9600);

  // Inicializar el sensor de sonido
  pinMode(pinSensorSonido, INPUT);

  // Inicializar la tarjeta SD
  if (!SD.begin(chipSelect)) {
    Serial.println("Error al inicializar la tarjeta SD.");
    return;
  }

  // Inicializar el módulo de sonido
  tmrpcm.speakerPin = 9; // Pin de salida del módulo de sonido
}

void loop() {

}

void grabar_entrada_de_voz()
{

  // Leer el valor del sensor de sonido
  int valorSonido = digitalRead(pinSensorSonido);

  // Si se detecta sonido, grabar el audio en un archivo WAV
  if (valorSonido == HIGH) {
    Serial.println("Detectado sonido. Grabando...");
    tmrpcm.startRecording("grabacion.wav", 16000, A0); // Ajusta la tasa de muestreo según tu sensor
    delay(5000); // Grabar durante 5 segundos (ajusta según sea necesario)
    tmrpcm.stopRecording();
    Serial.println("Grabación completa.");

    // Reproducir el sonido grabado
    Serial.println("Reproduciendo grabación...");
    tmrpcm.play(".wav");
    while(tmrpcm.isPlaying());
    Serial.println("Reproducción completa.");

  }

  delay(1000); // Esperar un segundo antes de verificar nuevamente

}
