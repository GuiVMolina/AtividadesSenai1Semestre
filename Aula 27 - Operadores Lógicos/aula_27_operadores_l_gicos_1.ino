/*
  Autor: Guilherme Vieira Molina
  Projeto: Operadores de condição
  Descrição: Meu código em arduíno (C)
  Data: 25/02/2025
*/

// **Comparação de valores**
// == Valores iguais
// != Valores diferentes
//  < Menor que
//  > Maior que
// <= Menor ou igual a
// >= Maior ou igual a

//if (condição)
//else if (se a condição anterior não tiver sido atingida)
//else (caso nenhuma condição tenha sido atingida)

// && e
// || ou
// !  diferente

int temp;

void setup() {
  Serial.begin(9600); // Inicia a comunicação serial
  Serial.println("Digite um valor...");
}

void loop() {
  if (Serial.available() > 0) { // Verifica se há entrada no Serial Monitor
    temp = Serial.parseInt(); // Lê o valor inserido como número inteiro
    
    Serial.print("Temperatura: "); Serial.print(temp); Serial.println(" graus");

    if (temp >= 30) {
      Serial.print("Hoje esta muito quente");
    } else if (temp < 30 && temp >= 24) {
      Serial.print("Hoje esta quente");
    } else if (temp < 24 && temp >= 18) {
      Serial.print("Hoje esta adequado");
    } else if (temp < 18 && temp >= 6) {
      Serial.print("Hoje esta frio");
    } else {
      Serial.print("Hoje esta muito frio");
    }
    
    Serial.println("\nDigite outro valor..."); // Pede outro valor
  }
}