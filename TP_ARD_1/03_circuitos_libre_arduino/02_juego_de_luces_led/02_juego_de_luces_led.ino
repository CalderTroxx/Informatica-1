int botonUno = 2;
int botonDos = 3;
volatile int contador;
const int range = 110;
long timeDiference;

void contadorPlusA(){
  if(millis() > timeDiference + range){ //La condicion no permite que se entre al if si no paso el tiempo indicado en la variable "range"
    contador++;                           //contador sube en 1
    timeDiference = millis();             //Se guarda el valor de la cuenta que hace la funcion "millis"
  }
}
void contadorPlusB(){
  if(millis() > timeDiference + range){ //Si la suma 
    contador--;
    timeDiference = millis();
  }
}
void ningunEfecto(){
  for(int i = 13; i > 3; i--){
    if(contador != 0) return;
    digitalWrite(i,LOW);
  }
}
void autoFantastico(){
  for(int i = 13; i > 3; i--){
    if(contador != 1) return;
    digitalWrite(i,HIGH);
    delay(20);
    digitalWrite(i,LOW);
    delay(20);
  }
  for(int i = 13; i > 3; i--){
    if(contador != 1) return;
    digitalWrite(i,HIGH);
    delay(20);
    digitalWrite(i,LOW);
    delay(20);
  }
}
void barrido(){  
  for(int i = 13; i > 3; i--){
    if(contador != 2) return;
    digitalWrite(i, HIGH);
    delay(50);
  } 
  for(int i = 13; i > 3; i--){
    if(contador != 2) return;
    digitalWrite(i, LOW);
    delay(50);
  }
}
void mitad(){
  for(int i = 13; i > 8; i--){
    if(contador != 3) return;
    digitalWrite(i, HIGH);
    digitalWrite(i-5, LOW);
  }delay(150);
  for(int i = 13; i > 8; i--){
    if(contador != 3) return;
    digitalWrite(i, LOW);
    digitalWrite(i-5, HIGH);
  }delay(150);
}
void barridoPWM(){
  for (int i = 13; i > 3; i--){
    if(contador != 4) return;
    for(int j = 0; j < 256; j++){
      analogWrite(i, j);
      delay(0.5);
    }
  }
  for (int i = 13; i > 3; i--){
    if(contador != 4) return;
    for(int j = 255; j >= 0 ; j--){
      analogWrite(i, j);
      delay(0.5);
    }
  }
}
void parImpar(){
  for(int i = 13; i > 3 ; i = i-2){
    if(contador != 5) return;
    digitalWrite(i,HIGH);
    digitalWrite(i-1,LOW);
  }delay(150);
  for(int i = 13; i > 3 ; i = i-2){
    if(contador != 5) return;
    digitalWrite(i,LOW);
    digitalWrite(i-1,HIGH);
  }delay(150);
}
void Random(){
    if(contador != 6) return;
    int num = random(4,14);
    digitalWrite(num, HIGH);
    delay(100);
    digitalWrite(num, LOW);
    Serial.println(num);
}

void efectos(){
  switch (contador){
   case 0:
   ningunEfecto();
    break;
   case 1:
    autoFantastico();
    break;
   case 2:
    barrido();
    break;
   case 3:
    mitad();
    break;
   case 4:
    barridoPWM();
    break;
   case 5:
    parImpar();
    break;
   case 6:
    Random();
    break;
   default:
    contador = 0;
    break;
  }
}

void setup() {
  for(int i = 4; i < 14 ; i++){
    pinMode(i, OUTPUT);
  }
  attachInterrupt(digitalPinToInterrupt(botonUno),contadorPlusA,RISING);
  attachInterrupt(digitalPinToInterrupt(botonDos),contadorPlusB,RISING);
}
void loop(){
  efectos();
}
