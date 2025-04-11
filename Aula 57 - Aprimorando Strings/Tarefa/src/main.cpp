#include <Arduino.h>

// * Formas de escrever palavras em C
char letra[10] = {'P', 'A', 'L', 'A', 'V', 'R', 'A', '\0', '\0', '\0'};
char letraConcatenada[10] = "PALAVRA";

String palavra = "PALAVRA";

void setup() {

  // Copiando a string
  strcpy(letra, "PALAVRA");

  // Comparando a string
  if (strcmp(letra, "SENAI") == 0) {}

  // Comparando a string no 3º caractere
  if (strncmp(letra, "SENAI", 3) == 0) {}

  // Preenche a string com 'A'
  strstr(letra, "A");

  // Pega o tamanho da string
  palavra.length();

  // Pega o caractere na posição 0
  palavra.charAt(0);

  // Pega o caractere da posição 0 até a 3
  palavra.substring(0, 3);

  // Pega o índice do caractere 'A'
  palavra.indexOf('A');

  // Pega o último índice do caractere 'A'
  palavra.lastIndexOf('A');

  // Troca o caractere 'A' por 'B'
  palavra.replace('A', 'B');

  // Remove espaços em branco no começo e no final da string
  palavra.trim();

  // Compara a string
  if(palavra.equals("PALAVRA")) {}

  // Compara a string ignorando maiúsculas e minúsculas
  if(palavra.equalsIgnoreCase("PALAVRA")) {}

  // Compara o começo da string
  if(palavra.startsWith("PAL")) {}

  // Compara o final da string
  if(palavra.endsWith("RA")) {}

  // Converte a string para int
  String valor = "123";
  int numero = valor.toInt();

  // Converte a string para float
  String valor2 = "123.45";
  float numero2 = valor2.toFloat();
}

void loop() {}