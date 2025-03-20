#define botao 7

int led[5] = {13, 12, 11, 10, 9};
bool ligado = 1;
  
void setup(){
  for (int i = 0; i < 5; i++){
    pinMode(led[i], OUTPUT);
  }
  pinMode(botao, INPUT);
}

void loop(){
  int i = 0;
  bool leituraBotao = digitalRead(botao);
  
  while(leituraBotao){
  	digitalWrite(led[i], HIGH);
    leituraBotao = digitalRead(botao);
    i++;
    if(i == 5) i = 0;
    delay(500);
  }
  while(!leituraBotao && i != 5){
    digitalWrite(led[i], LOW);
    i++;
  }
  
  /* do{}
  	 while(condicao) */
  // executa a ação uma vez antes de entrar em repetição
}