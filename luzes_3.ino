int g=13;
int y=12;
int r=11;


int porta[]={g, r, g, r, y, y, g, y, r, y, g, y, r, y};



void setup() {
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);


}

void loop() {
  for(int i=0; i<14; i=i+1){
    digitalWrite(porta[i], HIGH);
    delay(400);
    digitalWrite(porta[i], LOW);
    delay(100);
  } 

  
}
