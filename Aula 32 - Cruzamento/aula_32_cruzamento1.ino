#define ledVerde1 5
#define ledAmarelo1 6
#define ledVermelho1 7
#define ledVerde2 8
#define ledAmarelo2 9
#define ledVermelho2 10
#define botao 4

unsigned long tempoInicial = 0, tempoAtual;
const int tempoVerde = 3000;    // 3 segundos
const int tempoAmarelo = 2000;  // 2 segundos
bool estadoBotao = 0;

void setup() {
  pinMode(ledVerde1, OUTPUT);
  pinMode(ledVerde2, OUTPUT);
  pinMode(ledAmarelo1, OUTPUT);
  pinMode(ledAmarelo2, OUTPUT);
  pinMode(ledVermelho1, OUTPUT);
  pinMode(ledVermelho2, OUTPUT);
  
  pinMode(botao, INPUT_PULLUP); // Ativa resistor de pull-up interno
}

void loop() {
  estadoBotao = digitalRead(botao);

  if (estadoBotao == LOW) { // O botão está pressionado
    tempoInicial = millis(); // Reinicia o semáforo
  }

  tempoAtual = millis();
  if (tempoAtual - tempoInicial < tempoVerde) {
    digitalWrite(ledVerde1, HIGH);
    digitalWrite(ledAmarelo1, LOW);
    digitalWrite(ledVermelho1, LOW);

    digitalWrite(ledVerde2, LOW);
    digitalWrite(ledAmarelo2, LOW);
    digitalWrite(ledVermelho2, HIGH);

  } else if (tempoAtual - tempoInicial < tempoVerde + tempoAmarelo) {
    digitalWrite(ledVerde1, LOW);
    digitalWrite(ledAmarelo1, HIGH);
    digitalWrite(ledVermelho1, LOW);

    digitalWrite(ledVerde2, LOW);
    digitalWrite(ledAmarelo2, LOW);
    digitalWrite(ledVermelho2, HIGH);

  } else if (tempoAtual - tempoInicial < tempoVerde * 2 + tempoAmarelo) {
    digitalWrite(ledVerde1, LOW);
    digitalWrite(ledAmarelo1, LOW);
    digitalWrite(ledVermelho1, HIGH);

    digitalWrite(ledVerde2, HIGH);
    digitalWrite(ledAmarelo2, LOW);
    digitalWrite(ledVermelho2, LOW);

  } else if (tempoAtual - tempoInicial < tempoVerde * 2 + tempoAmarelo * 2) {
    digitalWrite(ledVerde1, LOW);
    digitalWrite(ledAmarelo1, LOW);
    digitalWrite(ledVermelho1, HIGH);

    digitalWrite(ledVerde2, LOW);
    digitalWrite(ledAmarelo2, HIGH);
    digitalWrite(ledVermelho2, LOW);

  } else {
    tempoInicial = tempoAtual;
  }
}