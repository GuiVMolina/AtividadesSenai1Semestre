int valor;

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println("Digite um valor:");
  while (Serial.available()==0){}
  valor = Serial.parseInt();
  if (valor > 0) {
    Serial.print("O valor "); Serial.print(valor); Serial.println(" eh positivo");
  } else if (valor < 0){
    Serial.print("O valor "); Serial.print(valor); Serial.println(" eh negativo");
  } else {
    Serial.print("O valor "); Serial.print(valor); Serial.println(" eh zero");
  }
}