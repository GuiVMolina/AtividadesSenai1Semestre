float salario;
String nome, cargo;

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println("Qual o seu nome?");
  while (Serial.available()==0){}
  nome = Serial.readString();
  
  Serial.println("Qual o seu cargo?");
  while (Serial.available()==0){}
  cargo = Serial.readString();
  
  Serial.println("Qual o seu salario?");
  while (Serial.available()==0){}
  salario = Serial.parseFloat();
  
  if (salario < 1000) {
    salario *= 1.1;
    Serial.print("Salario inferior a 1000 Reais\nValor reajustado para: "); Serial.println(salario);
  }
  Serial.print("Nome do funcionario: "); Serial.println(nome);
  Serial.print("Cargo: "); Serial.println(cargo);
  Serial.print("Salario: "); Serial.println(salario);
}