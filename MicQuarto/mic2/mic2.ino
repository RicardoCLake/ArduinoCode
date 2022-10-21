//mistura do leitor de palmas do manual do mundo com o meu próprio sensor de palma

/**************************** DEFINIÇÕES ***************************************/

// Os números associados a cada variável seguem o guia de conexões e representam as portas digitais usadas. 
#define releUm 4
#define releDois 5
#define releTres 6
#define releQuatro 7
#define sinal 10    //*teste*

/************************ VARIÁVEIS AUXILIARES *********************************/

// Essas variáveis definem alguns parâmetros do programa e auxiliam na detecção e contagem das palmas.
int mn = 300;  
int delayfinal = 100;       //Valor representa um tempo em milissegundos, esse tempo é aguardado pelo programa para que se inicie novamente o loop.  
int duracaoPalma = 200;     //Valor representa um tempo em milissegundos, é o tempo que dura o som de uma palma, precisa ser calibrado entre 100 e 250. 
int intervaloPalmas = 500;  //Valor representa um tempo em milissegundos, é o intervalo máximo permitido entre uma sequência de palmas.  
int quantidadePalmas = 0;   //Quantidade de palmas registradas.
long momentoPalma = 0;      //Marcador usado para a detecção das palmas, será utilizado junto com a função millis. 
long esperaPalmas = 0;      //Marcador usado para contagem dos intervalos de tempo, será utilizado junto com a função millis. 

/********************************************************************************/ 
void setup() {

  pinMode(releUm,OUTPUT);
  pinMode(releDois,OUTPUT);
  pinMode(releTres,OUTPUT);
  pinMode(releQuatro,OUTPUT);

  pinMode(13, OUTPUT);      //*teste*

  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  
  digitalWrite(releUm,LOW);
  digitalWrite(releDois,LOW);
  digitalWrite(releTres,LOW);
  digitalWrite(releQuatro,LOW);
  
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);

  
}

void loop() {

  
  
  //Faz a leitura digital do sensor de som, quando este sensor detecta som ele desliga a porta de entrada, mudando seu estado para LOW e quando não detecta mantem em HIGH.
  int leituraSom = analogRead(A0);

  if(leituraSom < mn){      //*teste*
    digitalWrite(13, HIGH);
  }
    else{
    digitalWrite(13, LOW);
     }
  
  //Ações quando o sensor detectar som, ou seja, fica com leitura menor do que "mn"
  if (leituraSom < mn) {
    
     //Marca o momento da palma, soma a quantidade de palmas e aguarda um intervalo para não marcar a mesma palma mais de uma vez. 
     if (momentoPalma == 0) {
        momentoPalma = esperaPalmas = millis();
        quantidadePalmas = quantidadePalmas + 1; 
        
        PORTB = (PORTB & B11110000);
        /*PORTB = PORTB | (2 ^ (quantidadePalmas-1));*/ //(POR QUE NÃO FUNCIONA??)  
        if(quantidadePalmas == 1)
          PORTB = PORTB | B1; 
        if(quantidadePalmas == 2)
          PORTB = PORTB | B10;
        if(quantidadePalmas == 3)
          PORTB = PORTB | B100;
        if(quantidadePalmas == 4)
          PORTB = PORTB | B1000;
     } 
     else if ((millis() - momentoPalma) >= duracaoPalma) {
        momentoPalma = 0;
          }
      
  }
  



  //Verifica se nenhuma palma mais pode ser dada, e em seguida faz o acionamento dos relés conforme o número de palmas já registrado. 
  if (((millis() - esperaPalmas) > intervaloPalmas) && (quantidadePalmas != 0)) {

    PORTB = PORTB & B11110000;
    
    if(quantidadePalmas == 1){
       digitalWrite(releUm, !digitalRead(releUm));          //O sinal de exclamação inverte a condição do relé, se estava ligado será desligado e vice versa. 
       }
    if(quantidadePalmas == 2){
       digitalWrite(releDois, !digitalRead(releDois));      //O sinal de exclamação inverte a condição do relé, se estava ligado será desligado e vice versa. 
       }  
    if(quantidadePalmas == 3){
       digitalWrite(releTres, !digitalRead(releTres));      //O sinal de exclamação inverte a condição do relé, se estava ligado será desligado e vice versa. 
       }
    if(quantidadePalmas == 4){
       digitalWrite(releQuatro, !digitalRead(releQuatro));  //O sinal de exclamação inverte a condição do relé, se estava ligado será desligado e vice versa. 
       }

     delay(delayfinal);     //Tempo de espera para continuar o programa, esse tempo é importante para evitar efeitos de possiveis detecções truncadas de ecos e reverberações no som. 
     quantidadePalmas = 0;  //Retoma a condição inicial da quantidade de palmas. 
   }
}
    
