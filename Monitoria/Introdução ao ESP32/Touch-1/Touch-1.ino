// Touch Test

const int touchPin = T3; //or "= T3"
double exponentialMain = 0.0;
double alpha = 0.15;

void setup()
{
  Serial.begin(115200);
  Serial.println("Sample Main");
  delay(1500); // avoid measurment error
}
void loop()
{
  int sampleTouch = touchRead(touchPin);
  exponentialMain = (1 - alpha) * exponentialMain + alpha * sampleTouch;

  Serial.print(sampleTouch);
  Serial.print(" ");
  Serial.println(exponentialMain); 

  delay(100);
}

//// Touch Test
//
//int touchPin = 15; //or "= T3"
//
//void setup()
//{
//  Serial.begin(115200);
//  Serial.println("Iniciando o teste...");
//}
//void loop()
//{
//  Serial.println(touchRead(touchPin)); 
//  delay(100);
//}