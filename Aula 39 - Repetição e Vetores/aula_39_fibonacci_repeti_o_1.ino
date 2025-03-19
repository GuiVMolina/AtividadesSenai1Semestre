int valorA = 1, valorB = 0, resultado = 0, repeticao = 1;

void setup() {
  Serial.begin(9600);
  for (int i = 1; i <= 10; i++){
  	resultado = valorA + valorB;
    valorA = valorB;
    valorB = resultado;
    
    Serial.println(resultado);
  }
}

void loop() {
  /* É a mesma coisa que trabalhar com  o 'for'
  if (repeticao <= 10){
  	resultado = valorA + valorB;
    valorA = valorB;
    valorB = resultado;
    repeticao++;
    
    Serial.println(resultado);
  }
  */
}