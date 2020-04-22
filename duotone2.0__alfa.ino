const int buz1=7;
const int buz2=4;

int buz1state=LOW;
int buz2state=LOW;

unsigned long inicialtime1=0;
unsigned long inicialtime2=0;

unsigned long now = micros();
unsigned long d0=now;

unsigned long f1=1;
unsigned long f2=2;

void setup() {
  pinMode(buz1, OUTPUT);
  pinMode(buz2, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop() {
  digitalWrite(13, HIGH);
  delay (30);
  digitalWrite(13, LOW);
  delay (30);  

if(now - inicialtime1 >= 1000000/(f1* 2)){
      inicialtime1=now;  
      if(buz1state==LOW){
        buz1state=HIGH;
      }
      else{
        buz1state=LOW;
      }
      digitalWrite(buz1, buz1state);
    }
    
    if( now - inicialtime2 >= 1000000/(f2 * 2)){
      inicialtime2=now;
      if(buz2state==LOW){
        buz2state=HIGH;
      }
      else{
        buz2state=LOW;
      }
      digitalWrite(buz2, buz2state);
    }


}
