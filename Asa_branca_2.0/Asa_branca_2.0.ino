/*Toque da música Asa Branca com a função Duotone 2.0, que serviu para testar a função e perceber que ela não funciona*/


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

void duotone2 (unsigned long f1, unsigned long f2, unsigned long d){

  unsigned long inicialtime1=0;
  unsigned long inicialtime2=0;
  
  unsigned long now = micros();
  unsigned long d0=now;
  
  while (now - d0 <= d * 270000 -100000) {
    now = micros();
    if(now - inicialtime1 >= 1000000/(f1*2) ){              //SEI LA O QUE É ISSO: - (295 - f1*70 / 440)
      if(PORTD & 16){
        PORTD = PORTD & B11101111;
      }
      else{
        PORTD= PORTD | 16;
      }
      now = inicialtime1 = micros();
    }
    
    if(now - inicialtime2 >= 1000000/(f2 * 2)){
      if(PORTD & 128){
        PORTD = PORTD & B01111111;
      }
      else{
        PORTD= PORTD | 128;
      }
      now = inicialtime2 = micros();
    }
    
    now = micros();
  }
  delay(100);
}




     
void setup() {
  pinMode(pd,OUTPUT);
  pinMode(pt,OUTPUT);
  
  for(int x=0; ASABRANCA[x]!=X; x=x+3){
    duotone2(ASABRANCA[x]*2,ASABRANCA[x+1]*2,ASABRANCA[x+2]);
    }
}

void loop(){
    
}
