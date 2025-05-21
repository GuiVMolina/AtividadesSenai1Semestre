#include <Arduino.h>
#include <PubSubClient.h>
#include <WiFi.h>
#include <ArduinoJson.h>
#include "internet.h"

#define pinLed 2

WiFiClient espClient;
PubSubClient client(espClient);

bool estadoLed = false;
bool modoPisca = false;
float tempoEspera = 500; // velocidade em ms

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

  JsonDocument doc;

  doc["botao"] = digitalRead(4);
  doc["msg"] = "OLA MUNDO";

  String mensagem;
  serializeJson(doc, mensagem);

  Serial.println(mensagem);
  client.publish(mqtt_topic_pub, mensagem.c_str());

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

  JsonDocument doc;
  char * mensagem 
  deserializeJson(doc, mensagem);

  Serial.println(mensagem);
  if(!doc["estadoLed"].isNull()){
    estadoLed = doc["estadoLed"];
  }

  if(!doc["modoPisca"].isNull()){
    modoPisca = doc["modoPisca"];
  }

  if(!doc["velocidade"].isNull()){
    tempoEspera = doc["velocidade"];
  }
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
    if(tempoAtual - tempoAnteriorPisca > tempoEspera){
      estadoLed = !estadoLed;
      tempoAnteriorPisca = tempoAtual;
    }
  }

  digitalWrite(pinLed, estadoLed);
}