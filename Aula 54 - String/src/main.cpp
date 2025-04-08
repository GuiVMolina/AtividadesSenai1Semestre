#include <Arduino.h>

struct Pessoa{
  char nome[20];
  int idade;
  float altura;
  bool generoMasculino;
};

Pessoa aluno, amigo, professor;

void setup() {
  Serial.begin(9600);
  strcpy(aluno.nome, "Guilherme");
  aluno.idade = 19;
  aluno.altura = 1.75;
  aluno.generoMasculino = true;

  Serial.println("\tAluno");
  Serial.printf("Nome: %s\n\r", aluno.nome);
  Serial.printf("Idade: %d anos\n\r", aluno.idade);
  Serial.printf("Altura: %.2f m\n\r", aluno.altura);
  Serial.printf("Sexo: %s", aluno.generoMasculino ? "Masculino" : "Feminino");

  strcpy(amigo.nome, "Giuliano");
  amigo.idade = 18;
  amigo.altura = 1.74;
  amigo.generoMasculino = true;
  Serial.println("\n\n\tAmigo");
  Serial.printf("\rNome: %s\n\r", amigo.nome);
  Serial.printf("Idade: %d anos\n\r", amigo.idade);
  Serial.printf("Altura: %.2f m\n\r", amigo.altura);
  Serial.printf("Sexo: %s", amigo.generoMasculino ? "Masculino" : "Feminino");

  strcpy(professor.nome, "Thiago");
  professor.idade = 30;
  professor.altura = 1.82;
  professor.generoMasculino = true;
  Serial.println("\n\n\tProfessor");
  Serial.printf("\rNome: %s\n\r", professor.nome);
  Serial.printf("Idade: %d anos\n\r", professor.idade);
  Serial.printf("Altura: %.2f m\n\r", professor.altura);
  Serial.printf("Sexo: %s", professor.generoMasculino ? "Masculino" : "Feminino");
}

void loop() {
}