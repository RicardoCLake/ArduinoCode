//frequencia do buzzer varia com a intensidade da luz no sensor

int luz=0;

void setup() {
  int luz=0;
  pinMode(11, OUTPUT);
}

void loop() {
  luz = analogRead(A0);
  tone(11, luz * 2, 100);
  delay(100);
}
