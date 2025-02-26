#define pinLED 13
int temp;

void setup() {
  pinMode(pinLED, OUTPUT);
  Serial.begin(9600); // Inicia a comunicação serial
}

void loop() {
  digitalWrite(pinLED, LOW);
  Serial.println("Qual a temperatura de hoje?");
  while (Serial.available()==0){}
  temp = Serial.parseInt();
  
  if (temp >= 30) {
    Serial.println("Hoje esta muito quente\n");
    digitalWrite(pinLED, HIGH);
  } else if (temp < 30 && temp >= 24) {
    Serial.println("Hoje esta quente\n");
  } else if (temp < 24 && temp >= 18) {
    Serial.println("Hoje esta adequado\n");
  } else if (temp < 18 && temp >= 6) {
    Serial.println("Hoje esta frio\n");
  } else {
    Serial.println("Hoje esta muito frio\n");
  }
  delay(5000);
}