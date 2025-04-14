#include <Arduino.h>

#define pinLed 2

void setup() {
  Serial.begin(9600);
  Serial.print("Comunicação Serial Iniciada \n");
  pinMode(pinLed, OUTPUT);
}

void loop() {
  static bool estadoLed = false;
  static bool piscaLed = false;
  static float velocidadeFloat = 300;
  String velocidadeStr = " ";

  if(Serial.available()){
    // Lê a mensagem do Serial
    String msg = Serial.readStringUntil('\n');
    msg.trim();
    msg.toLowerCase();

    // Casos de controle do LED
    if (msg.equals("liga") || msg.equals("ligar")){
      estadoLed = true;
      piscaLed = false;
    } else if (msg.equals("desliga") || msg.equals("desligar")){
      estadoLed = false;
      piscaLed = false;
    } else if (msg.equals("pisca") || msg.equals("piscar")){
      piscaLed = true;
    } else if (msg.equals("velocidade") || msg.equals("vel")){
      Serial.print("Digite a velocidade em segundos: ");
      while (Serial.available() == 0) {}
      velocidadeStr = Serial.readStringUntil('\n');
      velocidadeStr.trim();
      velocidadeFloat = velocidadeStr.toFloat() * 1000; // Converte para milissegundos
      Serial.println("Velocidade definida: " + String(velocidadeFloat) + " ms");
    } else if (msg.equals("rapido")){
      if (velocidadeFloat > 100) {
        velocidadeFloat -= 100;
        Serial.println("Aumentando a velocidade para: " + String(velocidadeFloat) + " ms");
      } else {
        Serial.println("Velocidade já no máximo.");
      }
    } else if (msg.equals("devagar")) {
      velocidadeFloat += 100;
      Serial.println("Diminuindo a velocidade para: " + String(velocidadeFloat) + " ms");
    } else if (msg.equals("ajuda") || msg.equals("help")){
      Serial.println("Comandos disponíveis:");
      Serial.println("      liga - Liga o LED");
      Serial.println("   desliga - Desliga o LED");
      Serial.println("     pisca - Faz o LED piscar");
      Serial.println("    rapido - Aumenta a velocidade do piscar");
      Serial.println("   devagar - Diminui a velocidade do piscar");
      Serial.println("velocidade - Define a velocidade do piscar");
      Serial.println("     ajuda - Mostra os comandos disponíveis");
    } else {
      Serial.println("Comando inválido. Digite 'ajuda' para ver os comandos disponíveis.");
    }
  }

  // Função piscaLed
  unsigned long tempoAtual = millis();
  static unsigned long tempoInicial = 0;
  if (piscaLed) {
    if (tempoAtual - tempoInicial > velocidadeFloat) {
      estadoLed = !estadoLed;
      tempoInicial = tempoAtual;
    }
  }

  // Atualiza o estado do LED
  digitalWrite(pinLed, estadoLed);
}