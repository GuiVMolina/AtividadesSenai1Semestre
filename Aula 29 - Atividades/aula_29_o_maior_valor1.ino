float valor1, valor2;

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println("Primeiro valor:");
  while (Serial.available()==0){}
  valor1 = Serial.parseFloat();
  
  Serial.println("Segundo valor:");
  while (Serial.available()==0){}
  valor2 = Serial.parseFloat();
  
  if (valor1 > valor2) {
    Serial.print(valor1); Serial.print(" eh maior que "); Serial.print(valor2);
  } else if (valor2 < valor1) {
    Serial.print(valor2); Serial.print(" eh maior que "); Serial.print(valor1);
  } else {
  	Serial.print("Ambos os valores são iguais");
  }
}