#include <Arduino.h>
#include "BluetoothSerial.h"

#define pinLed 2
BluetoothSerial SerialBT;
String mensagem = " ";
bool estadoLedAnterior = false;

// * ESP MASTER

void setup() {
  Serial.begin(9600);
  SerialBT.begin("ESP32_GG1", true);
  Serial.println("Esperando uma conexão Bluetooth...");
  if(SerialBT.connect("ESP32_GG2")) Serial.println("Conectado ao dispositivo Bluetooth");
  else {
    Serial.println("Falha na conexão Bluetooth");
    while (true);
  }
  pinMode(pinLed, OUTPUT);
}

void loop() {
  // * Aguarda 3 segundos
  unsigned long timeout = millis() + 3000;
  while (millis() < timeout) {
    if (SerialBT.connected()) {
      if (Serial.available()) {
        String mensagem = Serial.readStringUntil('\n');
        mensagem.trim();

        Serial.printf("Mensagem enviada: %s\n", mensagem.c_str());
        SerialBT.println(mensagem);

        if (mensagem.equalsIgnoreCase("LIGAR")) {
          digitalWrite(pinLed, HIGH);
          Serial.println("LED ligado\n\r");
        } else if (mensagem.equalsIgnoreCase("DESLIGAR")) {
          digitalWrite(pinLed, LOW);
          Serial.println("LED desligad\n\r");
        } else {
          Serial.println("Comando desconhecido");
        }
        break; // Sai do loop após uma mensagem
      }
    }
  }
}

// * ESP SLAVE

// void setup() {
//   Serial.begin(9600);
//   SerialBT.begin("ESP32_GG2", true);
//   Serial.println("Esperando uma conexao Bluetooth...");
//   if(SerialBT.connect("ESP32_GG1")) Serial.println("Conectado ao dispositivo Bluetooth");
//   else {
//     Serial.println("Falha na conexão Bluetooth");
//     while(true);
//   }
//   pinMode(pinLed, OUTPUT);
// }
 
//  void loop() {
//   if (SerialBT.available()) {
//     mensagem = SerialBT.readStringUntil('\n');
//     mensagem.trim();  // Remove espaços e quebras de linha extras
//     Serial.printf("Mensagem recebida: %s\n", mensagem.c_str());

//   if (mensagem.equalsIgnoreCase("LIGAR")) {
//     digitalWrite(pinLed, HIGH);
//     Serial.println("LED ligado");
//     } else if (mensagem.equalsIgnoreCase("DESLIGAR")) {
//       digitalWrite(pinLed, LOW);
//       Serial.println("LED desligado");
//     } else {
//       Serial.println("Comando desconhecido");
//     }
//   }
// }