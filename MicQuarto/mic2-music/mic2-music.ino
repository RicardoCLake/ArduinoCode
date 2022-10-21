//mistura de Mic2 com o duotone das musicas

/**************************** DEFINIÇÕES ***************************************/

// Os números associados a cada variável seguem o guia de conexões e representam as portas digitais usadas. 
#define releUm 4
#define releDois 5
#define releTres 6
#define releQuatro 7
#define sinal 10    //*teste*

/************************ VARIÁVEIS AUXILIARES *********************************/

// Essas variáveis definem alguns parâmetros do programa e auxiliam na detecção e contagem das palmas.
int mn = 290;  
int delayfinal = 100;       //Valor representa um tempo em milissegundos, esse tempo é aguardado pelo programa para que se inicie novamente o loop.  
int duracaoPalma = 200;     //Valor representa um tempo em milissegundos, é o tempo que dura o som de uma palma, precisa ser calibrado entre 100 e 250. 
int intervaloPalmas = 500;  //Valor representa um tempo em milissegundos, é o intervalo máximo permitido entre uma sequência de palmas.  
int quantidadePalmas = 0;   //Quantidade de palmas registradas.
long momentoPalma = 0;      //Marcador usado para a detecção das palmas, será utilizado junto com a função millis. 
long esperaPalmas = 0;      //Marcador usado para contagem dos intervalos de tempo, será utilizado junto com a função millis. 

/************************  DUOTONE **********************************/ 
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

 int pt=8;
int pd=9;

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

 /************************  ASA BRANCA  **********************************/ 
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


/****************************JE VOUS SALUT  **************************************/ 
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


/********************************************************************************/ 
void setup() {

  pinMode(pd,OUTPUT);
  pinMode(pt,OUTPUT);
  

  pinMode(releUm,OUTPUT);
  pinMode(releDois,OUTPUT);
  pinMode(releTres,OUTPUT);
  pinMode(releQuatro,OUTPUT);

  pinMode(sinal, OUTPUT);     //*teste*
  pinMode(13, OUTPUT);      //*teste*
  
  digitalWrite(releUm,LOW);
  digitalWrite(releDois,LOW);
  digitalWrite(releTres,LOW);
  digitalWrite(releQuatro,LOW);
}

void loop() {
  
  //Faz a leitura digital do sensor de som, quando este sensor detecta som ele desliga a porta de entrada, mudando seu estado para LOW e quando não detecta mantem em HIGH.
  int leituraSom = analogRead(A0);

  if(leituraSom < mn){      //*teste*
    digitalWrite(13, HIGH);
    digitalWrite(sinal, HIGH);
  }
    else{
    digitalWrite(13, LOW);
    digitalWrite(sinal, LOW);
    }
  
  //Ações quando o sensor detectar som, ou seja, fica com leitura menor do que "muda"
  if (leituraSom < mn) {
    
     //Marca o momento da palma, soma a quantidade de palmas e aguarda um intervalo para não marcar a mesma palma mais de uma vez. 
     if (momentoPalma == 0) {
        momentoPalma = esperaPalmas = millis();
        quantidadePalmas = quantidadePalmas + 1; 
     } 
     else if ((millis() - momentoPalma) >= duracaoPalma) {
        momentoPalma = 0;
        }
  }

  //Verifica se nenhuma palma mais pode ser dada, e em seguida faz o acionamento dos relés conforme o número de palmas já registrado. 
  if (((millis() - esperaPalmas) > intervaloPalmas) && (quantidadePalmas != 0)) {
    
    if(quantidadePalmas == 1){
       digitalWrite(releUm, !digitalRead(releUm));          //O sinal de exclamação inverte a condição do relé, se estava ligado será desligado e vice versa. 
       }
    if(quantidadePalmas == 2){                              //ASA BRANCA
       for(int x=0; ASABRANCA[x]!=X; x=x+3){
         duotone(ASABRANCA[x]*2,ASABRANCA[x+1]*2,ASABRANCA[x+2]);
         }
       }  
    if(quantidadePalmas == 3){
      for(int x=0; JE[x]!=X; x=x+3){
        duotone(JE[x],JE[x+1],JE[x+2]);
        }
      }
       
    if(quantidadePalmas == 4){
       digitalWrite(releQuatro, !digitalRead(releQuatro));  //O sinal de exclamação inverte a condição do relé, se estava ligado será desligado e vice versa. 
       }

     delay(delayfinal);     //Tempo de espera para continuar o programa, esse tempo é importante para evitar efeitos de possiveis detecções truncadas de ecos e reverberações no som. 
     quantidadePalmas = 0;  //Retoma a condição inicial da quantidade de palmas. 
   }
}
    
