/*
Faça um programa que acenda 3 leds um por um,
mantenha-os acesos, por 3 segundos,
em seguida apague-os um por um.
*/

int led[5] = {13, 12, 11, 10, 9};
unsigned long tempoInicial = 0, tempoAtual;
const int tempoEspera = 3000;
bool ligado = 1;

void setup() {
  for (int i = 0; i < 5; i++) pinMode(led[i], OUTPUT);
}

void loop() {
  tempoAtual = millis();

  if (tempoAtual - tempoInicial >= tempoEspera) {
    tempoInicial = tempoAtual;
    ligado = !ligado;

    for (int i = 0; i < 5; i++) {
      digitalWrite(led[i], ligado);
      delay(250);
    }
  }
}