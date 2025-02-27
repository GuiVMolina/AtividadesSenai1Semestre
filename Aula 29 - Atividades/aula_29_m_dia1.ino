float n1, n2, n3, n4, media;

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println("1a Nota:");
  while (Serial.available()==0){}
  n1 = Serial.parseFloat();
  
  Serial.println("2a Nota:");
  while (Serial.available()==0){}
  n2 = Serial.parseFloat();
  
  Serial.println("3a Nota:");
  while (Serial.available()==0){}
  n3 = Serial.parseFloat();
  
  Serial.println("4a Nota:");
  while (Serial.available()==0){}
  n4 = Serial.parseFloat();
  
  media = (n1 + n2 + n3 + n4) / 4.0;
  
  if (media >= 7.0) {
    Serial.println("Aluno aprovado");
  } else if (media < 7.0 && media >= 5.0) {
    Serial.println("Aluno em recuperacao");
  } else {
  	Serial.println("Aluno reprovado");
  }
  Serial.print("Nota final: "); Serial.println(media);
}