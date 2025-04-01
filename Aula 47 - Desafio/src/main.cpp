#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

#define pinLed 2
#define pinButtonDesce 4
#define pinButtonSobe 5
#define pinButtonConfirma 18

LiquidCrystal_I2C lcd(0x27, 20, 4);

int posicao = 0, numero = 0, tentativa = 1;
bool numeroEscolhido = false;

void setup() {
  pinMode(pinLed, OUTPUT);
  pinMode(pinButtonSobe, INPUT_PULLUP);
  pinMode(pinButtonDesce, INPUT_PULLUP);
  pinMode(pinButtonConfirma, INPUT_PULLUP);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 1);
  lcd.print(" > Choose a number");
  lcd.setCursor(0, 2);
  lcd.print(" Game starts in...");
  lcd.setCursor(1, 3);
  lcd.print("3");
  delay(1000);
  lcd.setCursor(3, 3);
  lcd.print("2");
  delay(1000);
  lcd.setCursor(5, 3);
  lcd.print("1");
  delay(1000);
  lcd.clear();

  for (int i = 0; i < 4; i++) {
    lcd.setCursor(0, i);
    lcd.write(byte(255));
    lcd.setCursor(19, i);
    lcd.write(byte(255));
  }

  digitalWrite(pinLed, LOW);
  lcd.setCursor(1, 0);
  lcd.print(" Choose a number");
  lcd.setCursor(1, 1);
  lcd.print(" Number: 0");
}

void loop() {
  const unsigned long tempoDebounce = 50;
  static unsigned long tempoAnteriorDebounce = 0;
  unsigned long tempoAtual = millis();

  // Botão "Sobe"
  bool estadoAtualBotaoSobe = digitalRead(pinButtonSobe);
  static bool estadoAnteriorBotaoSobe = 0;
  static bool ultimaAcaoSobe = 1;

  if (estadoAtualBotaoSobe != estadoAnteriorBotaoSobe) {
    tempoAnteriorDebounce = tempoAtual;
  }

  if ((tempoAtual - tempoAnteriorDebounce) > tempoDebounce) {
    if (estadoAtualBotaoSobe != ultimaAcaoSobe) {
      ultimaAcaoSobe = estadoAtualBotaoSobe;
      if (!estadoAtualBotaoSobe) {
        posicao++;
        if (posicao > 9) {
          posicao = 0;
        }
        lcd.setCursor(10, 1);
        lcd.print(" ");
        lcd.setCursor(10, 1);
        lcd.print(posicao);
      }
    }
  }
  estadoAnteriorBotaoSobe = estadoAtualBotaoSobe;

  // Botão "Desce"
  bool estadoAtualBotaoDesce = digitalRead(pinButtonDesce);
  static bool estadoAnteriorBotaoDesce = 0;
  static bool ultimaAcaoDesce = 1;

  if (estadoAtualBotaoDesce != estadoAnteriorBotaoDesce) {
    tempoAnteriorDebounce = tempoAtual;
  }

  if ((tempoAtual - tempoAnteriorDebounce) > tempoDebounce) {
    if (estadoAtualBotaoDesce != ultimaAcaoDesce) {
      ultimaAcaoDesce = estadoAtualBotaoDesce;
      if (!estadoAtualBotaoDesce) {
        posicao--;
        if (posicao < 0) {
          posicao = 9;
        }
        lcd.setCursor(10, 1);
        lcd.print(" ");
        lcd.setCursor(10, 1);
        lcd.print(posicao);
      }
    }
  }
  estadoAnteriorBotaoDesce = estadoAtualBotaoDesce;

  // Botão "Confirma"
  bool estadoAtualBotaoConfirma = digitalRead(pinButtonConfirma);
  static bool estadoAnteriorBotaoConfirma = 0;
  static bool ultimaAcaoConfirma = 1;

  if (estadoAtualBotaoConfirma != estadoAnteriorBotaoConfirma) {
    tempoAnteriorDebounce = tempoAtual;
  }

  if ((tempoAtual - tempoAnteriorDebounce) > tempoDebounce) {
    if (estadoAtualBotaoConfirma != ultimaAcaoConfirma) {
      ultimaAcaoConfirma = estadoAtualBotaoConfirma;
      if (!estadoAtualBotaoConfirma && !numeroEscolhido) {
        lcd.setCursor(10, 1);
        lcd.print(" ");
        lcd.setCursor(10, 1);
        lcd.print(numero);
        numeroEscolhido = true;
        numero = posicao;
        posicao = 0;
        tentativa = 1;
      } else
      if (!estadoAtualBotaoConfirma && numeroEscolhido) {
        lcd.setCursor(1, 2);
        if (posicao == numero) {
          lcd.print("You got it right!");
          digitalWrite(pinLed, HIGH);
        } else if (posicao != numero && tentativa < 3) {
          lcd.print("You got it wrong!");
          digitalWrite(pinLed, LOW);
          lcd.setCursor(1, 3);
          lcd.print("Tries: ");
          lcd.print(tentativa);
          tentativa++;
        } else {
          lcd.print(" You lost!       ");
          digitalWrite(pinLed, LOW);
          lcd.setCursor(1, 3);
          lcd.print(" Call your mama :)");
        }
      }
    }
  }
  estadoAnteriorBotaoConfirma = estadoAtualBotaoConfirma;
}