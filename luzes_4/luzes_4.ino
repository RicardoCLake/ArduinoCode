// Da série "Luzes" que criei para aprender e ensinar funções e programação basicas do arduino: 4 de 6

int g=13;
int y=12;
int r=11;


int porta[]={
r, 500,
y, 500,
g, 500,
r, 300,
y, 300,
g, 300,
r, 100,
y, 100,
g, 100,
r, 5000,
y, 5000,
g, 5000};




void setup() {
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);


}

void loop() {
  for(int i=0; i<18; i=i+2){
    digitalWrite(porta[i], HIGH);
    delay(porta[i+1]);
    digitalWrite(porta[i], LOW);
  } 

  
}
