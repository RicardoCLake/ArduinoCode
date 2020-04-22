int buzstate = LOW;
const int buz=7;

void setup() {
 pinMode(buz,OUTPUT);

}

void loop() {
  
if(buzstate == LOW){
        buzstate = HIGH;
      }
      else{
        buzstate = LOW;
      }
digitalWrite(buz, buzstate);
delay (500); 

}
