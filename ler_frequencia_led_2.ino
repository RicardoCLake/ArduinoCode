void setup() {
  Serial.begin(9600);
  pinMode(11, INPUT);
  

}

void loop() {
  Serial.println(pulseIn(11,HIGH,500000));
  Serial.print(analogRead(A0));
  Serial.print(" - ");
  Serial.println((analogRead(A0)+1)*5/1024);
  Serial.println('.');


}
