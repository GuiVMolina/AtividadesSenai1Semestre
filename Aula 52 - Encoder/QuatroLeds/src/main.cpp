#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <Bounce2.h>

Bounce botaoEncoder = Bounce();
LiquidCrystal_I2C lcd(0x27, 20, 4);

// Definições de pinos
#define pinLed1 15
#define pinLed2 2
#define pinLed3 4
#define pinLed4 5
#define CanalA 18
#define CanalB 19
#define pinBotao 34

const int8_t led[4] = {pinLed1, pinLed2, pinLed3, pinLed4};

// Tabela de transição
const int8_t tabelaTransicao[4][4] = {
  { 0, 1,-1, 0},
  {-1, 0, 0, 1},
  { 1, 0, 0,-1},
  { 0,-1, 1, 0}
};

// Estados do encoder
int detectarRotacaoEncoder() {
  static int estadoAnterior = 3;
  static int acumulador = 0;
  bool estadoA = digitalRead(CanalA);
  bool estadoB = digitalRead(CanalB);
  int estadoAtual = (estadoA << 1) | estadoB;
  int resultado = 0;

  if (estadoAtual != estadoAnterior) {
    acumulador += tabelaTransicao[estadoAnterior][estadoAtual];
    if (estadoAtual == 3) {
      if (acumulador == 4) resultado = 1;
      else if (acumulador == -4) resultado = -1;
      acumulador = 0;
    }
    estadoAnterior = estadoAtual;
  }

  return resultado;
}

void setup() {
  pinMode(CanalA, INPUT);
  pinMode(CanalB, INPUT);
  botaoEncoder.attach(pinBotao, INPUT);

  for (int i = 0; i < 4; i++) {
    pinMode(led[i], OUTPUT);
    // Configura PWM se necessário (ESP32)
    ledcAttachPin(led[i], i);     // Canal i
    ledcSetup(i, 5000, 8);        // 5kHz, 8-bit resolução
  }

  lcd.init();
  lcd.backlight();

  for (int i = 0; i < 4; i++) {
    lcd.setCursor(0, i);
    if (i == 0) lcd.print(">");
    else lcd.print(" ");
    lcd.print("LED ");
    lcd.print(i + 1);
    lcd.print(": 000");
  }
}

void loop() {
  int direcaoRotacao = detectarRotacaoEncoder();
  botaoEncoder.update();

  static int indiceItemMenu = 0;
  static bool modoMenuAtivo = true;
  static int intensidadeLed[4] = {0, 0, 0, 0};

  // Alterna modo
  if (botaoEncoder.fell()) {
    modoMenuAtivo = !modoMenuAtivo;
  }

  // Modo seleção do LED
  if (modoMenuAtivo) {
    if (direcaoRotacao != 0) {
      // Atualiza posição
      int novoIndice = indiceItemMenu + direcaoRotacao;
      if (novoIndice > 3) novoIndice = 0;
      else if (novoIndice < 0) novoIndice = 3;

      // Atualiza seta no display
      lcd.setCursor(0, indiceItemMenu);
      lcd.print(" ");
      lcd.setCursor(0, novoIndice);
      lcd.print(">");
      indiceItemMenu = novoIndice;
    }
  }

  // Modo ajuste de intensidade
  else if (direcaoRotacao != 0) {
    intensidadeLed[indiceItemMenu] += direcaoRotacao * 10;
    if (intensidadeLed[indiceItemMenu] > 100) intensidadeLed[indiceItemMenu] = 100;
    else if (intensidadeLed[indiceItemMenu] < 0) intensidadeLed[indiceItemMenu] = 0;

    // Atualiza PWM
    int pwmValue = map(intensidadeLed[indiceItemMenu], 0, 100, 0, 255);
    ledcWrite(indiceItemMenu, pwmValue);

    // Atualiza display
    lcd.setCursor(8, indiceItemMenu);
    lcd.print("   "); // Limpa
    lcd.setCursor(8, indiceItemMenu);
    if (intensidadeLed[indiceItemMenu] < 10) lcd.print("00");
    else if (intensidadeLed[indiceItemMenu] < 100) lcd.print("0");
    lcd.print(intensidadeLed[indiceItemMenu]);
  }
}