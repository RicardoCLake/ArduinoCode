//comparação do "mono duotone" com um novo "tone2" que eu criei sem daley
//essa função tone 2 seria utlizada para criar o duotone2.0
//então criei esse arquivo para comparar as duas formas de "tone" para tentar entender o porque do duotone2.0 estar desafinado

const int buz1=4;

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

void tone2(unsigned long f1, unsigned long d){
  unsigned long inicialtime1=0;
  unsigned long now = micros();
  unsigned long d0=now;
  
  while (now - d0 <= d * 270000 - 100000) {
    if( 4000*(now - inicialtime1) >= 4000000000/(f1*2) ){              //SEI LA O QUE É ISSO: - (295 - f1*70 / 440)
      if(PORTD & 16){
        PORTD = PORTD & B11101111;
      }
      else{
        PORTD= PORTD | 16;
      }
      now = inicialtime1 = micros();
    }
    now = micros();
  }  
  delay(100);
}


void monoduotone(int a, int d){
  tone(buz1,a);
  delay(d*250-100);
  noTone(buz1);
  delay(100);
}


void setup() {
   pinMode(buz1, OUTPUT);
   pinMode(13, OUTPUT);
}

void loop() {
   tone2(C, 10);
   monoduotone(C,10);
   
   PORTB = B100000;
   delay(500);
   PORTB = 0;
   
   tone2(D, 10);
   monoduotone(D,10);
   
   PORTB = B100000;
   delay(500);
   PORTB = 0;
   
   tone2(E, 10);
   monoduotone(E,10);
   
   PORTB = B100000;
   delay(500);
   PORTB = 0;
   
   tone2(F, 10);
   monoduotone(F,10);
   
   PORTB = B100000;
   delay(500);
   PORTB = 0;
   
   tone2(G, 10);
   monoduotone(G,10);
   
   PORTB = B100000;
   delay(500);
   PORTB = 0;
   
   
}
