// * Pedreiros: Diego C, Guilherme V, Pedro C, Kaue S 

#include <Arduino.h>
#include <FastLED.h>

#define pinLed 5 // Saída
#define NUM_LEDS 25 // Número de LEDs
CRGB leds[NUM_LEDS]; // Array de LEDs

// * Variáveis globais
uint8_t r = 16;
uint8_t g = 16;
uint8_t b = 16;
String ultimoComandoSeta = "";

// * Protótipos
void setaEsquerda(uint8_t r, uint8_t g, uint8_t b);
void setaDireita(uint8_t r, uint8_t g, uint8_t b);
void setaCima(uint8_t r, uint8_t g, uint8_t b);
void setaBaixo(uint8_t r, uint8_t g, uint8_t b);
void setaCimaEsquerda(uint8_t r, uint8_t g, uint8_t b);
void setaCimaDireita(uint8_t r, uint8_t g, uint8_t b);
void setaBaixoEsquerda(uint8_t r, uint8_t g, uint8_t b);
void setaBaixoDireita(uint8_t r, uint8_t g, uint8_t b);
void sorriso();
void reaplicarUltimaSeta();

void setup()
{
  Serial.begin(9600);
  FastLED.addLeds<WS2812, pinLed, GRB>(leds, NUM_LEDS);
  sorriso();
}

void loop()
{
  if(Serial.available()){
    String comando = Serial.readStringUntil('\n');
    comando.trim();
    comando.toLowerCase();

    if(comando.equals("esquerda") || comando.equals("e")) {
      Serial.println("Seta esquerda");
      setaEsquerda(r, g, b);
      ultimoComandoSeta = "esquerda";
    }
    else if(comando.equals("direita") || comando.equals("d")){
      Serial.println("Seta direita");
      setaDireita(r, g, b);
      ultimoComandoSeta = "direita";
    }
    else if(comando.equals("cima") || comando.equals("c")){
      Serial.println("Seta cima");
      setaCima(r, g, b);
      ultimoComandoSeta = "cima";
    }
    else if(comando.equals("baixo") || comando.equals("b")){
      Serial.println("Seta baixo");
      setaBaixo(r, g, b);
      ultimoComandoSeta = "baixo";
    }
    else if(comando.equals("cima esquerda") || comando.equals("ce")){
      Serial.println("Seta cima esquerda");
      setaCimaEsquerda(r, g, b);
      ultimoComandoSeta = "cima esquerda";
    }
    else if(comando.equals("cima direita") || comando.equals("cd")){
      Serial.println("Seta cima direita");
      setaCimaDireita(r, g, b);
      ultimoComandoSeta = "cima direita";
    }
    else if(comando.equals("baixo esquerda") || comando.equals("be")){
      Serial.println("Seta baixo esquerda");
      setaBaixoEsquerda(r, g, b);
      ultimoComandoSeta = "baixo esquerda";
    }
    else if(comando.equals("baixo direita") || comando.equals("bd")){
      Serial.println("Seta baixo direita");
      setaBaixoDireita(r, g, b);
      ultimoComandoSeta = "baixo direita";
    }

    else if(comando.startsWith("r")) {
      r = constrain(comando.substring(2).toInt(), 0, 255);
      Serial.printf("R: %i \n", r);
      reaplicarUltimaSeta();
    }
    else if(comando.startsWith("g")) {
      g = constrain(comando.substring(2).toInt(), 0, 255);
      Serial.printf("G: %i \n", g);
      reaplicarUltimaSeta();
    }
    else if(comando.startsWith("b")) {
      b = constrain(comando.substring(2).toInt(), 0, 255);
      Serial.printf("B: %i \n", b);
      reaplicarUltimaSeta();
    }

    else if (comando.equals("vermelho")){
      r = 32; g = 0; b = 0;
      reaplicarUltimaSeta();
    }
    else if (comando.equals("verde")){
      r = 0; g = 32; b = 0;
      reaplicarUltimaSeta();
    }
    else if (comando.equals("azul")){
      r = 0; g = 0; b = 32;
      reaplicarUltimaSeta();
    }
    else if (comando.equals("branco")){
      r = 32; g = 32; b = 32;
      reaplicarUltimaSeta();
    }
    else if (comando.equals("preto") || comando.equals("desligar") || comando.equals("apagar")){
      fill_solid(leds, NUM_LEDS, CRGB::Black);
      FastLED.show();
    }
    else if (comando.equals("cor")){
      Serial.println("Cor atual:");
      Serial.printf("R: %i \nG: %i \nB: %i \n", r, g, b);
      Serial.println("Cores padrão:");
      Serial.println("vermelho / verde / azul / branco");
    }
    else if (comando.equals("lista") || comando.equals("ajuda")){
      Serial.println("Comandos disponíveis:");
      Serial.println("esquerda (e)");
      Serial.println("direita (d)");
      Serial.println("cima (c)");
      Serial.println("baixo (b)");
      Serial.println("cima esquerda (ce)");
      Serial.println("cima direita (cd)");
      Serial.println("baixo esquerda (be)");
      Serial.println("baixo direita (bd)");
      Serial.println("r [valor]");
      Serial.println("g [valor]");
      Serial.println("b [valor]");
      Serial.println("cor");
      Serial.println("vermelho / verde / azul / branco");
      Serial.println("preto / desligar / apagar");
    }

    else {
      Serial.println("Comando inválido. Digite 'ajuda' para ver a lista de comandos.");
    }
  }
}

