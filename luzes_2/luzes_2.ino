// Da série "Luzes" que criei para aprender e ensinar funções basicas do arduino: 2 de 6


int porta[]={13, 12, 11, 12, 13, 12, 11, 12, 13, 12, 11, 12, 13, 12, 11, 11, 11,};



void setup() {
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);


}

void loop() {
  for(int i=0; i<17; i++){
    digitalWrite(porta[i], HIGH);
    delay(400);
    digitalWrite(porta[i], LOW);
  } 

  
}
