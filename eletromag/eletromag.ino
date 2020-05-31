//Utilização do arduino para ligar e desligar bobinas
//mesmo com a baixa corrente do arduino houve bons resultados

void setup() {
  pinMode(8, OUTPUT);
  pinMode(12, OUTPUT);


}

void loop() {
  digitalWrite(12, HIGH);
  digitalWrite(8, HIGH);
  delay(3000);
  digitalWrite(12, LOW);
  digitalWrite(8, LOW);
  delay(4000);


}
