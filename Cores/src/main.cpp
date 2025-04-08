#include <Arduino.h>

struct corRGB{
  char r, g, b;
  int h, s, l;
  char hex[7];
};

corRGB vermelho, verde, azul, ciano, magenta, amarelo, branco, cinza, preto, laranja, roxo, verdeAgua;

void setup() {
  Serial.begin(9600);
  //Vermelho rgb(255, 0, 0)
  vermelho.r = 255;
  vermelho.g = 0;
  vermelho.b = 0;
  vermelho.h = 0;
  vermelho.s = 100;
  vermelho.l = 50;
  strcpy(vermelho.hex, "#ff0000");

  //Verde rgb(0, 255, 0)
  verde.r = 0;
  verde.g = 255;
  verde.b = 0;
  verde.h = 120;
  verde.s = 100;
  verde.l = 50;
  strcpy(verde.hex, "#00ff00");

  //Azul rgb(0, 0, 255)
  azul.r = 0;
  azul.g = 0;
  azul.b = 255;
  azul.h = 240;
  azul.s = 100;
  azul.l = 50;
  strcpy(azul.hex, "#0000ff");

  //Ciano rgb(0, 255, 255)
  ciano.r = 0;
  ciano.g = 255;
  ciano.b = 255;
  ciano.h = 180;
  ciano.s = 100;
  ciano.l = 50;
  strcpy(ciano.hex, "#00ffff");

  //Magenta rgb(255, 0, 255)
  magenta.r = 255;
  magenta.g = 0;
  magenta.b = 255;
  magenta.h = 240;
  magenta.s = 100;
  magenta.l = 50;
  strcpy(magenta.hex, "#ff00ff");

  //Amarelo rgb(255, 255, 0)
  amarelo.r = 255;
  amarelo.g = 255;
  amarelo.b = 0;
  amarelo.h = 60;
  amarelo.s = 100;
  amarelo.l = 50;
  strcpy(amarelo.hex, "#ffff00");

  //Preto rgb(0, 0, 0)
  preto.r = 0;
  preto.g = 0;
  preto.b = 0;
  preto.h = 0;
  preto.s = 100;
  preto.l = 0;
  strcpy(preto.hex, "#000000");

  //Cinza rgb(127, 127, 127)
  cinza.r = 127;
  cinza.g = 127;
  cinza.b = 127;
  cinza.h = 0;
  cinza.s = 0;
  cinza.l = 50;
  strcpy(cinza.hex, "#7f7f7f");

  //Branco rgb(255, 255, 255)
  branco.r = 255;
  branco.g = 255;
  branco.b = 255;
  branco.h = 0;
  branco.s = 100;
  branco.l = 100;
  strcpy(branco.hex, "#ffffff");

  //Laranja rgb(255, 127, 0)
  laranja.r = 255;
  laranja.g = 127;
  laranja.b = 0;
  laranja.h = 30;
  laranja.s = 100;
  laranja.l = 50;
  strcpy(laranja.hex, "#ff7f00");

  //Roxo rgb(127, 0, 127)
  roxo.r = 127;
  roxo.g = 0;
  roxo.b = 127;
  roxo.h = 270;
  roxo.s = 100;
  roxo.l = 25;
  strcpy(roxo.hex, "#7f007f");

  //Verde Água rgb(0, 255, 127)
  verdeAgua.r = 0;
  verdeAgua.g = 255;
  verdeAgua.b = 127;
  verdeAgua.h = 150;
  verdeAgua.s = 100;
  verdeAgua.l = 50;
  strcpy(verdeAgua.hex, "#00ff7f");

  Serial.println("Cores RGB");
  Serial.printf("Vermelho: R:%d G:%d B:%d\n\r", vermelho.r, vermelho.g, vermelho.b);
  Serial.printf("          H:%d S:%d L:%d\n\r", vermelho.h, vermelho.s, vermelho.l);
  Serial.printf("          Hexadecimal: %s\n\n\r", vermelho.hex);

  Serial.printf("   Verde: R:%d G:%d B:%d\n\r", verde.r, verde.g, verde.b);
  Serial.printf("          H:%d S:%d L:%d\n\r", verde.h, verde.s, verde.l);
  Serial.printf("          Hexadecimal: %s\n\n\r", verde.hex);

  Serial.printf("    Azul: R:%d G:%d B:%d\n\r", azul.r, azul.g, azul.b);
  Serial.printf("          H:%d S:%d L:%d\n\r", azul.h, azul.s, azul.l);
  Serial.printf("          Hexadecimal: %s\n\n\r", azul.hex);

  Serial.printf("   Ciano: R:%d G:%d B:%d\n\r", ciano.r, ciano.g, ciano.b);
  Serial.printf("          H:%d S:%d L:%d\n\r", ciano.h, ciano.s, ciano.l);
  Serial.printf("          Hexadecimal: %s\n\n\r", ciano.hex);

  Serial.printf(" Magenta: R:%d G:%d B:%d\n\r", magenta.r, magenta.g, magenta.b);
  Serial.printf("          H:%d S:%d L:%d\n\r", magenta.h, magenta.s, magenta.l);
  Serial.printf("          Hexadecimal: %s\n\n\r", magenta.hex);

  Serial.printf(" Amarelo: R:%d G:%d B:%d\n\r", amarelo.r, amarelo.g, amarelo.b);
  Serial.printf("          H:%d S:%d L:%d\n\r", amarelo.h, amarelo.s, amarelo.l);
  Serial.printf("          Hexadecimal: %s\n\n\r", amarelo.hex);

  Serial.printf("   Preto: R:%d G:%d B:%d\n\r", preto.r, preto.g, preto.b);
  Serial.printf("          H:%d S:%d L:%d\n\r", preto.h, preto.s, preto.l);
  Serial.printf("          Hexadecimal: %s\n\n\r", preto.hex);

  Serial.printf("   Cinza: R:%d G:%d B:%d\n\r", cinza.r, cinza.g, cinza.b);
  Serial.printf("          H:%d S:%d L:%d\n\r", cinza.h, cinza.s, cinza.l);
  Serial.printf("          Hexadecimal: %s\n\n\r", cinza.hex);

  Serial.printf("  Branco: R:%d G:%d B:%d\n\r", branco.r, branco.g, branco.b);
  Serial.printf("          H:%d S:%d L:%d\n\r", branco.h, branco.s, branco.l);
  Serial.printf("          Hexadecimal: %s\n\n\r", branco.hex);

  Serial.printf(" Laranja: R:%d G:%d B:%d\n\r", laranja.r, laranja.g, laranja.b);
  Serial.printf("          H:%d S:%d L:%d\n\r", laranja.h, laranja.s, laranja.l);
  Serial.printf("          Hexadecimal: %s\n\n\r", laranja.hex);

  Serial.printf("    Roxo: R:%d G:%d B:%d\n\r", roxo.r, roxo.g, roxo.b);
  Serial.printf("          H:%d S:%d L:%d\n\r", roxo.h, roxo.s, roxo.l);
  Serial.printf("          Hexadecimal: %s\n\n\r", roxo.hex);

  Serial.printf("  V-Agua: R:%d G:%d B:%d\n\r", verdeAgua.r, verdeAgua.g, verdeAgua.b);
  Serial.printf("          H:%d S:%d L:%d\n\r", verdeAgua.h, verdeAgua.s, verdeAgua.l);
  Serial.printf("          Hexadecimal: %s\n\n\r", verdeAgua.hex);
}

void loop() {
}