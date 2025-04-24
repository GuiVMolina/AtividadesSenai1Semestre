#include <Arduino.h>
#include "RoboCore_MMA8452Q.h"
#include <FastLED.h>
#include <LiquidCrystal_I2C.h>

#define pinLed 5
#define pinBotao 23
#define NUM_LEDS 25

CRGB leds[NUM_LEDS]; // Guarda as cores de cada LED
MMA8452Q acelerometro;
LiquidCrystal_I2C lcd(0x27, 20, 4);

// Cores padrão
uint8_t r = 16, g = 16, b = 16;

// Controle de última seta
String ultimoComandoSeta = "";

// Protótipos
void reaplicarUltimaSeta();
void sorriso();
void setaEsquerda(uint8_t r, uint8_t g, uint8_t b);
void setaDireita(uint8_t r, uint8_t g, uint8_t b);
void setaFrente(uint8_t r, uint8_t g, uint8_t b);
void setaTras(uint8_t r, uint8_t g, uint8_t b);
void setaFrenteEsquerda(uint8_t r, uint8_t g, uint8_t b);
void setaFrenteDireita(uint8_t r, uint8_t g, uint8_t b);
void setaTrasEsquerda(uint8_t r, uint8_t g, uint8_t b);
void setaTrasDireita(uint8_t r, uint8_t g, uint8_t b);

void setup()
{
  Serial.begin(115200);
  acelerometro.init();
  FastLED.addLeds<WS2812, pinLed, GRB>(leds, NUM_LEDS);
  pinMode(pinBotao, INPUT_PULLUP);
  sorriso();

  lcd.init();
  lcd.backlight();
  lcd.print("Projetinho");
  lcd.setCursor(0, 1);
  lcd.print("Cor:");
  lcd.setCursor(0, 2);
  lcd.print("Direcao:");
}

void loop()
{
  acelerometro.read();

  int horizontal = 0;
  int vertical = 0;

  if (acelerometro.x > 0.2)
    horizontal = 1;
  else if (acelerometro.x < -0.2)
    horizontal = 2;

  if (acelerometro.y > 0.2)
    vertical = 1;
  else if (acelerometro.y < -0.2)
    vertical = 2;

  // Direção
  if (horizontal == 1 && vertical == 1)
  {
    Serial.println("TRAS ESQUERDA");
    setaTrasEsquerda(r, g, b);
    ultimoComandoSeta = "baixo esquerda";
  }
  else if (horizontal == 1 && vertical == 2)
  {
    Serial.println("FRENTE ESQUERDA");
    setaFrenteEsquerda(r, g, b);
    ultimoComandoSeta = "cima esquerda";
  }
  else if (horizontal == 2 && vertical == 1)
  {
    Serial.println("TRAS DIREITA");
    setaTrasDireita(r, g, b);
    ultimoComandoSeta = "baixo direita";
  }
  else if (horizontal == 2 && vertical == 2)
  {
    Serial.println("FRENTE DIREITA");
    setaFrenteDireita(r, g, b);
    ultimoComandoSeta = "cima direita";
  }
  else if (horizontal == 1 && vertical == 0)
  {
    Serial.println("ESQUERDA");
    setaEsquerda(r, g, b);
    ultimoComandoSeta = "esquerda";
  }
  else if (horizontal == 2 && vertical == 0)
  {
    Serial.println("DIREITA");
    setaDireita(r, g, b);
    ultimoComandoSeta = "direita";
  }
  else if (horizontal == 0 && vertical == 1)
  {
    Serial.println("TRAS");
    setaTras(r, g, b);
    ultimoComandoSeta = "baixo";
  }
  else if (horizontal == 0 && vertical == 2)
  {
    Serial.println("FRENTE");
    setaFrente(r, g, b);
    ultimoComandoSeta = "cima";
  }

  // Movimento no eixo Z
  if (acelerometro.z > 0.2)
  {
    Serial.println("PARA CIMA");
    lcd.setCursor(9, 2);
    lcd.print("Cima ");
  }
  else if (acelerometro.z < -0.2)
  {
    Serial.println("PARA BAIXO");
    lcd.setCursor(9, 2);
    lcd.print("Baixo");
  }

  // Troca de cor com botão
  static unsigned long tempoAnteriorDebounce = 0;
  const unsigned long tempoDebounce = 50;
  static bool estadoAnteriorBotao = HIGH;
  static bool ultimaAcao = HIGH;
  static int cont = 0;

  unsigned long tempoAtual = millis();
  bool estadoAtualBotao = digitalRead(pinBotao);

  if (estadoAtualBotao != estadoAnteriorBotao)
  {
    tempoAnteriorDebounce = tempoAtual;
  }

  if ((tempoAtual - tempoAnteriorDebounce) > tempoDebounce)
  {
    if (estadoAtualBotao != ultimaAcao)
    {
      ultimaAcao = estadoAtualBotao;
      if (!estadoAtualBotao)
      {
        switch (cont)
        {
        case 0:
          lcd.setCursor(5, 1);
          lcd.print("Vermelho");
          r = 32;
          g = 0;
          b = 0;
          cont++;
          break;
        case 1:
          lcd.setCursor(5, 1);
          lcd.print("Verde   ");
          r = 0;
          g = 32;
          b = 0;
          cont++;
          break;
        case 2:
          lcd.setCursor(5, 1);
          lcd.print("Azul    ");
          r = 0;
          g = 0;
          b = 32;
          cont++;
          break;
        case 3:
          lcd.setCursor(5, 1);
          lcd.print("Branco  ");
          r = 32;
          g = 32;
          b = 32;
          cont++;
          break;
        case 4:
          lcd.setCursor(5, 1);
          lcd.print("Laranja ");
          r = 32;
          g = 16;
          b = 0;
          cont++;
          break;
        case 5:
          lcd.setCursor(5, 1);
          lcd.print("Amarelo ");
          r = 32;
          g = 32;
          b = 0;
          cont++;
          break;
        case 6:
          lcd.setCursor(5, 1);
          lcd.print("Roxo    ");
          r = 16;
          g = 0;
          b = 32;
          cont++;
          break;
        case 7:
          lcd.setCursor(5, 1);
          lcd.print("Ciano   ");
          r = 0;
          g = 32;
          b = 32;
          cont++;
          break;
        case 8:
          cont = 0;
          break;
        }
        reaplicarUltimaSeta();
      }
    }
  }
  estadoAnteriorBotao = estadoAtualBotao;
}

