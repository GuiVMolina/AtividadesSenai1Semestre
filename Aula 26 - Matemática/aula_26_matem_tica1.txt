/*
  Autor: Guilherme Vieira Molina
  Projeto: Matemática
  Descrição: Meu código em arduíno (C)
  Data: 24/02/2025
*/

//** DECLARAÇÃO DE VARIÁVEIS GLOBAIS **
int numeroA =  14;
int numeroB = 5;
int resultado = 0;
float resultadoReal = 0;

void setup() {
  Serial.begin(9600);
  
  //Adição
  resultado = numeroA + numeroB;
  Serial.print("A soma de A com B, eh: "); Serial.println(resultado);
  
  //Subtração
  resultado = numeroA - numeroB;
  Serial.print("A subtracao de A com B, eh: "); Serial.println(resultado);
  
  //Multiplicação
  resultado = (float)numeroA * (float)numeroB;
  Serial.print("A multiplicacao de A e B, eh: "); Serial.println(resultado);
  
  //Divisão
  resultado = numeroA / numeroB;
  resultadoReal = (float)numeroA / (float)numeroB; //Divisão (Número Real)
  Serial.print("A divisao de A por B, eh: "); Serial.println(resultado);
  
  //Caso tenha resto da divisão
  if (numeroA % numeroB != 0) {
  	resultado = numeroA % numeroB;
  	Serial.print("O resto da divisao de A por B, eh: "); Serial.println(resultado);
  }
  
  //Limita a impressão do resultado em uma casa decimal
  Serial.print("Ou seja, em Numero Real fica: "); Serial.println(resultadoReal, 1);
  
  //Potenciação
  resultado = pow(numeroA, numeroB); //numeroA elevado ao numeroB
  Serial.print("O numeroA elevado ao numeroB, eh: "); Serial.println(resultado);
  resultado = sq(numeroA); //numeroA ao quadrado
  Serial.print("O numeroA elevado ao numeroB, eh: "); Serial.println(resultado);
                                                                     
  //Raiz Quadrada
  resultado = sqrt((float)numeroA); //Raiz quadrada do numeroA
  Serial.print("A Raiz Quadrado de A, eh: "); Serial.println(resultado);
  
  //Radiciação
  resultado = pow(numeroA, 1.0/numeroB); //Raiz do numeroA pelo numeroB
  Serial.print("A Raiz de A por B, eh: "); Serial.println(resultado);
                                                                     
  //Módulo
  resultado = abs(numeroA * -1);
  Serial.print("O Modulo de A, eh: "); Serial.println(resultado);
  
  //Restrição
  //constrain(valor, menorPossivel, maiorPossivel)
  resultado = constrain(numeroA, -3, 5); //Restringe a variavel numero A aos limites -3 e 5
  
  if (numeroA < -3){
   Serial.print("O numeroA estava abaixo do limte, entao passou a ser ");
  } else if (numeroA > 5){
    Serial.print("O numeroA estava acima do limte, entao passou a ser ");
  } else {
    Serial.print("O numeroA dentro do limite, entao continuou a ser ");
  }
  Serial.println(resultado);
  
  //Remapeamento
  //map(valor, deMenor, deMaior, paraMenor, paraMaior)
  resultado = map(numeroA, 0, 20, 0, 10);
  Serial.print("O numeroA remapeado ficaria: "); Serial.println(resultado);
  
  //Operadores de atribuição
  numeroA = 14;
  
  //numeroA = numeroA + 5
  numeroA += 5;
  Serial.print("numeroA += 5: "); Serial.println(numeroA);
  
  //numeroA = numeroA - 5
  numeroA -= 5;
  Serial.print("numeroA -= 5: "); Serial.println(numeroA);
  
  //numeroA = numeroA * 5
  numeroA *= 5;
  Serial.print("numeroA *= 5: "); Serial.println(numeroA);
  
  //numeroA = numeroA / 5
  numeroA /= 5;
  Serial.print("numeroA /= 5: "); Serial.println(numeroA);
  
  //numeroA = numeroA % 5
  numeroA %= 5;
  Serial.print("numeroA %= 5: "); Serial.println(numeroA);
  
  //Incrementação
  //numeroA = numeroA + 1
  numeroA++; //Pós-incremento
  ++numeroA; //Pré-incremento
  
  //Decrementação
  //numeroA = numeroA - 1
  numeroA--; //Pós-decremento
  --numeroA; //Pré-decremento
  
  //Expressões matemáticas
  float expressao = 3.0 * ((2.0 / 5.0) + (2.0 * 3.0));
  Serial.println(expressao);
  
  //
  float X = 750, deMenor = 500, deMaior = 1000, paraMenor = 100, paraMaior = 200, resultadoMap = 0;
  //map(X, deMenor, deMaior, paraMenor, paraMaior)
  resultadoMap = ((deMaior - X) / (deMaior - deMenor)) * paraMenor + (paraMaior - paraMenor);
  //resultadoMap = ((1000 - 750) / (1000 - 500)) * 100 + (200 - 100);
  Serial.println(resultadoMap);
  Serial.println(map(X, deMenor, deMaior, paraMenor, paraMaior));
}

void loop() {
}