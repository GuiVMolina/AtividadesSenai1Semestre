#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);

#define CanalA 18
#define CanalB 19

const int8_t tabelaTransicao[4][4] = {
/*
	+1 = Horário
	 0 = Parado
	-1 = Anti-horário
*/

/* 		  0  1  2  3 
	 0 	{00,01,02,03},
	 1 	{10,11,12,13},
	 2 	{20,21,22,23},
	 3 	{30,31,32,33}
*/

	{ 0, 1,-1, 0},
	{-1, 0, 0, 1},
	{ 1, 0, 0,-1},
	{ 0,-1, 1, 0}
};

void setup() {
  pinMode(CanalA, INPUT);
  pinMode(CanalB, INPUT);
  lcd.init();
  lcd.backlight();
  lcd.print("Contador Encoder");
  lcd.setCursor(0, 1);
  lcd.print("Posicao:");
  lcd.setCursor(0, 2);
  lcd.print("Direcao:");
}

void loop() {
  bool leituraCanalA = digitalRead(CanalA);
  bool leituraCanalB = digitalRead(CanalB);
  int estadoAtualEncoder = ((leituraCanalA << 1) | leituraCanalB);
  static int estadoAnteriorEncoder = 3;
  static int posicao = 0;
  int direcao = 0;

  if (estadoAnteriorEncoder != estadoAtualEncoder) {
    direcao = tabelaTransicao[estadoAnteriorEncoder][estadoAtualEncoder];

    if (estadoAtualEncoder > 3) {
      estadoAtualEncoder = 0;
    }
    else if (estadoAtualEncoder < 0) {
      estadoAtualEncoder = 3;
    }
    
    posicao += direcao;

    lcd.setCursor(8, 1);
    lcd.print("           ");
    lcd.setCursor(8, 1); 
    lcd.print(posicao);

    if (direcao != 0) {
      lcd.setCursor(8, 2);
      if (direcao == 1) {
        lcd.print("Horario     ");
      } else if (direcao == -1) {
        lcd.print("AntiHorario ");
      }
    }
    else {
      lcd.setCursor(8, 2);
      lcd.print("Parado      ");
    }
    estadoAnteriorEncoder = estadoAtualEncoder;
  }
  delay(20);
}