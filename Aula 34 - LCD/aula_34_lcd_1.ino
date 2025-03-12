#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd (0x27, 16, 2); 

const int pinLedAzul = 13;
const int pinBotao = 12;

void setup(){
  pinMode(pinBotao, INPUT);
  pinMode(pinLedAzul, OUTPUT);
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
  lcd.print("Estado do LED");
}

void loop(){
  lcd.setCursor(0,1);
  bool statusBotao = digitalRead(pinBotao);
  digitalWrite(pinLedAzul, statusBotao);
  
  if (statusBotao){
    lcd.print("Led ligado   ");
  }

  if (!statusBotao){
    lcd.print("Led desligado");
  }
}