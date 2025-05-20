#include <Arduino.h>
#include <PubSubClient.h>
#include <WiFi.h>
#include "internet.h"

#define pinLed 2

WiFiClient espClient;
PubSubClient client(espClient);

bool estadoLed = false;
bool modoPisca = false;
float velocidadePisca = 500; // velocidade em ms

const char *mqtt_server = "broker.hivemq.com";
const int mqtt_port = 1883;
const char *mqtt_id = "esp32-senai134-guivmolina";
const char *mqtt_topic_sub = "senai134/mesa05/eps_inscrito";
const char *mqtt_topic_pub = "senai134/mesa05/eps_publicando";

void callback(char *, byte *, unsigned int);
void mqttConnect();
void piscaLed();

void setup(){
  Serial.begin(9600);
  conectaWiFi();
  pinMode(pinLed, OUTPUT);

  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);
}

void loop(){
  checkWiFi();

  if(!client.connected()) mqttConnect();
  client.loop();

  static unsigned long tempoAnteriorMsg = 0;
  unsigned long tempoAtual = millis();

  if(tempoAtual - tempoAnteriorMsg > 3000){
    client.publish(mqtt_topic_pub, "Olá Mundo");
    tempoAnteriorMsg = tempoAtual;
  }

  piscaLed();
}

void callback(char *topic, byte *payLoad, unsigned int Length){
  Serial.printf("Mensagem recebida em %s: ", topic, "/n");

  String mensagem = "";
  for (unsigned int i = 0; i < Length; i++){
    char c = (char)payLoad[i];
    mensagem += c;
  }

  mensagem.toLowerCase();
  mensagem.trim();

  if (mensagem.equals("ligar") || mensagem.equals("liga")){
    estadoLed = true;
    modoPisca = false;
    Serial.println("LED ligado");
  }

  else if (mensagem.equals("desligar") || mensagem.equals("desliga")){
    estadoLed = false;
    modoPisca = false;
    Serial.println("LED desligado");
  }

  else if (mensagem.equals("piscar") || mensagem.equals("pisca")){
    modoPisca = true;
    Serial.println("LED piscando");
  }

  else if (mensagem.startsWith("vel ")){
    String valorStr = mensagem.substring(4);
    float novoValor = valorStr.toFloat();
    if (novoValor > 0) {
      velocidadePisca = novoValor * 1000;
      Serial.println("Velocidade definida: " + String(velocidadePisca) + " ms");
    } else {
      Serial.println("Valor inválido para velocidade.");
    }
  }

  else if (mensagem.equals("rapido")){
    if (velocidadePisca > 100) {
      velocidadePisca -= 100;
      Serial.println("Aumentando a velocidade para: " + String(velocidadePisca) + " ms");
    } else {
      Serial.println("Velocidade já no máximo.");
    }
  }

  else if (mensagem.equals("devagar")){
    velocidadePisca += 100;
    Serial.println("Diminuindo a velocidade para: " + String(velocidadePisca) + " ms");
  }

  else if (mensagem.equals("status")){
    if (estadoLed) Serial.println("LED ligado");
    else if (modoPisca) Serial.println("LED piscando");
    else Serial.println("LED desligado");
    Serial.println("Velocidade atual: " + String(velocidadePisca) + " ms");
  }

  else if (mensagem.equals("ajuda") || mensagem.equals("help")){
    Serial.println("Comandos disponíveis:");
    Serial.println("     liga - Liga o LED");
    Serial.println("  desliga - Desliga o LED");
    Serial.println("    pisca - Faz o LED piscar");
    Serial.println("   rapido - Aumenta a velocidade do piscar");
    Serial.println("  devagar - Diminui a velocidade do piscar");
    Serial.println("vel <seg> - Define a velocidade em segundos (ex: vel 0.5)");
    Serial.println("   status - Mostra o estado atual");
    Serial.println("    ajuda - Mostra os comandos");
  }

  else {
    Serial.println("Comando inválido. Digite 'ajuda' para ver os comandos disponíveis.");
  }

  Serial.println(mensagem);
};

void mqttConnect(){
  while(!client.connected()){
    Serial.println("Conectando ao MQTT...");

    if(client.connect(mqtt_id)){
      Serial.println("Conectado com sucesso");
      client.subscribe(mqtt_topic_sub);
    } else {
      Serial.print("Falha, rc=");
      Serial.println(client.state());
      Serial.println("Tentando novamente em 5 segundos");
      delay(5000);
    }
  }
};

void piscaLed(){
  static unsigned long tempoAnteriorPisca = 0;
  unsigned long tempoAtual = millis();

  if(modoPisca){
    if(tempoAtual - tempoAnteriorPisca > velocidadePisca){
      estadoLed = !estadoLed;
      tempoAnteriorPisca = tempoAtual;
    }
  }

  digitalWrite(pinLed, estadoLed);
}
