/*
  Autor: Guilherme Vieira Molina
  Projeto: Operadores de condição
  Descrição: Meu código em arduíno (C)
  Data: 25/02/2025
*/

float altura, peso, IMC;

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println("Qual a sua altura?");
  while (Serial.available()==0){}
  altura = Serial.parseFloat();
  Serial.println("Qual o seu peso?");
  while (Serial.available()==0){}
  peso = Serial.parseFloat();
  IMC = peso / sq(altura);
  Serial.print("Seu IMC te define como ");

  if (IMC >= 40) {
    Serial.println("Obesidade grau 3\n");
  } else if (IMC < 40 && IMC >= 35) {
    Serial.println("Obesidade grau 2\n");
  } else if (IMC < 35 && IMC >= 30) {
    Serial.println("Obesidade grau 1\n");
  } else if (IMC < 30 && IMC >= 25) {
    Serial.println("Sobrepeso\n");
  } else if (IMC < 25 && IMC >= 18.6) {
    Serial.println("Normal\n");
  } else {
    Serial.println("Abaixo do normal\n");
  }
}