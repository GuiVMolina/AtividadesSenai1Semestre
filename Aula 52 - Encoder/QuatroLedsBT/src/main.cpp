#include <Arduino.h>
#include "BluetoothSerial.h"

#define pinLed 2
#define pinLed1 4
#define pinLed2 18
#define pinLed3 19
#define pinLed4 21

// Cria um objeto Bluetooth Serial
BluetoothSerial SerialBT;

// Array de pinos para os LEDs
const u_int8_t led[4] = {pinLed1, pinLed2, pinLed3, pinLed4};

void setup() {
    // Nome
    SerialBT.begin("ESP32_GuilhermeVM");
    Serial.begin(9600);
    pinMode(pinLed, OUTPUT);
    pinMode(pinLed1, OUTPUT);
    pinMode(pinLed2, OUTPUT);
    pinMode(pinLed3, OUTPUT);
    pinMode(pinLed4, OUTPUT);
}

void loop() {
  static int numeroLed = 0;
  static char input = 0;
  static bool proximoPasso = false;

  while (SerialBT.available()) {
    SerialBT.println("Escolha um LED (1-4):");
    input = SerialBT.read();
    
    // Converte de ASCII para índice (0-3)
    numeroLed = input - '1';

    if (numeroLed < 0 || numeroLed > 3) SerialBT.println("Número inválido. Use 1-4 para escolher o LED.");
    else proximoPasso = true;
  }

  if (proximoPasso == true){
    String intensidadeString = "";
    while (SerialBT.available()) {
      SerialBT.println("Escolha a intensidade (0-100%):");
      char input = SerialBT.read();
      if (input >= '0' && input <= '9') intensidadeString += input;
      else if (input == '\n' || input == '\r') break;
    }

    // Converte para inteiro
    int intensidade = intensidadeString.toInt();
    if (intensidade < 0 || intensidade > 100) {
      SerialBT.println("Intensidade inválida. Use 0-100 para escolher a intensidade.");
    } else {
      // map() da intensidade
      int intensidadeLed = map(intensidade, 0, 100, 0, 255);
      analogWrite(numeroLed, intensidadeLed);
      SerialBT.println("LED configurado com sucesso!");
      proximoPasso = false;
    }
  }
}