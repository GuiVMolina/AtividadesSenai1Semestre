#define pinLED 13
int numero;

void setup() {
  pinMode(pinLED, OUTPUT);
  Serial.begin(9600); // Inicia a comunicação serial
}

void loop() {
  digitalWrite(pinLED, LOW);
  Serial.println("Escolha um numero...");
  while (Serial.available()==0){}
  numero = Serial.parseInt();
  
  if (numero % 2 == 0) {
    digitalWrite(pinLED, HIGH);
    Serial.print(numero); Serial.println(" eh par");
    delay(5000);
  } else {
    Serial.print(numero); Serial.println(" eh impar");
  }
}