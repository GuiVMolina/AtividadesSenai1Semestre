#include <LiquidCrystal_I2C.h>

#define pinBotaoSobe 7
#define pinBotaoDesce 6

#define pinBotaoLiga 5
#define pinBotaoPosicao 4

#define ledVerde 11
#define ledVermelho 10

LiquidCrystal_I2C lcd(0x27, 16, 2);

int valorA = 0;
int valorB = 0;
bool posicao = 0; // 0 = LED A (Verde), 1 = LED B (Vermelho)

void setup() {
  // Configura os pinos como entrada ou saída
  pinMode(pinBotaoSobe, INPUT);
  pinMode(pinBotaoDesce, INPUT);
  pinMode(pinBotaoLiga, INPUT);
  pinMode(pinBotaoPosicao, INPUT);

  pinMode(ledVerde, OUTPUT);
  pinMode(ledVermelho, OUTPUT);

  // Inicializa o LCD
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);

  // Letreiro inicial
  lcd.print(">LED A: OFF 0  %");
  lcd.setCursor(0, 1);
  lcd.print(" LED B: OFF 0  %");
}

void loop() {
  // Leitura dos botões
  bool estadoBotaoSobe = digitalRead(pinBotaoSobe);
  bool estadoBotaoDesce = digitalRead(pinBotaoDesce);
  bool estadoBotaoLiga = digitalRead(pinBotaoLiga);
  bool estadoBotaoPosicao = digitalRead(pinBotaoPosicao);

  static bool estadoAnteriorBotaoSobe = 0;
  static bool estadoAnteriorBotaoDesce = 0;
  static bool estadoAnteriorBotaoLiga = 0;
  static bool estadoAnteriorBotaoPosicao = 0;

  static bool estadoLedA = 0;
  static bool estadoLedB = 0;

  // Define qual LED está sendo ajustado
  int &valor = posicao ? valorB : valorA;
  bool &estadoLed = posicao ? estadoLedB : estadoLedA;
  int led = posicao ? ledVermelho : ledVerde;

  // Botão Sobe
  if (estadoBotaoSobe && !estadoAnteriorBotaoSobe && valor < 100) {
    valor += 10;
    lcd.setCursor(12, posicao);
    lcd.print("   ");
    lcd.setCursor(12, posicao);
    lcd.print(valor);
  }

  // Botão Desce
  if (estadoBotaoDesce && !estadoAnteriorBotaoDesce && valor > 0) {
    valor -= 10;
    lcd.setCursor(12, posicao);
    lcd.print("   ");
    lcd.setCursor(12, posicao);
    lcd.print(valor);
  }

  // Botão Liga/Desliga
  if (estadoBotaoLiga && !estadoAnteriorBotaoLiga) {
    estadoLed = !estadoLed;
    digitalWrite(led, estadoLed);
    lcd.setCursor(8, posicao);
    estadoLed ? lcd.print("ON ") : lcd.print("OFF");
  }

  // Botão Posição
  if (estadoBotaoPosicao && !estadoAnteriorBotaoPosicao) {
    lcd.setCursor(0, posicao);
    lcd.print(" ");
    posicao = !posicao;
    lcd.setCursor(0, posicao);
    lcd.print(">");

    // Atualiza o display para mostrar o valor correto ao alternar LEDs
    lcd.setCursor(12, posicao);
    lcd.print("   ");
    lcd.setCursor(12, posicao);
    lcd.print(posicao ? valorB : valorA);
  }

  // Atualiza estados dos botões
  estadoAnteriorBotaoSobe = estadoBotaoSobe;
  estadoAnteriorBotaoDesce = estadoBotaoDesce;
  estadoAnteriorBotaoLiga = estadoBotaoLiga;
  estadoAnteriorBotaoPosicao = estadoBotaoPosicao;
}