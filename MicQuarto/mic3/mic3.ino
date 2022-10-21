//Nova versão do código para o arduido do meu quarto
// Nessa versão foram inseridas opções mais complexas de comandos com palmas
// e foi trocado o microfone simples para versão em módulo digital

/**************************** DEFINIÇÕES ***************************************/

// Os números associados a cada variável seguem o guia de conexões e representam as portas digitais usadas.
#define bts 9        //receptor bluetooth
#define releUm 2
#define releDois 4
#define releTres 6
#define releQuatro 2
#define botao 12
#define led 13
#define mic 14
#define MAXIMO_COMANDO 7

/************************ VARIÁVEIS AUXILIARES *********************************/

// Essas variáveis definem alguns parâmetros do programa e auxiliam na detecção e contagem das palmas.
bool pare = false;                //condição para congelar o sistema
int posicaoFinal = 0;         //posicao no vetor de comandos
int duracaoEcoPalma = 250;    //Valor representa um tempo em milissegundos, é o tempo que dura o som de uma palma, precisa ser calibrado entre 100 e 250.
int duracaoEcoBotão = 250;    //Valor representa um tempo em milissegundos, é o tempo que dura o pulso de um botão.
int intervaloCurto = 300;     //Em milissegundos, duração considerada curta entre duas palmas
int intervaloLongo = 600;     //Em milissegundos, duração considerada longa duas palmas
int comando[MAXIMO_COMANDO] = {0};       //Sequencia de comandos (palmas curtas e longas)
unsigned long comandoDecimal = 0;         //Comando em formato de numero decimal
long momentoPalma = 0;      //Marcador usado para a detecção das palmas, será utilizado junto com a função millis.
long esperaPalmas = 0;      //Marcador usado para contagem dos intervalos de tempo, será utilizado junto com a função millis.

int delayfinal = 100;       //Valor representa um tempo em milissegundos, esse tempo é aguardado pelo programa para que se inicie novamente o loop.

/*************************** FUNÇÕES AUXILIARES *************************************/

bool lerComando(int pino, int dalayPino)
{
  delay(delayPino);
  momentoPalma = millis();
  while (millis() - momentoPalma <= intervaloLongo)
  {
    if (digitalRead(pino))
    {
      if (millis() - momentoPalma <= intervaloCurto)
      {
        comando[posicaoFinal] = 1;
      }
      else
      {
        comando[posicaoFinal] = 2;
      }
      posicaoFinal++;
      
      if (posicaoFinal >= 10) 
      {
        return false;
      }
      //else
      return lerComando(pino);
    }
  }
  comando[posicaoFinal] = 2;
  posicaoFinal++;
  comando[posicaoFinal] = 0;
  return true;
}

unsigned long produzirComandoDecimal(int posicaoFinal)
{
  unsigned long temporario = 0;
  unsigned long decimal = 1;
  for (int i = 0; i < posicaoFinal; i++)
  {
    decimal *= 10;
  }
  for (int i = 0; i < posicaoFinal; i++)
  {
    temporario += decimal * comando[i];
    decimal = decimal / 10;
  }
  return temporario;
}

void piscarComando(unsigned long nComando)
{
  int palma;
  while (nComando != 0)
  {
    palma = nComando % 10;
    if (palma == 1)
    {
      digitalWrite(led, HIGH);
      delay(duracaoEcoPalma);
      digitalWrite(led, LOW);
      delay(intervaloCurto);
    }
    if (palma == 2)
    {
      digitalWrite(led, HIGH);
      delay(duracaoEcoPalma);
      digitalWrite(led, LOW);
      delay(intervaloLongo);
    }
    nComando = nComando / 10;
  }
}


/********************************************************************************/

void setup() 
{
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

void loop() 
{
    if (digitalRead(mic))
    {
      if (!lerComando(mic, duracaoEcoPalma))
      {
        *comando = {0};
        posicaoFinal = 0;
      }
      comandoDecimal = produzirComandoDecimal(posicaoFinal);
      posicaoFinal = 0;
    }

    if (!digitalRead(botao, duracaoEcoBotao))
    {
      if (!lerComando(botao))
      {
        *comando = {0};
        posicaoFinal = 0;
      }
      comandoDecimal = produzirComandoDecimal(posicaoFinal);
      posicaoFinal = 0;
    }

    while (pare)
    {
      if (!digitalRead(botao))
      {
        pare = false;
      }
    }

    if (comandoDecimal != 0)
    {
      if (comandoDecimal == 2220) 
      {
        pare = !pare;
      }
      
      if (comandoDecimal == 2220) //################
      {
        digitalWrite(releDois, !digitalRead(releDois));      //O sinal de exclamação inverte a condição do relé, se estava ligado será desligado e vice versa.
      }
      
      if (comandoDecimal == 2220) //################
      {
        digitalWrite(releTres, !digitalRead(releTres));      //O sinal de exclamação inverte a condição do relé, se estava ligado será desligado e vice versa.
        digitalWrite(bts, LOW);                              //"aperta" o botão do receptor bts (que esta em pull up)
        delay(3000);
        digitalWrite(bts, HIGH);
      }
      
      if (comandoDecimal == 2220) //################
      {
        digitalWrite(bts, LOW);                              //soh "aperta" o botão do receptor bts (sem mexer na caixa de som)
        delay(3000);
        digitalWrite(bts, HIGH);
      }

      piscarComando(comandoDecimal);
      //delay(delayFinal);
      
    }
    

}
