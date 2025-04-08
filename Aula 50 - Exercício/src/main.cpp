#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

#define pinS1 1
#define pinS2 2

LiquidCrystal_I2C lcd(0x27, 20, 4);

void setup() {
    int valor = digitalRead(pinS1 << 1 | pinS2);
}

void loop() {
}