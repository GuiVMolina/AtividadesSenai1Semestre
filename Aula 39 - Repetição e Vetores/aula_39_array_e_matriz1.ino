int array[5] = {0, 1, 2 ,3 ,4};
int matriz[3][3] = {0, 1, 2,
                    3, 4, 5,
                    6, 7, 8};
void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 5; i++){
    Serial.println(array[i]);
  }
  
  for (int i = 0; i < 3; i++){
    for (int j = 0; j < 3; j++){
      Serial.println(matriz[i][j]);
  	}
  }
}

void loop() {
}