// * Reaplica a última seta com a nova cor
void reaplicarUltimaSeta() {
  if (ultimoComandoSeta == "esquerda") setaEsquerda(r, g, b);
  else if (ultimoComandoSeta == "direita") setaDireita(r, g, b);
  else if (ultimoComandoSeta == "cima") setaCima(r, g, b);
  else if (ultimoComandoSeta == "baixo") setaBaixo(r, g, b);
  else if (ultimoComandoSeta == "cima esquerda") setaCimaEsquerda(r, g, b);
  else if (ultimoComandoSeta == "cima direita") setaCimaDireita(r, g, b);
  else if (ultimoComandoSeta == "baixo esquerda") setaBaixoEsquerda(r, g, b);
  else if (ultimoComandoSeta == "baixo direita") setaBaixoDireita(r, g, b);
}

// * Funções das setas e sorriso (mesmas de antes, não alteradas)
void setaEsquerda(uint8_t r, uint8_t g, uint8_t b) {
  fill_solid(leds, NUM_LEDS, CRGB::Black);
  leds[2] = leds[8] = leds[10] = leds[11] = leds[12] = leds[13] = leds[14] = leds[18] = leds[22] = CRGB(r, g, b);
  FastLED.show();
}
void setaDireita(uint8_t r, uint8_t g, uint8_t b) {
  fill_solid(leds, NUM_LEDS, CRGB::Black);
  leds[2] = leds[6] = leds[10] = leds[11] = leds[12] = leds[13] = leds[14] = leds[16] = leds[22] = CRGB(r, g, b);
  FastLED.show();
}
void setaCima(uint8_t r, uint8_t g, uint8_t b){
  fill_solid(leds, NUM_LEDS, CRGB::Black);
  leds[2] = leds[7] = leds[10] = leds[12] = leds[14] = leds[16] = leds[17] = leds[18] = leds[22] = CRGB(r, g, b);
  FastLED.show();
}
void setaBaixo(uint8_t r, uint8_t g, uint8_t b){
  fill_solid(leds, NUM_LEDS, CRGB::Black);
  leds[2] = leds[6] = leds[7] = leds[8] = leds[10] = leds[12] = leds[14] = leds[17] = leds[22] = CRGB(r, g, b);
  FastLED.show();
}
void setaCimaEsquerda(uint8_t r, uint8_t g, uint8_t b){
  fill_solid(leds, NUM_LEDS, CRGB::Black);
  leds[4] = leds[6] = leds[10] = leds[12] = leds[18] = leds[19] = leds[20] = leds[21] = leds[22] = CRGB(r, g, b);
  FastLED.show();
}
void setaCimaDireita(uint8_t r, uint8_t g, uint8_t b){
  fill_solid(leds, NUM_LEDS, CRGB::Black);
  leds[0] = leds[8] = leds[12] = leds[14] = leds[15] = leds[16] = leds[22] = leds[23] = leds[24] = CRGB(r, g, b);
  FastLED.show();
}
void setaBaixoEsquerda(uint8_t r, uint8_t g, uint8_t b){
  fill_solid(leds, NUM_LEDS, CRGB::Black);
  leds[0] = leds[1] = leds[2] = leds[8] = leds[9] = leds[10] = leds[12] = leds[16] = leds[24] = CRGB(r, g, b);
  FastLED.show();
}
void setaBaixoDireita(uint8_t r, uint8_t g, uint8_t b){
  fill_solid(leds, NUM_LEDS, CRGB::Black);
  leds[2] = leds[3] = leds[4] = leds[5] = leds[6] = leds[12] = leds[14] = leds[18] = leds[20] = CRGB(r, g, b);
  FastLED.show();
}
void sorriso(){
  fill_solid(leds, NUM_LEDS, CRGB::Black);
  leds[1] = leds[2] = leds[3] = leds[5] = leds[9] = leds[16] = leds[18] = CRGB(r, g, b);
  FastLED.show();
}