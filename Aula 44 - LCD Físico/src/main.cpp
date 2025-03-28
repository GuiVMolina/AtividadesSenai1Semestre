#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define sorriso 0
#define bat1 1
#define bat2 2

LiquidCrystal_I2C lcd(0x27,20,4);

byte customChar0[] = {
  B00000,
  B00000,
  B01010,
  B00000,
  B10001,
  B01110,
  B00000,
  B00000
};

byte customChar1[] = {
  B00000,
  B01000,
  B10101,
  B10010,
  B10000,
  B01000,
  B00110,
  B00001
};

byte customChar2[] = {
  B00000,
  B00010,
  B10101,
  B01001,
  B00001,
  B00010,
  B01100,
  B10000
};


void setup() {
  lcd.init();
  lcd.setBacklight(HIGH);
  lcd.createChar(bat1, customChar1);
  lcd.createChar(bat2, customChar2);
  lcd.setCursor(0,0);
  lcd.print("Eu sou o BATMAN!");
  lcd.setCursor(17,0);
  lcd.write(bat1);
  lcd.write(bat2);
}

void loop() {
}