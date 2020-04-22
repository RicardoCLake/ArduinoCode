void setup() {
  // put your setup code here, to run once:
pinMode(0, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
PORTD = 1;
delay(500);
PORTD = 0;
delay(250);

}
