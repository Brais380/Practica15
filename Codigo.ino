/********************************************************************
Programación para simular el comprotamento de la penultima práctica 
de puertas logicas inclullendo un pulsador/interruptor en los pines 
10,9,8 para forzar 0 o 1 :
La salida se activa en función de tres entradas controladas por 
interruptores, de manera que cumpla la función logica. 

F = not a x not b x c + a x not b x c + a x b x not c

Entardas pin 10,9,8 (digitales)
Salida pin 11 (digital)

Autor: Brais Rey Mirón
Fecha: 16 / Enero / 2025
********************************************************************/

#define A 10
#define B  9
#define C  8
#define RELE 11

bool a = 0;// Definimos a,b,c como datos booleanos
bool b = 0;
bool c = 0;

void setup() {
  pinMode(A, INPUT);// Definimos que funcion tiene cada pin INPUT / OUTPUT
  pinMode(B, INPUT);
  pinMode(C, INPUT);
  pinMode(RELE, OUTPUT);
}

void loop() {
  a = digitalRead(A);// Leemos y guardamos los estados de las entradas 
  b = digitalRead(B);
  c = digitalRead(C);
  bool condicion = !a && !b && c || a && !b && c || a && b && !c ;//Se añade un balor booleano encargado de establecer las condiciones de activaciòn (Usando Minterms) 
  if(condicion) {// Cuando se cumplan las condiciones:
    digitalWrite(RELE,HIGH);// Activa el RELE
  } 
  else {// En caso de que no se cumplan las condiciones:
    digitalWrite(RELE, LOW);// Desactiva el RELE
  }
}
