int led[5] = {13, 12, 11, 10, 9};
bool ligado = 1;
  
void setup(){
  for (int i = 0; i < 5; i++){
    pinMode(led[i], OUTPUT);
  }
}

void loop(){
  for (int i = 0; i < 5; i++){
    digitalWrite(led[i], ligado);
    delay(100);
  }
  ligado = !ligado;
}