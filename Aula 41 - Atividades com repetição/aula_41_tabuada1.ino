/*
Faça um programa que calcule a tabuada de um numero e mostre no monitor serial.
ex: 5 x 1 = 5
    5 x 2 = 10
*/

int numero = 0, resultado = 0;

void setup(){
  Serial.begin(9600);
  Serial.print("Tabuada de 1 a 10\nEscolha um numero");
  while (Serial.available()==0){}
  numero = Serial.parseInt();
  for (int i = 0; i <=10; i++){
  	Serial.print(numero);
    Serial.print(" x ");
    Serial.print(i);
    Serial.print(" = ");
    resultado = numero * i;
    Serial.println(resultado);
  }
}

void loop(){}