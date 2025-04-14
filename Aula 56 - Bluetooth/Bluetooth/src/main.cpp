#include <Arduino.h>
#include "BluetoothSerial.h"

#define pinLed 2
BluetoothSerial SerialBT;
String mensagem = " ";

// * ESP MASTER

void setup() {
  Serial.begin(9600);
  SerialBT.begin("ESP32_MasterGG", true);

  if(SerialBT.connect("ESP32_GG")) {
    Serial.println("Conectado ao ESP32_GG");
  } else {
    Serial.println("Falha ao conectar ao ESP32_GG");
    while(true); // * Trava o ESP
  }
}

void loop(){
  // * Aguarda 3 segundos
  unsigned long timeout = millis() + 3000;
  while(millis() < timeout) {
    if(SerialBT.available()) {
      mensagem = SerialBT.readStringUntil('\r');
      Serial.printf("Mensagem enviada: %s", mensagem);
      break; // * Sai do loop
    }
  }
}

// * ESP SLAVE

// void setup() {
//   Serial.begin(9600);
//   SerialBT.begin("ESP32_GG");
//   Serial.println("Esperando uma conexão Bluetooth...");
// }

// void loop() {
//   if(SerialBT.available()) {
//     String mensagem = SerialBT.readStringUntil('\n');
//     Serial.printf("Mensagem recebida: %s", mensagem);
//     if(mensagem.equals("ping")){
//       SerialBT.println("pong\n\r");
//     }
//   }
// }