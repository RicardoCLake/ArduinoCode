int verde=12;
int amarelo=11;
int vermelho=10;


void setup() {
  pinMode(verde, OUTPUT);
  pinMode(amarelo, OUTPUT);
  pinMode(vermelho, OUTPUT);
  
  
}

void loop() {
  digitalWrite(vermelho, HIGH);
  delay(400);
  digitalWrite(vermelho, LOW);
  digitalWrite(amarelo, HIGH);
  delay(400);
  digitalWrite(amarelo,LOW);
  
}
