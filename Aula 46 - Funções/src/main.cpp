#include <Arduino.h>
#define pinLed 22

// * Protótipo da função
void ligaLed(uint8_t);
void desligaLed(uint8_t);
float equacao(float, float, float);

void setup() {
  pinMode(pinLed, OUTPUT);
  Serial.begin(9600);
  equacao(1, 2, -15);
}

void loop() {
  ligaLed(pinLed);
  desligaLed(pinLed);
}

void ligaLed(uint8_t pin) {
  digitalWrite(pin, HIGH);
  delay(300);
}

void desligaLed(uint8_t pin) {
  digitalWrite(pin, LOW);
  delay(300);
}

float equacao(float A, float B, float C){
  float delta = pow(B, 2.0) - 4 * A * C;
  if (delta < 0) {
    Serial.println("Delta negativo");
    return 0;
  } else {
    float resultado[2];
    float X1 = (-B + sqrt(delta)) / (2 * A);
    float X2 = (-B - sqrt(delta)) / (2 * A);
    resultado[0] = X1;
    resultado[1] = X2;
    Serial.print("X¹ = ");
    Serial.println(X1);
    Serial.print("X² = ");
    Serial.println(X2);
    return resultado[2];
  }
}