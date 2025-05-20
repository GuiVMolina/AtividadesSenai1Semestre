#include <Arduino.h>
#include <ezTime.h>
#include "internet.h"

Timezone tempo;

void Odeley();

void setup() {
  Serial.begin(9600);
  conectaWiFi();

  waitForSync();
  tempo.setLocation("America/Sao_Paulo");
}

void loop() {
  checkWiFi();

  // Mostra a data e hora atual em formato legível.
  Serial.println(tempo.dateTime());
  // Exemplo: "2024-06-07 15:23:45"

  // Mostra os milissegundos atuais do tempo.
  Serial.println(tempo.ms());
  // Exemplo: 123

  // Mostra o segundo atual (0-59).
  Serial.println(tempo.second());
  // Exemplo: 45

  // Mostra o minuto atual (0-59).
  Serial.println(tempo.minute());
  // Exemplo: 23

  // Mostra a hora atual no formato 24h (0-23).
  Serial.println(tempo.hour());
  // Exemplo: 15

  // Mostra a hora atual no formato 12h (1-12).
  Serial.println(tempo.hourFormat12());
  // Exemplo: 3

  // Indica se está em horário de verão (1 para sim, 0 para não).
  Serial.println(tempo.isDST());
  // Exemplo: 0

  // Indica se é AM (1 para sim, 0 para não).
  Serial.println(tempo.isAM());
  // Exemplo: 1

  // Indica se é PM (1 para sim, 0 para não).
  Serial.println(tempo.isPM());
  // Exemplo: 0

  // Mostra o timestamp atual (segundos desde 1970).
  Serial.println(tempo.now());
  // Exemplo: 1717779825

  // Mostra o dia do mês (1-31).
  Serial.println(tempo.day());
  // Exemplo: 7

  // Mostra o dia da semana (1=domingo, 7=sábado).
  Serial.println(tempo.weekday());
  // Exemplo: 6

  // Mostra a semana ISO do ano (1-53).
  Serial.println(tempo.weekISO());
  // Exemplo: 23

  // Mostra o mês atual (1-12).
  Serial.println(tempo.month());
  // Exemplo: 6

  // Mostra o ano atual (ex: 2024).
  Serial.println(tempo.year());
  // Exemplo: 2024

  // Mostra o ano ISO (pode ser diferente em semanas próximas ao ano novo).
  Serial.println(tempo.yearISO());
  // Exemplo: 2024

  // Mostra o dia do ano (1-366).
  Serial.println(tempo.dayOfYear());
  // Exemplo: 159

  // Mostra a string POSIX do fuso horário.
  Serial.println(tempo.getPosix());
  // Exemplo: "BRST-3BRDT,M10.3.0/0,M2.3.0/0"

  Serial.println("— — — — — — — — — —");
  Odeley();
}

void Odeley(){
  delay(2000);
}