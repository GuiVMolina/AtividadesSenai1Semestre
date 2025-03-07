#define ledVerde 12
#define ledVermelho 13
#define tempoPisca 2000

unsigned long tempoMs, tempoInicial = 0;
bool estadoLed = 0;

void setup() {
  Serial.begin(9600);
  pinMode(ledVerde, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
}

void loop() {
  
  //1a solução
  tempoMs = millis();
  tempoMs %= 4000;
  if (tempoMs >= 0 && tempoMs < 2000) {
  	digitalWrite(ledVermelho, HIGH);
  } else {
    digitalWrite(ledVermelho, LOW);
  }
  
  //2a solução
  tempoMs = millis();
  if (tempoMs - tempoInicial >= tempoPisca) {
    estadoLed = !estadoLed;
    tempoInicial = tempoMs;
  }
  digitalWrite(ledVerde, estadoLed);
}