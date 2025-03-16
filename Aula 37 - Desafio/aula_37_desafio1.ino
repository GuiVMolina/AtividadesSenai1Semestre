#include <LiquidCrystal_I2C.h>

#define pinBotao 11
#define valorBotao1 0
#define valorBotao2 145
#define valorBotao3 329
#define valorBotao4 505
#define valorBotao5 741

#define pinBotaoLiga 10
#define pinBotaoPosicao 9

#define ledVerde 13
#define ledVermelho 12

LiquidCrystal_I2C lcd(0x27, 16, 2);

bool estadoLedVerde = false;
bool estadoLedVermelho = false;
bool prioridadeLed = true; // true = Verde, false = Vermelho
int ultimoValorTensao = -1;

void setup() {
  // Entradas e Saídas
  pinMode(pinBotao, INPUT_PULLUP);
  pinMode(pinBotaoLiga, INPUT_PULLUP);
  pinMode(pinBotaoPosicao, INPUT_PULLUP);
  pinMode(ledVerde, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
  
  // Inicializa o LCD
  lcd.init();
  lcd.backlight();
  lcd.print("B:  Tensao: ");
  lcd.setCursor(0, 1);
  lcd.print("> G:OFF   R:OFF");
}

void loop() {
  static bool estadoAnteriorBotaoLiga = false;
  static bool estadoAnteriorBotaoPosicao = false;
  
  // **Lê o valor da tensão dos botões analógicos**
  int valorTensao = analogRead(A0);
  int novoValorTensao = -1;

  // **Verifica qual botão foi pressionado**
  if (valorTensao >= valorBotao1 * 0.9 && valorTensao <= valorBotao1 * 1.1) novoValorTensao = 1;
  else if (valorTensao >= valorBotao2 * 0.9 && valorTensao <= valorBotao2 * 1.1) novoValorTensao = 2;
  else if (valorTensao >= valorBotao3 * 0.9 && valorTensao <= valorBotao3 * 1.1) novoValorTensao = 3;
  else if (valorTensao >= valorBotao4 * 0.9 && valorTensao <= valorBotao4 * 1.1) novoValorTensao = 4;
  else if (valorTensao >= valorBotao5 * 0.9 && valorTensao <= valorBotao5 * 1.1) novoValorTensao = 5;
  else novoValorTensao = -1;

  // **Atualiza LCD somente se a tensão mudar**
  if (novoValorTensao != ultimoValorTensao) {
    lcd.setCursor(2, 0);
    if (novoValorTensao == -1) lcd.print("X");
    else lcd.print(novoValorTensao);

    lcd.setCursor(11, 0);
    lcd.print("    ");
    lcd.setCursor(11, 0);
    lcd.print(valorTensao);

    ultimoValorTensao = novoValorTensao;
  }

  // **Verifica Botão de Posição (Troca a Prioridade)**
  bool estadoBotaoPosicao = digitalRead(pinBotaoPosicao);
  if (estadoBotaoPosicao && !estadoAnteriorBotaoPosicao) {
    prioridadeLed = !prioridadeLed;

    // Atualiza a seta `>` no LCD para mostrar a prioridade
    if (prioridadeLed) {
      lcd.setCursor(0, 1);
      lcd.print(">");
      lcd.setCursor(8, 1);
      lcd.print(" ");
    } else {
      lcd.setCursor(0, 1);
      lcd.print(" ");
      lcd.setCursor(8, 1);
      lcd.print(">");
    }
  }
  estadoAnteriorBotaoPosicao = estadoBotaoPosicao;

  // **Verifica Botão Liga/Desliga**
  bool estadoBotaoLiga = digitalRead(pinBotaoLiga);
  if (estadoBotaoLiga && !estadoAnteriorBotaoLiga) {
    
    // Liga/desliga apenas o LED priorizado
    prioridadeLed ? estadoLedVerde = !estadoLedVerde
                  : estadoLedVermelho = !estadoLedVermelho;

    // Aplica os estados nos LEDs físicos
    digitalWrite(ledVerde, estadoLedVerde);
    digitalWrite(ledVermelho, estadoLedVermelho);

    // Atualiza o LCD
    lcd.setCursor(4, 1);
    lcd.print(estadoLedVerde ? "ON " : "OFF");
    lcd.setCursor(12, 1);
    lcd.print(estadoLedVermelho ? "ON " : "OFF");
  }
  estadoAnteriorBotaoLiga = estadoBotaoLiga;
}