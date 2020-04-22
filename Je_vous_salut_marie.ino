//recomendo frequencias na 5 (Max 4) oitava 
 int c=523;
 int f=698;
 int fS=740;
 int g=784;
 int a=880;
 int Bb=932;
 int B=988;
 int C=1047;
 int D=1175;
 int DS=1245;
 int E=1319;
 int F=1397;
 int FS=1480;
 int G=1568;
 int A=1760;
 int BB=1976;
 int CC=2093;
 int DD=2349;
 int X=0;
// NOTA1, ACOMPONHAMENTO1, d1, NOTA2, ACOMPANHAMENTO2, d2...

int JE[]={
E, g, 2,
E, g, 2,
FS, a, 2,
G, E, 3,
A, E, 1,
G, E, 2,
FS, D, 2,
E, B, 2,
D, B, 2,
E, B, 4,
E, B, 2,
E, B, 4, 
FS, A, 2,
G, E, 4,
G, E, 2,
A, FS, 2, 
G, E, 2, 
A, FS, 2, 
BB, G, 4,
BB, G, 2,
BB, G, 2, 
CC, G, 2,
DD, G, 2,
A, FS, 2,
BB, G, 2,
A, FS, 2, 
G, E, 2,
G, E, 2,
BB, E, 2,
FS, D, 4,
FS, D, 2, 
E, g, 4,
G, E, 2,
A, FS, 3,
A, FS, 1,
FS, a, 2,
G, E, 2,
G, E, 2,
FS, D, 2,
E, B, 6,

BB, G, 2,
G, B, 2,
A, G,2,
BB,G , 4,
BB, G, 2,
DD, G,2,
CC, A,2,
BB, G,2,
A, FS, 6, 
G, E, 2, 
E, g, 2,
FS, E, 2,
G, E,6,
BB,E , 2,
A, FS,2,
G, E, 2,
FS, DS,6,

BB, G, 2,
G, B, 2,
A, G, 2,
BB, G, 2,
BB, G, 1,
BB, G, 1,
BB, G, 2,
DD, G,2,
CC, A,2,
BB, G,2,
A, FS, 6,

E, B, 4,
G, E, 2,
A, FS, 4,
FS, a,2,
G, E, 2,
G, E, 2,
FS, D, 2,
E, B, 6,




  X 
};

int pt=4;
int pd=7;

void duotone(int a, int b, int d){
  for(int i=0; i<=(d*270/22) - 100/22; i++){
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
  
  for(int x=0; JE[x]!=X; x=x+3){
    duotone(JE[x],JE[x+1],JE[x+2]);
    }
}

void loop(){
    
}
