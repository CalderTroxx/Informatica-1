#define pin_sensor_temperatura A0

int numero[4] = {0, 0, 0, 0};

int lectura_sensor;
float temperatura;
float temperatura_final;
float temperatura_anterior;

unsigned long tiempo_transcurrido;
int tiempo_de_retardo = 60000;

void actualizarNumero(int valor, int cifra) {
  byte unidad[4] = {B0001000, B00000100, B00000010, B00000001};
  byte numeros[10] = {B01111110, B00001100, B10110110, B10011110, B11001100, B11011010, B11111010, B00001110, B11111110, B11011110};
  PORTB = unidad[cifra];
  PORTD = numeros[valor];
}

float fun_temperatura()
{

  if((millis() - tiempo_transcurrido) > tiempo_de_retardo){

    lectura_sensor = analogRead(pin_sensor_temperatura);
    temperatura = ((lectura_sensor * 5000.0) / 1023) / 10;
    tiempo_transcurrido = millis();
    temperatura_anterior = temperatura;
    return temperatura;

  }else{
    return temperatura_anterior;
  }
}
void setup()
{
  DDRB = B00001111;
  DDRD = B11111111;
}

void loop()
{
  temperatura_final = fun_temperatura();

  numero[3] = int(floor(temperatura_final / 100));

  numero[2] = int(floor((temperatura_final - (numero[3] * 100)) / 10));

  numero[1] = int(floor((temperatura_final - (numero[3] * 100) - (numero[2] * 10))));

  numero[0] = floor(temperatura_final * 10) - (numero[0] * 1000) - (numero[1] * 100) - (numero[2] * 10);

  for (int i = 0; i <= 3; i++) {
    actualizarNumero(numero[i], i);
    delay(1);
  }
}