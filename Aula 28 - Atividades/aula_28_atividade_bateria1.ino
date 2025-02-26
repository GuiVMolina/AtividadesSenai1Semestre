#define pinLED 13
int bateria;

void setup() {
  pinMode(pinLED, OUTPUT);
  Serial.begin(9600); // Inicia a comunicação serial
}

void loop() {
  digitalWrite(pinLED, LOW);
  Serial.println("Quantos % esta a bateria?");
  while (Serial.available()==0){}
  bateria = Serial.parseInt();
  
  if (bateria >= 20 && bateria <= 80) {
    digitalWrite(pinLED, HIGH);
  }
  delay(5000);
}