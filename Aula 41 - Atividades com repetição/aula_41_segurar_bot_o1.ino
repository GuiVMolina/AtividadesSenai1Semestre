/*
Faça um programa que acenda e apague 3 leds,
de forma progressiva, enquanto um botão estiver pressionado.
*/

#define botao 8
int led[5] = {13, 12, 11, 10, 9};
int i = 0;
bool ligado = 0, botaoPressionado = false;
  
void setup(){
  pinMode(botao, INPUT_PULLUP);
  for (int i = 0; i < 5; i++){
    pinMode(led[i], OUTPUT);
  }
}

void loop(){
  bool estadoBotao = digitalRead(botao);
  
  if (estadoBotao && !botaoPressionado) {
    botaoPressionado = true;
    ligado = false;
  }
  
  if (!estadoBotao) {
    botaoPressionado = false;
  	ligado = true;
  }
  
  for (int i = 0; i < 5; i++) {
      digitalWrite(led[i], ligado);
      delay(250);
  }
}