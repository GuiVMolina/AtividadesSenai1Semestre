#define pinLed 9
#define pinBotao 10

unsigned int valor = 0;
bool botaoPressionado = false;

void setup() {
  pinMode(pinBotao, INPUT);
  pinMode(pinLed, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  bool statusBotao = digitalRead(pinBotao);

  digitalWrite(pinLed, statusBotao);
  
  if (statusBotao && !botaoPressionado) { 
    valor++;
    Serial.println(valor);
    botaoPressionado = true;
  }

  if (!statusBotao) botaoPressionado = false;
}