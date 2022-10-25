// Button Test

int ledPin = 4;
int buttonPin = 22;

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  if (digitalRead(buttonPin))
  {
    digitalWrite(ledPin, HIGH);
    // Removed:
    //delay(300); // Wait for 300 millisecond(s)
    //digitalWrite(ledPin, LOW);
    //delay(300); // Wait for 300 millisecond(s)
  }
  else
  {
    digitalWrite(ledPin, LOW);
  }
}