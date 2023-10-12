
int numero[4] = {0, 0, 0, 0};

#define pin_boton_descender 12
#define pin_boton_ascender 13

int lectura_actual_boton_descender = 0;
int estado_boton_descender;
int estado_anterior_boton_descender = 0;

unsigned long tiempo_transcurrido_boton_descender = 0;
unsigned long tiempo_de_retardo_boton_descender = 50; //millisegundos
unsigned long tiempo_desde_la_ultima_lectura_boton_descender = 0;

int lectura_actual_boton_ascender = 0;
int estado_boton_ascender;
int estado_anterior_boton_ascender = 0;

unsigned long tiempo_transcurrido_boton_ascender = 0;
unsigned long tiempo_de_retardo_boton_ascender = 50; //millisegundos
unsigned long tiempo_desde_la_ultima_lectura_boton_ascender = 0;

void actualizarNumero(int valor, int cifra) {
  byte unidad[4] = {B0001000, B00000100, B00000010, B00000001};
  //byte numeros[10] = {B00111110, B00000110, B01011011, B01001111, B01100110, B01101101, B01111101, B00000111, B01111111, B01100111};
  byte numeros[10] = {B01111110, B00001100, B10110110, B10011110, B11001100, B11011010, B11111010, B00001110, B11111110, B11001110};
  PORTB = unidad[cifra];
  PORTD = numeros[valor];
}

bool leer_boton_descender()
{
  //Lectura del pin
  lectura_actual_boton_descender = digitalRead(pin_boton_descender);

    //Si el valor leido es distinto a otro leido instantes antes...
    if(lectura_actual_boton_descender != estado_anterior_boton_descender) tiempo_transcurrido_boton_descender = millis();

    tiempo_desde_la_ultima_lectura_boton_descender = millis() - tiempo_transcurrido_boton_descender; //Delta tiempo, Final - Inicial

    if(tiempo_desde_la_ultima_lectura_boton_descender > tiempo_de_retardo_boton_descender){
      //Si el valor leido es 1 (+5V)...
      if(lectura_actual_boton_descender != estado_boton_descender){
        estado_boton_descender = lectura_actual_boton_descender;
        if(estado_boton_descender == 1) return 1;
      }
    }
  //Se igualan las variables para volver a empezar el ciclo.
  estado_anterior_boton_descender = lectura_actual_boton_descender;
  return 0;
  
}

bool leer_boton_ascender()
{
  //Lectura del pin
  lectura_actual_boton_ascender = digitalRead(pin_boton_ascender);
  
  //Si el valor leido es distinto a otro leido instantes antes...
  if(lectura_actual_boton_ascender != estado_anterior_boton_ascender) tiempo_transcurrido_boton_ascender = millis();
	
    tiempo_desde_la_ultima_lectura_boton_ascender = millis() - tiempo_transcurrido_boton_ascender; //Delta tiempo, Final - Inicial

    if(tiempo_desde_la_ultima_lectura_boton_ascender > tiempo_de_retardo_boton_ascender){
      //Serial.println(lectura_actual_boton_ascender);
      //Si el valor leido es 1 (+5V)...
      if(lectura_actual_boton_ascender != estado_boton_ascender){
        estado_boton_ascender = lectura_actual_boton_ascender;
        //Serial.println(estado_boton_ascender);
        if(estado_boton_ascender == 1) return 1;
      }
    }
  //Se igualan las variables para volver a empezar el ciclo.
  estado_anterior_boton_ascender = lectura_actual_boton_ascender;
  return 0;
}

void contador()
{
  if (leer_boton_ascender())
  {
    //Serial.println("Boton Ascender");
    numero[0]++;
    if (numero[0] > 9) {
      numero[0] = 0;
      numero[1]++;
    }
    if (numero[1] > 9) {
      numero[1] = 0;
      numero[2]++;
    }
    if (numero[2] > 9) {
      numero[2] = 0;
      numero[3]++;
    }
    if (numero[3] > 9) {
      numero[0] = 0;
      numero[1] = 0;
      numero[2] = 0;
      numero[3] = 0;
    }
  }

  if (leer_boton_descender())
  {
    Serial.println("Boton Descender");
    numero[0]--;
    if (numero[0] < 0) {
      numero[0] = 9;
      numero[1]--;
    }
    if (numero[1] < 0) {
      numero[1] = 9;
      numero[2]--;
    }
    if (numero[2] < 0) {
      numero[2] = 9;
      numero[3]--;
    }
    if (numero[3] < 0) {
      numero[0] = 9;
      numero[1] = 9;
      numero[2] = 9;
      numero[3] = 9;
    }
  }
}

void setup()
{
  pinMode(pin_boton_ascender, INPUT);
  pinMode(pin_boton_descender, INPUT);
  pinMode(0, OUTPUT);
  DDRB = B00001111;
  DDRD = B11111111;

  //Serial.begin(9600);
}

void loop()
{
  contador();
  for (int i = 0; i <= 3; i++) {
    actualizarNumero(numero[i], i);
    delay(1);
  }
}