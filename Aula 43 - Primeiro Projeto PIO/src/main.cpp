#include <Arduino.h>

#define pinLed 2
#define pinButton 0

void setup() {
  pinMode(pinLed, OUTPUT);
  pinMode(pinButton, INPUT_PULLUP);
}

void loop() {
  bool botao = digitalRead(pinButton);
  if(!botao){
    digitalWrite(pinLed, HIGH);
    delay(300);
    digitalWrite(pinLed, LOW);
    delay(300);
  }
}