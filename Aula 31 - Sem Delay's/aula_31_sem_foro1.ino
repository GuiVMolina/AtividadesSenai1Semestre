#define ledVerde 8
#define ledAmarelo 9
#define ledVermelho 10

unsigned long tempoInicial = 0, tempoAtual;
const int tempoVerde = 3000;    // 3 segundos
const int tempoAmarelo = 2000;  // 2 segundos
const int tempoVermelho = 5000; // 5 segundos

void setup() {
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
}

void loop() {
  tempoAtual = millis();
  if (tempoAtual - tempoInicial < tempoVerde){
    // Led Verde, 3s
    digitalWrite(ledVerde, HIGH);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVermelho, LOW);
  } else if (tempoAtual - tempoInicial < tempoVerde + tempoAmarelo){
    // Led Amarelo, 2s
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAmarelo, HIGH);
    digitalWrite(ledVermelho, LOW);
  } else if (tempoAtual - tempoInicial < tempoVerde + tempoAmarelo + tempoVermelho){
    // Led Vermelho, 5s
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVermelho, HIGH);
  } else {
    tempoInicial = tempoAtual;
  }
}