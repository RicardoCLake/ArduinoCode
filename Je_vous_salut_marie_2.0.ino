//tentaticva de tocar a musica francesa com a função duotone 2.0, que nao funcionou

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

const int buz1=7;
const int buz2=4;

void duotone2 (int f1, int f2, int d){
  int buz1state=LOW;
  int buz2state=LOW;

  long inicialtime1=0;
  long inicialtime2=0;
  
  long now = micros();
  long d0=now;
  
    while (micros()-d0 <= d*270000) {
    if(micros() - inicialtime1 >= 1000000/(f1* 2) - (295 - f1*70/440)){  //a segunda parte da subtração é o fator de correção
      if(buz1state==LOW){
        buz1state=HIGH;
      }
      else{
        buz1state=LOW;
      }
      digitalWrite(buz1, buz1state);
      inicialtime1=micros();
    }
    
    if( micros() - inicialtime2 >= 1000000/(f2 * 2)  - (295 - f2*70/440)){
      if(buz2state==LOW){
        buz2state=HIGH;
      }
      else{
        buz2state=LOW;
      }
      digitalWrite(buz2, buz2state);
      inicialtime2=micros();
    }
  }

}

     
void setup() {
  pinMode(buz1 ,OUTPUT);
  pinMode(buz2,OUTPUT);
  
  for(int x=0; JE[x]!=X; x=x+3){
    duotone2(JE[x] ,JE[x+1] ,JE[x+2]);
    }
}

void loop(){
    
}

//moral da história: mesmo com um fator de correção primario, o treco ficou bem desafinado
