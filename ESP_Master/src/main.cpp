#include <Arduino.h>
#include <BluetoothSerial.h>

BluetoothSerial SerialBT;

// * ESP MASTER
void setup() {
  Serial.begin(9600);

  if(!SerialBT.begin("ESP32_Master", true)){
    Serial.println("Erro ao iniciar a conexão Bluetooth no modo Master");
  }

  if(SerialBT.connect("ESP32_Slave")){
    Serial.println("Conectado com sucesso ao ESP32_Slave");
  }
  else {
    Serial.println("Falha ao conectar ao ESP32_Slave");
  }
}

void loop() {
  if(Serial.available()){
    String comando = Serial.readStringUntil('\n');
    comando.trim();
    SerialBT.println(comando);
  }

  if(SerialBT.available()){
    String resposta = SerialBT.readStringUntil('\n');
    resposta.trim();
    Serial.printf("Comando recebido: %s\n\r", resposta);

    if(resposta.equals("liga")){

    }
    else if(resposta.equals("desliga")){
      
    }
    else if(resposta.equals("pisca")){
      
    }
    else {
      Serial.println("Comando inválido");
    }
  }
}