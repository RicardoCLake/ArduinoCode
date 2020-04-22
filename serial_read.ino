//aprendendo a usar a entrada serial do monitor
// Da série "Luzes" que criei para aprender e ensinar funções e programação basicas do arduino: 4 de 6

String nome[]={"eu", "voce"};
char tmb[64];
int t;

void setup() {
  Serial.begin(9600);
  tmb[0]=0;

}

void loop() {
  
  if (Serial.available() > 0){
    
    for(int x; x <= 1; x++){
      Serial.println(nome[x]);
    }
    
    for(int x; x <= 64; x++){
      Serial.println(tmb[x]);
      if(tmb[x] == 0)break;
    }
    
    Serial.readBytes(tmb, 10);

  }
}
