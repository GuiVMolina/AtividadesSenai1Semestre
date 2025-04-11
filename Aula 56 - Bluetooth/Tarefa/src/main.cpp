#include <Arduino.h>
#include "BluetoothSerial.h"

BluetoothSerial SerialBT;

// Define o pino do LED
const int ledPin = 2; // GPIO2 (ajuste conforme necessário)

void setup() {
  // Inicializa a comunicação serial e Bluetooth
  Serial.begin(9600);
  SerialBT.begin("ESP32_GG1");
  Serial.println("Esperando uma conexao Bluetooth...");
  if(SerialBT.connect("ESP32_GG2")) {
    Serial.println("Conectado ao dispositivo Bluetooth");
  } else {
    Serial.println("Falha na conexão Bluetooth");
    while(true);
  }

  // Configura o pino do LED como saída
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW); // Garante que o LED comece desligado
}

void loop() {
  // Verifica se há dados disponíveis no Bluetooth
  if (SerialBT.available()) {
    String mensagem = SerialBT.readStringUntil('\n'); // Lê a mensagem até o caractere '\n'
    Serial.printf("Mensagem recebida: %s \n\r", mensagem.c_str());

    // Verifica o comando recebido
    if (mensagem.equalsIgnoreCase("LIGAR")) {
      digitalWrite(ledPin, HIGH); // Liga o LED
      SerialBT.println("LED ligado");
    } else if (mensagem.equalsIgnoreCase("DESLIGAR")) {
      digitalWrite(ledPin, LOW); // Desliga o LED
      SerialBT.println("LED desligado");
    } else {
      SerialBT.println("Comando desconhecido");
    }
  }
}