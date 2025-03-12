#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd (0x27, 16, 2); 

#define pinLedA 13
#define pinBotaoA 12
#define pinLedB 11
#define pinBotaoB 10

void setup(){
  pinMode(pinBotaoA, INPUT);
  pinMode(pinLedA, OUTPUT);
  pinMode(pinBotaoB, INPUT);
  pinMode(pinLedB, OUTPUT);
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
  lcd.print("Estado LED A ");
  lcd.setCursor(0,1);
  lcd.print("Estado LED B ");
}

void loop(){
  bool estadoBotaoA = digitalRead(pinBotaoA);
  static bool estadoAnteriorBotaoA = 0;
  static bool estadoLedA = 0;
  
  bool estadoBotaoB = digitalRead(pinBotaoB);
  static bool estadoAnteriorBotaoB = 0;
  static bool estadoLedB = 0;
  
  digitalWrite(pinLedA, estadoLedA);
  digitalWrite(pinLedB, estadoLedB);
  
  if (estadoBotaoA && !estadoAnteriorBotaoA){
    estadoLedA = !estadoLedA;
    digitalWrite(pinLedA, estadoLedA);
    
    lcd.setCursor(13,0);
    if (estadoLedA) lcd.print("ON ");
    else lcd.print("OFF ");
  }
  
  if (estadoBotaoB && !estadoAnteriorBotaoB){
    estadoLedB = !estadoLedB;
    digitalWrite(pinLedB, estadoLedB);
    
    lcd.setCursor(13,1);
    if (estadoLedB) lcd.print("ON ");
    else lcd.print("OFF ");
  }
  
  estadoAnteriorBotaoA = estadoBotaoA;
  estadoAnteriorBotaoB = estadoBotaoB;
}