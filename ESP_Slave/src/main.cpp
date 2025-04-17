#include <Arduino.h>
#include <BluetoothSerial.h>

#define pinLed 2

BluetoothSerial SerialBT;

// * ESP SLAVE
void setup() {
  Serial.begin(9600);
  pinMode(pinLed, OUTPUT);

  if(!SerialBT.begin("SlaveGiuliano")){
    Serial.println("Erro ao iniciar a conexão Bluetooth no modo Slave");
  }
}

void loop() {
  static bool estadoLed = false;
  static bool piscaLed = false;
  static float velocidadeFloat = 300;
  String velocidadeStr = " ";

  if(Serial.available()){
    String comando = Serial.readStringUntil('\n');
    comando.trim();
    comando.toLowerCase();
    SerialBT.println(comando);
  }

  if(SerialBT.available()){
    String resposta = SerialBT.readStringUntil('\n');
    resposta.trim();
    resposta.toLowerCase();
    Serial.printf("Comando recebido: %s\n\r", resposta);

    // Casos de controle do LED
    if (resposta.equals("liga") || resposta.equals("ligar")){
      estadoLed = true;
      piscaLed = false;
    } else if (resposta.equals("desliga") || resposta.equals("desligar")){
      estadoLed = false;
      piscaLed = false;
    } else if (resposta.equals("pisca") || resposta.equals("piscar")){
      piscaLed = true;
    } else if (resposta.startsWith("vel")){
      int tamanhoResposta = resposta.length();
      String valorString = resposta.substring(4, tamanhoResposta);
      velocidadeFloat = valorString.toFloat() * 1000;
      Serial.println("Velocidade definida: " + String(velocidadeFloat) + " ms");
    } else if (resposta.equals("rapido")){
      if (velocidadeFloat > 100) {
        velocidadeFloat -= 100;
        Serial.println("Aumentando a velocidade para: " + String(velocidadeFloat) + " ms");
      } else {
        Serial.println("Velocidade já no máximo.");
      }
    } else if (resposta.equals("devagar") || resposta.equals("lento")) {
      velocidadeFloat += 100;
      Serial.println("Diminuindo a velocidade para: " + String(velocidadeFloat) + " ms");
    } else if (resposta.equals("ajuda") || resposta.equals("help")){
      Serial.println("Comandos disponíveis:");
      Serial.println("   liga - Liga o LED");
      Serial.println("desliga - Desliga o LED");
      Serial.println("  pisca - Faz o LED piscar");
      Serial.println(" rapido - Aumenta a velocidade do piscar");
      Serial.println("devagar - Diminui a velocidade do piscar");
      Serial.println("    vel - Define a velocidade do piscar");
      Serial.println("  ajuda - Mostra os comandos disponíveis");
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