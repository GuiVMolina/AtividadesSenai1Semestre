#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd (0x27, 16, 2); 

#define pinLedA 13
#define pinBotaoA 12

#define pinLedB 11
#define pinBotaoB 10

#define pinLedC 9
#define pinBotaoC 8

#define pinLedD 7
#define pinBotaoD 6

void setup(){
  //Entradas e saídas
  pinMode(pinBotaoA, INPUT);
  pinMode(pinBotaoB, INPUT);
  pinMode(pinBotaoC, INPUT);
  pinMode(pinBotaoD, INPUT);
  
  pinMode(pinLedA, OUTPUT);
  pinMode(pinLedB, OUTPUT);
  pinMode(pinLedC, OUTPUT);
  pinMode(pinLedD, OUTPUT);
  
  //Inicializadores
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
  
  //Letreiro
  lcd.print("L-A:OFF");
  lcd.setCursor(0,1);
  lcd.print("L-B:OFF");
  lcd.setCursor(8,0);
  lcd.print("L-C:OFF");
  lcd.setCursor(8,1);
  lcd.print("L-D:OFF");
}

void loop(){
  //Led A
  bool estadoBotaoA = digitalRead(pinBotaoA);
  static bool estadoAnteriorBotaoA = 0;
  static bool estadoLedA = 0;
  
  //Led B
  bool estadoBotaoB = digitalRead(pinBotaoB);
  static bool estadoAnteriorBotaoB = 0;
  static bool estadoLedB = 0;
  
  //Led C
  bool estadoBotaoC = digitalRead(pinBotaoC);
  static bool estadoAnteriorBotaoC = 0;
  static bool estadoLedC = 0;
  
  //Led D
  bool estadoBotaoD = digitalRead(pinBotaoD);
  static bool estadoAnteriorBotaoD = 0;
  static bool estadoLedD = 0;
  
  //Liga/desliga Led
  digitalWrite(pinLedA, estadoLedA);
  digitalWrite(pinLedB, estadoLedB);
  digitalWrite(pinLedC, estadoLedC);
  digitalWrite(pinLedD, estadoLedD);
  
  //Botão A
  if (estadoBotaoA && !estadoAnteriorBotaoA){
    estadoLedA = !estadoLedA;
    digitalWrite(pinLedA, estadoLedA);
    
    lcd.setCursor(4,0);
    estadoLedA ? lcd.print("ON ") : lcd.print("OFF");
  }
  
  //Botão B
  if (estadoBotaoB && !estadoAnteriorBotaoB){
    estadoLedB = !estadoLedB;
    digitalWrite(pinLedB, estadoLedB);
    
    lcd.setCursor(4,1);
    estadoLedB ? lcd.print("ON ") : lcd.print("OFF");
  }
  
  //Botão C
  if (estadoBotaoC && !estadoAnteriorBotaoC){
    estadoLedC = !estadoLedC;
    digitalWrite(pinLedC, estadoLedC);
    
    lcd.setCursor(12,0);
    estadoLedC ? lcd.print("ON ") : lcd.print("OFF");
  }
  
  //Botão D
  if (estadoBotaoD && !estadoAnteriorBotaoD){
    estadoLedD = !estadoLedD;
    digitalWrite(pinLedD, estadoLedD);
    
    lcd.setCursor(12,1);
    estadoLedD ? lcd.print("ON ") : lcd.print("OFF");
  }
  
  //Reseta estado anterior do botão
  estadoAnteriorBotaoA = estadoBotaoA;
  estadoAnteriorBotaoB = estadoBotaoB;
  estadoAnteriorBotaoC = estadoBotaoC;
  estadoAnteriorBotaoD = estadoBotaoD;
}