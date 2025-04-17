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

void setup()
{
  Serial.begin(9600);
  FastLED.addLeds<WS2812, pinLed, GRB>(leds, NUM_LEDS); // Funciona tipo um pinMode para os LEDs
  sorriso();
}

void loop()
{
  if(Serial.available()){
    // Lê a mensagem do Serial
    String comando = Serial.readStringUntil('\n');
    comando.trim();
    comando.toLowerCase();

    // * Comandos de direção
    if(comando.equals("esquerda") || comando.equals("e")) {
      Serial.println("Seta esquerda");
      setaEsquerda(r, g, b);
    }
    else if(comando.equals("direita") || comando.equals("d")){
      Serial.println("Seta direita");
      setaDireita(r, g, b);
    }
    else if(comando.equals("cima") || comando.equals("c")){
      Serial.println("Seta cima");
      setaCima(r, g, b);
    }
    else if(comando.equals("baixo") || comando.equals("b")){
      Serial.println("Seta baixo");
      setaBaixo(r, g, b);
    }
    else if(comando.equals("cima esquerda") || comando.equals("ce")){
      Serial.println("Seta cima esquerda");
      setaCimaEsquerda(r, g, b);
    }
    else if(comando.equals("cima direita") || comando.equals("cd")){
      Serial.println("Seta cima direita");
      setaCimaDireita(r, g, b);
    }
    else if(comando.equals("baixo esquerda") || comando.equals("be")){
      Serial.println("Seta baixo esquerda");
      setaBaixoEsquerda(r, g, b);
    }
    else if(comando.equals("baixo direita") || comando.equals("bd")){
      Serial.println("Seta baixo direita");
      setaBaixoDireita(r, g, b);
    }
    
    // * Comandos de cor
    else if(comando.startsWith("r")) {
      r = comando.substring(2).toInt();
      if (r > 255) r = 255; // Limita o valor máximo
      else if (r < 0) r = 0; // Limita o valor mínimo
      Serial.printf("R: %i \n", r);
    }
    else if(comando.startsWith("g")) {
      g = comando.substring(2).toInt();
      if (g > 255) g = 255; // Limita o valor máximo
      else if (g < 0) g = 0; // Limita o valor mínimo
      Serial.printf("G: %i \n", g);
    }
    else if(comando.startsWith("b")) {
      b = comando.substring(2).toInt();
      if (b > 255) b = 255; // Limita o valor máximo
      else if (b < 0) b = 0; // Limita o valor mínimo
      Serial.printf("B: %i \n", b);
    }

    // * Modelos de cores prontos
    else if (comando.equals("vermelho")){
      r = 32;
      g = 0;
      b = 0;
      Serial.println("Cor: vermelho");
    }
    else if (comando.equals("verde")){
      r = 0;
      g = 32;
      b = 0;
      Serial.println("Cor: verde");
    }
    else if (comando.equals("azul")){
      r = 0;
      g = 0;
      b = 32;
      Serial.println("Cor: azul");
    }
    else if (comando.equals("branco")){
      r = 32;
      g = 32;
      b = 32;
      Serial.println("Cor: branco");
    }
    else if (comando.equals("preto") || comando.equals("desligar") || comando.equals("apagar")){
      fill_solid(leds, NUM_LEDS, CRGB::Black);  // Preenche os LEDs com a cor preta (apagado)
      FastLED.show();
    }

    // Comando inválido
    else {
      Serial.println("Comando inválido");
    }
  }
}

