#include <Arduino.h>

char nome[20]; // Array de caracteres para armazenar o nome
char nome2[20];

void setup() {
  Serial.begin(9600);
  strcpy(nome, "Thiago"); // Copia "Thiago" para o array nome
  Serial.println(nome);
  strcat(nome, " Oliveira"); // Concatena " Oliveira" ao nome
  Serial.println(nome);
  int tamanho = strlen(nome); // Calcula o tamanho do nome
  Serial.println(tamanho);
  // Compara se o nome é igual a "Thiago Oliveira"
  if(strcmp(nome, "Thiago Oliveira") == 0) Serial.println("São iguais");
  else Serial.println("São diferentes");

  if(strncmp(nome, "Thiago", 6) == 0) Serial.println("Os 6 primeiros são iguais");
  else Serial.println("Os 6 primeiros são diferentes");

  char buffer[50];
  int tempetura = 25;
  sprintf(buffer, "Temperatura: %d°C", tempetura); // Formata a string
  Serial.println(buffer);
}

void loop() {
}