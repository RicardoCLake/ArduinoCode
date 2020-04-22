
/**************************** DEFINIÇÕES ***************************************/

// Os números associados a cada variável seguem o guia de conexões e representam as portas digitais usadas.
#define bts 9        //receptor bluetooth
#define releUm 2
#define releDois 4
#define releTres 6
#define releQuatro 2
#define botao 12
#define led 13

/************************ VARIÁVEIS AUXILIARES *********************************/

// Essas variáveis definem alguns parâmetros do programa e auxiliam na detecção e contagem das palmas.
int mn = 460;               //quanto mais alto, mais sensivel é o microfone
int leituraSom;
bool pare = 0;
int delayfinal = 100;       //Valor representa um tempo em milissegundos, esse tempo é aguardado pelo programa para que se inicie novamente o loop.
int duracaoPalma = 300;     //Valor representa um tempo em milissegundos, é o tempo que dura o som de uma palma, precisa ser calibrado entre 100 e 250.
int intervaloPalmas = 500;  //Valor representa um tempo em milissegundos, é o intervalo máximo permitido entre uma sequência de palmas.
int quantidadePalmas = 0;   //Quantidade de palmas registradas.
long momentoPalma = 0;      //Marcador usado para a detecção das palmas, será utilizado junto com a função millis.
long esperaPalmas = 0;      //Marcador usado para contagem dos intervalos de tempo, será utilizado junto com a função millis.

/********************************************************************************/
void setup() {

  pinMode(releUm, OUTPUT);
  pinMode(releDois, OUTPUT);
  pinMode(releTres, OUTPUT);
  pinMode(releQuatro, OUTPUT);
  pinMode(botao, INPUT_PULLUP);
  pinMode(led, OUTPUT);
  pinMode(bts, OUTPUT);

  digitalWrite(releUm, HIGH);
  digitalWrite(releDois, HIGH);
  digitalWrite(releTres, HIGH);
  digitalWrite(releQuatro, LOW);
  digitalWrite(led, LOW);
  digitalWrite(bts, HIGH);


}

void loop() {
  while (1) {


    if (!digitalRead(botao)) {
      pare = !pare;
      digitalWrite(led, !digitalRead(led));
      delay(500);
    }

    if (pare) {
      continue;
    }



    //Faz a leitura digital do microfone
    leituraSom = analogRead(A0);

    //Ações quando o sensor detectar som, ou seja, fica com leitura menor do que "mn"
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


      if (quantidadePalmas == 1) {
        digitalWrite(releUm, !digitalRead(releUm));          //O sinal de exclamação inverte a condição do relé, se estava ligado será desligado e vice versa.
      }
      if (quantidadePalmas == 2) {
        digitalWrite(releDois, !digitalRead(releDois));      //O sinal de exclamação inverte a condição do relé, se estava ligado será desligado e vice versa.
      }
      if (quantidadePalmas == 3) {
        digitalWrite(releTres, !digitalRead(releTres));      //O sinal de exclamação inverte a condição do relé, se estava ligado será desligado e vice versa.
        digitalWrite(bts, LOW);                              //"aperta" o botão do receptor bts (que esta em pull up)
        delay(3000);
        digitalWrite(bts, HIGH);

      }
      if (quantidadePalmas == 4) {
        digitalWrite(releQuatro, !digitalRead(releQuatro));  //O sinal de exclamação inverte a condição do relé, se estava ligado será desligado e vice versa.
      }

      delay(delayfinal);     //Tempo de espera para continuar o programa, esse tempo é importante para evitar efeitos de possiveis detecções truncadas de ecos e reverberações no som.
      quantidadePalmas = 0;  //Retoma a condição inicial da quantidade de palmas.
    }
  }
}
