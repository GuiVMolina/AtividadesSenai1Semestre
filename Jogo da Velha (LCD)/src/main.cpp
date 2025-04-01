#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

#define playerIcon 0
#define pinLed 2
#define pinButtonSobe 4
#define pinButtonDesce 5
#define pinButton 18

LiquidCrystal_I2C lcd(0x27, 20, 4);

bool jogoDaVelha[3][3] = {false};
char jogador[3][3] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
char letra[3][3] = {'a', 'b', 'c',
                    'd', 'e', 'f',
                    'g', 'h', 'i'};
char posicao = 'a';
bool vezJogador = true, jogando = false, finalizarJogo = false;
int linha = 0, coluna = 0;

void telaJogo();
void condicaoVitoria();

void setup() {
  pinMode(pinLed, OUTPUT);
  pinMode(pinButtonSobe, INPUT_PULLUP);
  pinMode(pinButtonDesce, INPUT_PULLUP);
  pinMode(pinButton, INPUT_PULLUP);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(1, 1);
  lcd.print("#Jogo da Velha");
  digitalWrite(pinLed, LOW);

  delay(1250);
  lcd.clear();
  telaJogo();
  lcd.setCursor(0, 3);
  lcd.print("Posicao: a");
}

void loop() {
  if (finalizarJogo) return;

  // Botão principal
  if (digitalRead(pinButton) == LOW) {
    delay(200);
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if (posicao == letra[i][j]) {
          coluna = j;
          linha = i;
        }
      }
    }
    if (!jogoDaVelha[linha][coluna]) {
      jogoDaVelha[linha][coluna] = true;
      jogador[linha][coluna] = vezJogador ? 'X' : 'O';
      vezJogador = !vezJogador;
      telaJogo();
      condicaoVitoria();
    } else {
      lcd.setCursor(0, 3);
      lcd.print("Posicao ocupada!");
      delay(1000);
      telaJogo();
    }
    posicao = 'a';
  }

  // Botão "Sobe"
  if (digitalRead(pinButtonSobe) == LOW) {
    delay(200);
    posicao++;
    if (posicao > 'i') posicao = 'a';
    lcd.setCursor(9, 3);
    lcd.print(" ");
    lcd.setCursor(9, 3);
    lcd.print(posicao);
  }

  // Botão "Desce"
  if (digitalRead(pinButtonDesce) == LOW) {
    delay(200);
    posicao--;
    if (posicao < 'a') posicao = 'i';
    lcd.setCursor(9, 3);
    lcd.print(" ");
    lcd.setCursor(9, 3);
    lcd.print(posicao);
  }
}

void telaJogo() {
  lcd.clear();
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      lcd.setCursor(j * 2, i);
      jogoDaVelha[i][j] ? lcd.print(jogador[i][j]) : lcd.print(letra[i][j]);
    }
  }
  lcd.setCursor(0, 3);
  lcd.print("Posicao: a");
}

void condicaoVitoria() {
  for (char player : {'X', 'O'}) {
    if ((jogador[0][0] == player && jogador[0][1] == player && jogador[0][2] == player) ||
        (jogador[1][0] == player && jogador[1][1] == player && jogador[1][2] == player) ||
        (jogador[2][0] == player && jogador[2][1] == player && jogador[2][2] == player) ||
        (jogador[0][0] == player && jogador[1][0] == player && jogador[2][0] == player) ||
        (jogador[0][1] == player && jogador[1][1] == player && jogador[2][1] == player) ||
        (jogador[0][2] == player && jogador[1][2] == player && jogador[2][2] == player) ||
        (jogador[0][0] == player && jogador[1][1] == player && jogador[2][2] == player) ||
        (jogador[2][0] == player && jogador[1][1] == player && jogador[0][2] == player)) {
      lcd.setCursor(0, 3);
      lcd.print("Vitoria do jogador ");
      lcd.print(player == 'X' ? "1" : "2");
      finalizarJogo = true;
      digitalWrite(pinLed, HIGH);
    }
  }
}