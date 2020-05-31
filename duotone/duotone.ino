//Função duotone, que toca em dois buzzers diferentes ao msm tempo para fazer uma harmonização

//recomendo frequencias na 5 (Max 4) oitava
int pt=4;
int pd=7;

void duotone(int a, int b, int d){
  for(int i=0; i<d*750/22; i++){
     tone(pt,a);
     delay(11);
     noTone(pt);
     tone(pd,b);
     delay(11);
     noTone(pd);
  }
}

int C=1047;
int D=1175;
int E=1319;
int F=1397;
int G=1568;
void setup() {
  pinMode(pd,OUTPUT);
  pinMode(pt,OUTPUT);

}

void loop() {
    duotone(C,G, 3);
    duotone(G, D, 2);
}
