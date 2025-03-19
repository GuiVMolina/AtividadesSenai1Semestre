#include <LiquidCrystal_I2C.h>

#define pinBotao 13
#define valorBotao1 0
#define valorBotao2 145
#define valorBotao3 329
#define valorBotao4 505
#define valorBotao5 741

#define pinBotaoLiga 12
#define pinBotaoPosicao 9

#define ledVerde 11
#define ledVermelho 10

LiquidCrystal_I2C lcd(0x27, 16, 2);

bool estadoLedVerde = false;
bool estadoLedVermelho = false;
bool prioridadeLed = true; // true = Verde, false = Vermelho
int ultimoValorTensao = -1;

void setup() {
  // Configuração dos pinos
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
  // Estado anterior dos botões
  static bool estadoAnteriorBotaoLiga = false;
  static bool estadoAnteriorBotaoPosicao = false;
  
  // Valor da tensão dos botões analógicos
  int valorTensao = analogRead(A0);
  int novoValorTensao = 0;
  static byte intensidadeLed = 0;

  // Vê qual botão foi pressionado e ajusta a intensidade
  if (valorTensao >= valorBotao1 * 0.9 && valorTensao <= valorBotao1 * 1.1) novoValorTensao = 1;
  else if (valorTensao >= valorBotao2 * 0.9 && valorTensao <= valorBotao2 * 1.1) novoValorTensao = 2;
  else if (valorTensao >= valorBotao3 * 0.9 && valorTensao <= valorBotao3 * 1.1) novoValorTensao = 3;
  else if (valorTensao >= valorBotao4 * 0.9 && valorTensao <= valorBotao4 * 1.1) novoValorTensao = 4;
  else if (valorTensao >= valorBotao5 * 0.9 && valorTensao <= valorBotao5 * 1.1) novoValorTensao = 5;
  else novoValorTensao = 0;

  // Intensidade do LED com base no botão pressionado
  intensidadeLed = map(novoValorTensao, 0, 5, 0, 255);

  // Atualiza LCD se a tensão mudar
  if (novoValorTensao != ultimoValorTensao) {
    lcd.setCursor(2, 0);
    if (novoValorTensao == 0) lcd.print("X ");
    else lcd.print(novoValorTensao);

    lcd.setCursor(11, 0);
    lcd.print("    ");
    lcd.setCursor(11, 0);
    lcd.print(valorTensao);

    ultimoValorTensao = novoValorTensao;
  }

  // Se o LED estiver ligado, aplica a nova intensidade
  if (estadoLedVerde) analogWrite(ledVerde, intensidadeLed);
  if (estadoLedVermelho) analogWrite(ledVermelho, intensidadeLed);

  // Botão de Posição
  bool estadoBotaoPosicao = digitalRead(pinBotaoPosicao);
  
  if (estadoBotaoPosicao && !estadoAnteriorBotaoPosicao) {
    prioridadeLed = !prioridadeLed;

    // Atualiza a seta `>` no LCD
    lcd.setCursor(0, 1);
    lcd.print(prioridadeLed ? ">" : " ");
    lcd.setCursor(8, 1);
    lcd.print(prioridadeLed ? " " : ">");
  }
  estadoAnteriorBotaoPosicao = estadoBotaoPosicao;

  // Botão Liga/Desliga
  bool estadoBotaoLiga = digitalRead(pinBotaoLiga);
  
  if (estadoBotaoLiga && !estadoAnteriorBotaoLiga) {
    // Liga/desliga apenas o LED priorizado
    prioridadeLed ? estadoLedVerde = !estadoLedVerde
				  : estadoLedVermelho = !estadoLedVermelho;

    // Intensidade dos LEDs
    analogWrite(ledVerde, estadoLedVerde ? intensidadeLed : 0);
    analogWrite(ledVermelho, estadoLedVermelho ? intensidadeLed : 0);

    // Atualiza o LCD
    lcd.setCursor(4, 1);
    lcd.print(estadoLedVerde ? "ON " : "OFF");
    lcd.setCursor(12, 1);
    lcd.print(estadoLedVermelho ? "ON " : "OFF");
  }
  estadoAnteriorBotaoLiga = estadoBotaoLiga;
}