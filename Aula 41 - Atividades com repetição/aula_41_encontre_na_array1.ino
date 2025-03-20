/*
Faça um programa que avalie um numero e verifique se este
numero esta dentro de um array,caso esse numero seja encontrado
mostre no console "Numero encontrado"caso contrario "Numero não encontrado".
*/

int array[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
int numero = 0;
bool confirmado = false;

void setup(){
  Serial.begin(9600);
  Serial.println("Escolha um numero");
  while (Serial.available()==0){}
  numero = Serial.parseInt();
  for (int i = 0; i < 10; i++) if (numero == array[i]) confirmado = true;
  confirmado ? Serial.println("Numero encontrado") : Serial.println("Numero nao encontrado");
}

void loop(){}