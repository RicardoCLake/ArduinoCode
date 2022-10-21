//tocar buzzer com frequencia definida em 12

void setup() {
  pinMode(12,OUTPUT);
  
}

void loop() {
  tone(12, 880, 10000);
  delay(10000);
  tone(12, 1319, 10000);
  delay(10000);

}
