// Criação da função Duotone 2.0, que pretende tocar em dois buzzers ao mesmo tempo, porém sem ficar com um som vibrado
//assim, a ideia era retirar a função delay
//observe que há uma melhor aparencia do código, pois o autor ja era mais velho quando escreveu
//mesmo assim não funcionou


const int buz1=4;  //IMPORTANTE NAO MUDAR ESSAS PORTAS, POIS AS DEFINIÇÕES DO "PORTD" SAO FIXAS PARA ESSE NÚMEROS LÁ EMBAIXO
const int buz2=7;

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

//******************************************DEFINIÇÃO DA FUNÇÃO DUOTONE2***************************

void duotone2 (unsigned long f1, unsigned long f2, unsigned long d){

  unsigned long inicialtime1=0;
  unsigned long inicialtime2=0;
  
  unsigned long d0 = micros();
  
  while (micros() - d0 <= d * 270000 - 100000) {                  // 270000 foi um parametro de velocidade que achei bom, mas foi apenas da minha cabeca
    
    if(micros() - inicialtime1 >= 1000000/(f1) ){              //SEI LA O QUE É ISSO: - (295 - f1*70 / 440) 
                                                               // o certo seria 500000 como numerador, mas coloquei 1000000 para diminuir uma oitava
      if(PORTD & B00010000){                                       //( b00010000 é a porta buz1)
        PORTD = PORTD & B11101111;
      }
      else{
        PORTD= PORTD | B00010000;
      }
      inicialtime1 = micros();
    }
    
    if(micros() - inicialtime2 >= 1000000/(f2)){                 // o certo seria 500000 como numerador, mas coloquei 1000000 para diminuir uma oitava
      if(PORTD & B10000000){                                     //( b10000000 é a porta do buz2)
        PORTD = PORTD & B01111111;
      }
      else{
        PORTD = PORTD | B10000000;
      }
     inicialtime2 = micros();
    }
    
  }
  delay(100);
}

//*********************************************EXECUSSAO*********************************************

void setup(){
  pinMode(buz1, OUTPUT);
  pinMode(buz2, OUTPUT);

  delay (500);
  duotone2(C, C, 10);
  duotone2(C, D, 10);
  duotone2(C, E, 10);
  duotone2(C, F, 10);
  duotone2(C, G, 10);
  duotone2(C, A, 10);
  duotone2(C, BB, 10);
  duotone2(C, CC, 10);
  
  
}
    
void loop(){

  delay (500);
  duotone2(C, C, 10);
  duotone2(C, D, 10);
  duotone2(C, E, 10);
  duotone2(C, F, 10);
  duotone2(C, G, 10);
  duotone2(C, A, 10);

  
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
  delay (500);
  digitalWrite(13, LOW);
  delay (500);  
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
  delay (500);
  digitalWrite(13, LOW);
  delay (500);  
}
