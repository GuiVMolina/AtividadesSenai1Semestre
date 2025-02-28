#define ledAzul 9
#define ledVerde 10
#define ledAmarelo 11
#define ledLaranja 12
#define ledVermelho 13

int opcao, led;

void setup() {
  Serial.begin(9600);
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledLaranja, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAzul, OUTPUT);
}

void loop() {
  Serial.println("O que voce deseja fazer?");
  Serial.println("Apagar LED (0)");
  Serial.println("Acender LED (1)");
  while (Serial.available()==0){}
  opcao = Serial.parseInt();
  if (opcao != 1 && opcao != 0){
    opcao = 1;
  }
  
  Serial.println("Em qual LED deseja realizar a acao?");
  Serial.println("Vermelho (1)");
  Serial.println("Laranja  (2)");
  Serial.println("Amarelo  (3)");
  Serial.println("Verde    (4)");
  Serial.println("Azul     (5)");
  while (Serial.available()==0){}
  led = Serial.parseInt();
  
  switch(led){
    case 1:
    	digitalWrite(ledVermelho, opcao);
    break;
    
    case 2:
    	digitalWrite(ledLaranja, opcao);
    break;
    
    case 3:
    	digitalWrite(ledAmarelo, opcao);
    break;
    
    case 4:
    	digitalWrite(ledVerde, opcao);
    break;
    
    case 5:
    	digitalWrite(ledAzul, opcao);
    break;
    
    default:
    	Serial.println("Nao encontrado, tente novamente");
    break;
  }
}