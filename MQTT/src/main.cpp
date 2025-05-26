#include <Arduino.h>
#include <PubSubClient.h>
#include <WiFi.h>
#include <ArduinoJson.h>
#include <Bounce2.h>
#include <ezTime.h>
#include <DHT.h>
#include "internet.h"

#define pinBotao 0
#define pinLed 2
#define DHTPIN 4
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

WiFiClient espClient;
PubSubClient client(espClient);
Bounce botao = Bounce();
Timezone tempo;

bool envioMqtt = false;
bool estadoLed = false;
bool modoPisca = false;
float velocidadePisca = 500; // velocidade em ms
float velocidadeDelay = 1000; // velocidade em ms
float hum, temp;

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

  // * Botão
  pinMode(pinBotao, INPUT_PULLUP);
  botao.attach(pinBotao);
  botao.interval(25);

  // * MQTT
  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);

  // * ezTime
  waitForSync();
  tempo.setLocation("America/Sao_Paulo");

  // * DHT22
  dht.begin();
}

void loop(){
  checkWiFi();

  if(!client.connected()) mqttConnect();
  client.loop();
  botao.update();

  static unsigned long tempoAnteriorMsg = 0;
  unsigned long tempoAtual = millis();

  JsonDocument doc;
  String mensagem = "";

  if(tempoAtual - tempoAnteriorMsg > velocidadeDelay){
    doc.clear();
    serializeJson(doc, mensagem);

    // * DHT22
    hum = dht.readHumidity();
    temp = dht.readTemperature();
    doc["umidade"] = hum;
    doc["temperatura"] = temp;
    doc["timestamp"] = tempo.now();
    doc["velocidadeDelay"] = velocidadeDelay;
    serializeJson(doc, mensagem);
    Serial.println(mensagem);
    client.publish(mqtt_topic_pub, mensagem.c_str());
    tempoAnteriorMsg = tempoAtual;
  }
  
  if (botao.changed()){
    doc["botao"] = botao.read();
    doc["umidade"] = hum;
    doc["temperatura"] = temp;
    doc["timestamp"] = tempo.now();
    doc["velocidadeDelay"] = velocidadeDelay;
    envioMqtt = true;
  }

  if (envioMqtt){
    serializeJson(doc, mensagem);
    Serial.println(mensagem);
    client.publish(mqtt_topic_pub, mensagem.c_str());
    envioMqtt = false;
  }

  // if (botao.fell()) {
  //   modoPisca = false;
  //   estadoLed = !estadoLed;
  //   digitalWrite(pinLed, estadoLed);

  //   doc.clear();
  //   doc["botao"] = 1;
  //   doc["estadoLed"] = estadoLed;
  //   serializeJson(doc, mensagem);
  //   client.publish(mqtt_topic_pub, mensagem.c_str());
  //   mensagem = "";
  // }

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
  deserializeJson(doc, mensagem.c_str());

  Serial.println(mensagem);
  if(!doc["estadoLed"].isNull()){
    estadoLed = doc["estadoLed"];
  }

  if(!doc["modoPisca"].isNull()){
    modoPisca = doc["modoPisca"];
  }

  if(!doc["velolcidadePisca"].isNull()){
    velocidadePisca = doc["velocidadePisca"];
  }
  
  if(!doc["velocidadeDelay"].isNull()){
    velocidadeDelay = doc["velocidadeDelay"];
  }

  if(!doc["botao"].isNull()){
    int botao = doc["botao"];
    if(botao == 1){
      estadoLed = !estadoLed;
      digitalWrite(pinLed, estadoLed);
    }
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
    if(tempoAtual - tempoAnteriorPisca > velocidadePisca){
      estadoLed = !estadoLed;
      tempoAnteriorPisca = tempoAtual;
    }
  }

  digitalWrite(pinLed, estadoLed);
}