
// Da série "Luzes" que criei para aprender e ensinar funções e programação basicas do arduino: 5 de 6

void duoluz(int a, int b, int t){
  for(int i=0; i<=t/80; i=i+1){
    digitalWrite(a, HIGH);
    delay(40);
    digitalWrite(a, LOW);
    digitalWrite(b, HIGH);
    delay(40);
    digitalWrite(b, LOW);
  }
}


void setup() {
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);


}

void loop() {
duoluz (11, 12, 1000);
duoluz (11, 13, 1000);
duoluz (12, 13, 1000);
  
}
