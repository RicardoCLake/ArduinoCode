/*Toque Da música Asa Branca com a função Duotone em dois peltiers*/


//recomendo frequencias na 5 (Max 4) oitava
 int c=523;
 int f=698;
 int g=784;
 int Bb=932;
 int C=1047;
 int D=1175;
 int E=1319;
 int F=1397;
 int G=1568;
 int A=1760;
 int X=0;
// NOTA1, ACOMPONHAMENTO1, d1, NOTA2, ACOMPANHAMENTO2, d2...

int ASABRANCA[]={
  C, c, 1,
  D, c, 1,
  E, c, 2,
  G, c, 2,
  G, c, 2,
  E, c, 2,
  F, f, 2,
  F, f, 4,
  C, c, 1,
  D, c, 1,
  E, c, 2,
  G, c, 2,
  G, g, 2,
  F, g, 2,
  E, c, 5,
  
  C, c, 1,
  C, c, 1,
  D, c, 1,
  E, Bb,2,
  G, Bb,3,
  G, Bb,1,
  F, Bb,1,
  E, Bb,1,
  C, f, 2,
  F, f, 3,
  E, f, 1,
  E, f, 1, 
  D, f, 1,
  D, g, 2,
  E, g, 3,
  D, g, 1,
  D, g, 1,
  C, g, 1,
  C, c, 4,

  C, c, 1,
  C, c, 1,
  D, c, 1,
  E, Bb,2,
  G, Bb,3,
  G, Bb,1,
  F, Bb,1,
  E, Bb,1,
  C, f, 2,
  F, f, 3,
  E, f, 1,
  E, f, 1, 
  D, f, 1,
  D, g, 2,
  E, g, 3,
  D, g, 1,
  D, g, 1,
  C, g, 1,
  C, c, 4,
  X 
};

int pt=4;
int pd=7;

void duotone(int a, int b, int d){
  for(int i=0; i<=(d*300/22) - 100/22; i++){
     tone(pt,a);
     delay(11);
     noTone(pt);
     tone(pd,b);
     delay(11);
     noTone(pd);
  }
  delay(100);
}



     
void setup() {
  pinMode(pd,OUTPUT);
  pinMode(pt,OUTPUT);
  
  for(int x=0; ASABRANCA[x]!=X; x=x+3){
    duotone(ASABRANCA[x]*2,ASABRANCA[x+1]*2,ASABRANCA[x+2]);
    }
}

void loop(){
    
}
