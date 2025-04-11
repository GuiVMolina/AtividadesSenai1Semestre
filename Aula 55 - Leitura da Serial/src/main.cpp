#include <Arduino.h>
#include "BluetoothSerial.h"

#define pinLed 2

BluetoothSerial SerialBT; // Cria um objeto Bluetooth Serial

String palavra;

void setup() {
    Serial.begin(9600);
    SerialBT.begin("ESP32_GuilhermeVM"); // Nome do dispositivo Bluetooth
    pinMode(pinLed, OUTPUT);
    SerialBT.println("Digite algo no monitor serial:");
}

void loop() {
    while(SerialBT.available()) {
        char caractere = SerialBT.read();

        if(caractere == '\n') {
            SerialBT.println(palavra);

            // palavra.equalsIgnoreCase("ligar"), ignora maiúsculas e minúsculas
            if (palavra.equals("ligar")){
                digitalWrite(pinLed, HIGH); // Liga o LED
                SerialBT.println("LED ligado");

            } else if (palavra.equals("desligar")){
                digitalWrite(pinLed, LOW); // Desliga o LED
                SerialBT.println("LED desligado");

            } else {
                SerialBT.println("Comando não reconhecido. Use 'ligar' ou 'desligar'");
            }
            palavra = ""; // Limpa a palavra após imprimir

        } else if (caractere != '\r') {
            palavra += caractere; //Palavra concatena com o caractere
        }

        // if(caractere == 'l' || caractere == 'L') {
        //     digitalWrite(pinLed, HIGH); // Liga o LED
        //     Serial.println("LED ligado");
        // } else if (caractere == 'd' || caractere == 'D'){
        //     digitalWrite(pinLed, LOW); // Desliga o LED
        //     Serial.println("LED desligado");
        // } else {
        //     Serial.println("Caractere inválido. Use 'l'/'L' para ligar ou 'd'/'D' para desligar o LED.");
        // }
        // Serial.printf("Você digitou: %c \n\r", caractere);
    }
}