// * Funções
// 20 21 22 23 24
// 19 18 17 16 15
// 10 11 12 13 14
//  9  8  7  6  5
//  0  1  2  3  4
void setaEsquerda(uint8_t r, uint8_t g, uint8_t b) {
  fill_solid(leds, NUM_LEDS, CRGB::Black);  // Preenche os LEDs com a cor preta (apagado)
  leds[2] = CRGB(r, g, b);
  leds[8] = CRGB(r, g, b);
  leds[10] = CRGB(r, g, b);
  leds[11] = CRGB(r, g, b);
  leds[12] = CRGB(r, g, b);
  leds[13] = CRGB(r, g, b);
  leds[14] = CRGB(r, g, b);
  leds[18] = CRGB(r, g, b);
  leds[22] = CRGB(r, g, b);
  FastLED.show();
}
void setaDireita(uint8_t r, uint8_t g, uint8_t b) {
  fill_solid(leds, NUM_LEDS, CRGB::Black);  // Preenche os LEDs com a cor preta (apagado)
  leds[2] = CRGB(r, g, b);
  leds[6] = CRGB(r, g, b);
  leds[10] = CRGB(r, g, b);
  leds[11] = CRGB(r, g, b);
  leds[12] = CRGB(r, g, b);
  leds[13] = CRGB(r, g, b);
  leds[14] = CRGB(r, g, b);
  leds[16] = CRGB(r, g, b);
  leds[22] = CRGB(r, g, b);
  FastLED.show();
}
void setaCima(uint8_t r, uint8_t g, uint8_t b){
  fill_solid(leds, NUM_LEDS, CRGB::Black);  // Preenche os LEDs com a cor preta (apagado)
  leds[2] = CRGB(r, g, b);
  leds[7] = CRGB(r, g, b);
  leds[10] = CRGB(r, g, b);
  leds[12] = CRGB(r, g, b);
  leds[14] = CRGB(r, g, b);
  leds[16] = CRGB(r, g, b);
  leds[17] = CRGB(r, g, b);
  leds[18] = CRGB(r, g, b);
  leds[22] = CRGB(r, g, b);
  FastLED.show();
}
void setaBaixo(uint8_t r, uint8_t g, uint8_t b){
  fill_solid(leds, NUM_LEDS, CRGB::Black);  // Preenche os LEDs com a cor preta (apagado)
  leds[2] = CRGB(r, g, b);
  leds[6] = CRGB(r, g, b);
  leds[7] = CRGB(r, g, b);
  leds[8] = CRGB(r, g, b);
  leds[10] = CRGB(r, g, b);
  leds[12] = CRGB(r, g, b);
  leds[14] = CRGB(r, g, b);
  leds[17] = CRGB(r, g, b);
  leds[22] = CRGB(r, g, b);
  FastLED.show();
}
void setaCimaEsquerda(uint8_t r, uint8_t g, uint8_t b){
  fill_solid(leds, NUM_LEDS, CRGB::Black);  // Preenche os LEDs com a cor preta (apagado)
  leds[4] = CRGB(r, g, b);
  leds[6] = CRGB(r, g, b);
  leds[10] = CRGB(r, g, b);
  leds[12] = CRGB(r, g, b);
  leds[18] = CRGB(r, g, b);
  leds[19] = CRGB(r, g, b);
  leds[20] = CRGB(r, g, b);
  leds[21] = CRGB(r, g, b);
  leds[22] = CRGB(r, g, b);
  FastLED.show();
}
void setaCimaDireita(uint8_t r, uint8_t g, uint8_t b){
  fill_solid(leds, NUM_LEDS, CRGB::Black);  // Preenche os LEDs com a cor preta (apagado)
  leds[0] = CRGB(r, g, b);
  leds[8] = CRGB(r, g, b);
  leds[12] = CRGB(r, g, b);
  leds[14] = CRGB(r, g, b);
  leds[15] = CRGB(r, g, b);
  leds[16] = CRGB(r, g, b);
  leds[22] = CRGB(r, g, b);
  leds[23] = CRGB(r, g, b);
  leds[24] = CRGB(r, g, b);
  FastLED.show();
}
void setaBaixoEsquerda(uint8_t r, uint8_t g, uint8_t b){
  fill_solid(leds, NUM_LEDS, CRGB::Black);  // Preenche os LEDs com a cor preta (apagado)
  leds[0] = CRGB(r, g, b);
  leds[1] = CRGB(r, g, b);
  leds[2] = CRGB(r, g, b);
  leds[8] = CRGB(r, g, b);
  leds[9] = CRGB(r, g, b);
  leds[10] = CRGB(r, g, b);
  leds[12] = CRGB(r, g, b);
  leds[16] = CRGB(r, g, b);
  leds[24] = CRGB(r, g, b);
  FastLED.show();
}
void setaBaixoDireita(uint8_t r, uint8_t g, uint8_t b){
  fill_solid(leds, NUM_LEDS, CRGB::Black);  // Preenche os LEDs com a cor preta (apagado)
  leds[2] = CRGB(r, g, b);
  leds[3] = CRGB(r, g, b);
  leds[4] = CRGB(r, g, b);
  leds[5] = CRGB(r, g, b);
  leds[6] = CRGB(r, g, b);
  leds[12] = CRGB(r, g, b);
  leds[14] = CRGB(r, g, b);
  leds[18] = CRGB(r, g, b);
  leds[20] = CRGB(r, g, b);
  FastLED.show();
}
void sorriso(){
  fill_solid(leds, NUM_LEDS, CRGB::Black);  // Preenche os LEDs com a cor preta (apagado)
  leds[1] = CRGB(r, g, b);
  leds[2] = CRGB(r, g, b);
  leds[3] = CRGB(r, g, b);
  leds[5] = CRGB(r, g, b);
  leds[9] = CRGB(r, g, b);
  leds[16] = CRGB(r, g, b);
  leds[18] = CRGB(r, g, b);
  FastLED.show();
}