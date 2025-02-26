#define pinLED 13
int valor;

void setup() {
  pinMode(pinLED, OUTPUT);
  Serial.begin(9600); // Inicia a comunicação serial
}

void loop() {
  digitalWrite(pinLED, LOW);
  Serial.println("Valor:");
  while (Serial.available()==0){}
  valor = Serial.parseInt();
  
  valor = map(valor, 0, 1023, 0, 100);
  Serial.print("Reajuste: "); Serial.println(valor);
  
  if (valor <= 20 || valor >= 80){
    digitalWrite(pinLED, HIGH);
  	Serial.print("O valor "); Serial.print(valor); Serial.println(" excedeu os limites");
    valor = constrain(valor, 20, 80);
    Serial.print("Valor reajustado para "); Serial.println(valor);
    delay(5000);
  } else {
  	Serial.print("O valor "); Serial.print(valor); Serial.println(" esta dentro do limite");
  }
}
  