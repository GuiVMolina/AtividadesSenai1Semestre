#include <LiquidCrystal_I2C.h>

#define pinBotao 11
#define valorBotao1 0
#define valorBotao2 145
#define valorBotao3 329
#define valorBotao4 505
#define valorBotao5 741

LiquidCrystal_I2C lcd (0x27, 16, 2);

void setup(){
  pinMode(pinBotao, INPUT_PULLUP);
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
  lcd.print("Botao: ");
  lcd.setCursor(0,1);
  lcd.print("Tensao: ");
}

void loop(){
  bool estadoBotao = digitalRead(pinBotao);
  int valorTensao = analogRead(A0);
  
  lcd.setCursor(7,0);
  if (estadoBotao == 1){
    lcd.print("   ");
    lcd.setCursor(7,0);
    if (valorTensao == valorBotao1) lcd.print("1");
    
    else if (valorTensao >= valorBotao2 * 0.9
             && valorTensao <= valorBotao2 * 1.1) lcd.print("2");
      
    else if (valorTensao >= valorBotao3 * 0.9
             && valorTensao <= valorBotao3 * 1.1) lcd.print("3");
      
    else if (valorTensao >= valorBotao4 * 0.9
             && valorTensao <= valorBotao4 * 1.1) lcd.print("4");
      
    else if (valorTensao >= valorBotao5 * 0.9
             && valorTensao <= valorBotao5 * 1.1) lcd.print("5");
      
    else lcd.print("N/A");
      
    lcd.setCursor(8,1);
    lcd.print(valorTensao);
      
    lcd.setCursor(8,1);
    lcd.print("    ");
    lcd.setCursor(8,1);
    lcd.print(valorTensao);
    delay(250);
  }
}