int g=13;
int y=12;
int r=11;
int f=0;

int porta[]={
  r, y, 1000,
  r, g, 1000, 
  r, y, 1000,
  r, g, 1000,
  r, r, 1000,
  y, y, 1000,
  g, g, 1000,
  y, y, 1000, 
  
  f
};

void duoluz(int a, int b, int t){
  for(int i=0; i<=t/80; i=i+1){
    digitalWrite(a, HIGH);
    delay(40);
    digitalWrite(a, LOW);
    digitalWrite(b, HIGH);
    delay(40);
    digitalWrite(b, LOW);
  }
}


void setup() {
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);


}

void loop() {
  for(int x=0; porta[x]!=f; x=x+3){
    duoluz (porta[x], porta[x+1], porta[x+2]);}
  
}
