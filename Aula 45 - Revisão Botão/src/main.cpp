#include <Arduino.h>
#define pinLed 22
#define pinButton 23

void setup() {
  pinMode(pinLed, OUTPUT);
  pinMode(pinButton, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  bool estadoAtualBotao = digitalRead(pinButton);
  static bool estadoAnteriorBotao = 0;
  static bool ultimaAcao = 1;
  static bool estadoLed = 0;

  const unsigned long tempoDebounce = 50;
  static unsigned long tempoAnteriorDebounce = 0;
  unsigned long tempoAtual = millis();

  static int valor = 0;

  if (estadoAtualBotao != estadoAnteriorBotao) {
    tempoAnteriorDebounce = tempoAtual;
  }

  if ((tempoAtual - tempoAnteriorDebounce) > tempoDebounce) {
    if (estadoAtualBotao != ultimaAcao) {
      ultimaAcao = estadoAtualBotao;
      if (!estadoAtualBotao) {
        estadoLed = !estadoLed;
        digitalWrite(pinLed, estadoLed);
        valor++;
        Serial.println(valor);
      }
    }
  }
  estadoAnteriorBotao = estadoAtualBotao;
}