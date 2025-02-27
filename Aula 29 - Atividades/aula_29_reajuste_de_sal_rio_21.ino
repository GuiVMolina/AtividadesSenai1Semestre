float salario;

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println("Qual o seu salario?");
  while (Serial.available()==0){}
  salario = Serial.parseFloat();
  
  if (salario < 500) {
    salario *= 1.3;
    Serial.print("Salario inferior a 500 Reais\nValor reajustado para: "); Serial.println(salario);
  } else {
    Serial.print("Salario: "); Serial.print(salario); Serial.println(", nao permitido reajuste");
  }
}