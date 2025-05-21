/*
  Autores: Guilherme Vieira Molina
           Giuliano Keler Chicarelli
  Projeto: Memórias
  Descrição: Meu código em arduíno (C)
  Data: 21/02/2025
*/

// Declaração de variável
int numero = 400;

void setup(){
  
  //Teste
  Serial.begin(9600);
  Serial.print("A variavel contem: ");
  Serial.print(numero);
  numero = 162;
  Serial.print("\nA variavel agora contem: ");
  Serial.print(numero);
  
  //Overflow
  numero = 32768;
  Serial.print("\nA variavel ultrapassa o limite de int: ");
  Serial.print(numero);
  
  //Tipos de variáveis
  Serial.println("\nTamanhos dos tipos de variaveis em Byte: ");
  
  //Tipo booleano = True ou False (0 ou 1)
  Serial.print("bool: "); Serial.print(sizeof(bool)); Serial.println(" Byte");
  
  //Tipo char = Caractere da tabela ASCII (0 a 255, ou caractere)
  Serial.print("char: "); Serial.print(sizeof(char)); Serial.println(" Byte");
  
  //Tipo byte = Números inteiros positivos (0 a 255)
  Serial.print("byte: "); Serial.print(sizeof(byte)); Serial.println(" Byte");
  
  //int8_t
  Serial.print("int8_t: "); Serial.print(sizeof(int8_t)); Serial.println(" Bytes");
  
  //uint8_t
  Serial.print("uint8_t: "); Serial.print(sizeof(uint8_t)); Serial.println(" Bytes");
  
  //int16_t
  Serial.print("int16_t: "); Serial.print(sizeof(int16_t)); Serial.println(" Bytes");
  
  //uint16_t
  Serial.print("uint16_t: "); Serial.print(sizeof(uint16_t)); Serial.println(" Bytes");
  
  //int32_t
  Serial.print("int32_t: "); Serial.print(sizeof(int32_t)); Serial.println(" Bytes");
  
  //uint32_t
  Serial.print("uint32_t: "); Serial.print(sizeof(uint32_t)); Serial.println(" Bytes");
  
  //int64_t
  Serial.print("int64_t: "); Serial.print(sizeof(int64_t)); Serial.println(" Bytes");
  
  //uint64_t
  Serial.print("uint64_t: "); Serial.print(sizeof(uint64_t)); Serial.println(" Bytes");
  
  //Tipo int = Números inteiros (-32.768 a 32.767)
  Serial.print("int: "); Serial.print(sizeof(int)); Serial.println(" Bytes");
  
  //Tipo uint (unsigned int) Números inteiros a partir de 0 (0 a 65.535)
  Serial.print("unsigned int: "); Serial.print(sizeof(unsigned int)); Serial.println(" Bytes");
  
  //Tipo long = Números inteiros (-2.147.483.648 a 2.147.483.647)
  Serial.print("long: "); Serial.print(sizeof(long)); Serial.println(" Bytes");
  
  //Tipo ulong (unsigned long) = Números inteiros a partir de 0 (0 a 4.294.967.295)
  Serial.print("unsigned long: "); Serial.print(sizeof(unsigned long)); Serial.println(" Bytes");
  
  //Tipo float = Números Reais (-3.402823e38 a 3.402823e38)
  Serial.print("float: "); Serial.print(sizeof(float)); Serial.println(" Bytes");
  
  //Tipo double = Números Reais (-1.79769313486232e308 a 1.79769313486232e308)
  Serial.print("double: "); Serial.print(sizeof(double)); Serial.println(" Bytes");
}

void loop(){
}