// Reaplica a última seta com a nova cor
void reaplicarUltimaSeta()
{
  if (ultimoComandoSeta == "esquerda")
    setaEsquerda(r, g, b);
  else if (ultimoComandoSeta == "direita")
    setaDireita(r, g, b);
  else if (ultimoComandoSeta == "cima")
    setaFrente(r, g, b);
  else if (ultimoComandoSeta == "baixo")
    setaTras(r, g, b);
  else if (ultimoComandoSeta == "cima esquerda")
    setaFrenteEsquerda(r, g, b);
  else if (ultimoComandoSeta == "cima direita")
    setaFrenteDireita(r, g, b);
  else if (ultimoComandoSeta == "baixo esquerda")
    setaTrasEsquerda(r, g, b);
  else if (ultimoComandoSeta == "baixo direita")
    setaTrasDireita(r, g, b);
}

// * Funções dos padrões de LED
void sorriso()
{
  fill_solid(leds, NUM_LEDS, CRGB::Black);
  leds[1] = leds[2] = leds[3] = leds[5] = leds[9] = leds[16] = leds[18] = CRGB(r, g, b);
  FastLED.show();
}

void setaEsquerda(uint8_t r, uint8_t g, uint8_t b)
{
  fill_solid(leds, NUM_LEDS, CRGB::Black);
  uint8_t idx[] = {2, 8, 10, 11, 12, 13, 14, 18, 22};
  for (uint8_t i : idx)
    leds[i] = CRGB(r, g, b);
  FastLED.show();
}

void setaDireita(uint8_t r, uint8_t g, uint8_t b)
{
  fill_solid(leds, NUM_LEDS, CRGB::Black);
  uint8_t idx[] = {2, 6, 10, 11, 12, 13, 14, 16, 22};
  for (uint8_t i : idx)
    leds[i] = CRGB(r, g, b);
  FastLED.show();
}

void setaFrente(uint8_t r, uint8_t g, uint8_t b)
{
  fill_solid(leds, NUM_LEDS, CRGB::Black);
  uint8_t idx[] = {2, 7, 10, 12, 14, 16, 17, 18, 22};
  for (uint8_t i : idx)
    leds[i] = CRGB(r, g, b);
  FastLED.show();
}

void setaTras(uint8_t r, uint8_t g, uint8_t b)
{
  fill_solid(leds, NUM_LEDS, CRGB::Black);
  uint8_t idx[] = {2, 6, 7, 8, 10, 12, 14, 17, 22};
  for (uint8_t i : idx)
    leds[i] = CRGB(r, g, b);
  FastLED.show();
}

void setaFrenteEsquerda(uint8_t r, uint8_t g, uint8_t b)
{
  fill_solid(leds, NUM_LEDS, CRGB::Black);
  uint8_t idx[] = {4, 6, 10, 12, 18, 19, 20, 21, 22};
  for (uint8_t i : idx)
    leds[i] = CRGB(r, g, b);
  FastLED.show();
}

void setaFrenteDireita(uint8_t r, uint8_t g, uint8_t b)
{
  fill_solid(leds, NUM_LEDS, CRGB::Black);
  uint8_t idx[] = {0, 8, 12, 14, 15, 16, 22, 23, 24};
  for (uint8_t i : idx)
    leds[i] = CRGB(r, g, b);
  FastLED.show();
}

void setaTrasEsquerda(uint8_t r, uint8_t g, uint8_t b)
{
  fill_solid(leds, NUM_LEDS, CRGB::Black);
  uint8_t idx[] = {0, 1, 2, 8, 9, 10, 12, 16, 24};
  for (uint8_t i : idx)
    leds[i] = CRGB(r, g, b);
  FastLED.show();
}

void setaTrasDireita(uint8_t r, uint8_t g, uint8_t b)
{
  fill_solid(leds, NUM_LEDS, CRGB::Black);
  uint8_t idx[] = {2, 3, 4, 5, 6, 12, 14, 18, 20};
  for (uint8_t i : idx)
    leds[i] = CRGB(r, g, b);
  FastLED.show();
}