//Nova versão do código para o arduido do meu quarto
// Nessa versão foram inseridas opções mais complexas de comandos com palmas
// e foi trocado o microfone simples para versão em módulo digital

#include "Pino.h"
#include "PinoAnalogico.h"
#include "PinoDigital.h"
#include "Comandos.h"

/**************************** DEFINIÇÕES ***************************************/
// Os números associados a cada variável seguem o guia de conexões e representam as portas digitais usadas.
#define bts 18        //receptor bluetooth
#define releUm 2     //vazio
#define releDois 4   //relê da iluminação
#define releTres 6   //relê do som
#define releQuatro 2 // vazio
#define botao 16     //entrada digital
#define led 13       // saída visual (avisos)
#define mic 14       //entrada do mic


//Definicoes para o pino de leitura do mic
#define LIMIAR_ANALOGICO 1.7 // em porcertagem da média móvel em baixa
#define ALPHA 0.1

//Definições temporais das palmas
const int duracaoEcoPalma = 250;    //Valor representa um tempo em milissegundos, é o tempo que dura o som de uma palma, precisa ser calibrado entre 100 e 250.
const int duracaoEcoBotao = 250;    //Valor representa um tempo em milissegundos, é o tempo que dura o pulso de um botão.
const int maximoIntervaloCurto = 300;     //Em milissegundos, duração considerada curta entre duas palmas
const int maximoIntervaloLongo = 600;     //Em milissegundos, duração considerada longa entre duas palmas

//Definicao do loop
const int delayfinal = 100;       //Valor representa um tempo em milissegundos, esse tempo é aguardado pelo programa para que se inicie novamente o loop.

/************************** VARIÁVEIS AUXILIARES *********************************/
bool pare = false;                //condição para congelar o sistema
unsigned long comandoDecimal = 0;         //Comando em formato de numero decimal
PinoAnalogico* pinoMic = new PinoAnalogico(mic, LIMIAR_ANALOGICO, ALPHA);
Comandos* comandoMic   = new Comandos(pinoMic, duracaoEcoPalma, maximoIntervaloCurto, maximoIntervaloLongo);
PinoDigital* pinoBotao = new PinoDigital(botao, "pullup");
Comandos* comandoBotao = new Comandos(pinoBotao, duracaoEcoBotao, maximoIntervaloCurto, maximoIntervaloLongo);

/*************************** FUNÇÕES AUXILIARES *************************************/
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
      delay(maximoIntervaloCurto);
    }
    if (palma == 2)
    {
      digitalWrite(led, HIGH);
      delay(duracaoEcoPalma);
      digitalWrite(led, LOW);
      delay(maximoIntervaloLongo);
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
  // Atualizacoes
  pinoMic->atualizaMediaEmBaixa();
  comandoDecimal = 0;

  // Se for detectado um pulso inicial no microfone
  if (pinoMic->ehPulso())
  {
    // Se conseguir ler o comando
    if (comandoMic->lerComando())
    {
      comandoDecimal = comandoMic->getComandoDecimal();
    }
  }

  // Se for detectado um pulso inicial no botao
  if (pinoBotao->ehPulso())
  {
    // Se conseguir ler o comando
    if (comandoBotao->lerComando())
    {
      comandoDecimal = comandoBotao->getComandoDecimal();
    }
  }

  //Se entrar no modo de congelamento
  while (pare)
  {
    // Basta apertar o botao para sair
    if (pinoBotao->ehPulso())
    {
      pare = false;
    }
  }

  // Escolha do que realizar com o comando lido
  if (comandoDecimal != 0)
  {
    // Congelamento
    if (comandoDecimal == 21210) 
    {
      pare = !pare;
    }
    
    // Iluminacao
    if (comandoDecimal == 210) //################
    {
      digitalWrite(releDois, !digitalRead(releDois));      //O sinal de exclamação inverte a condição do relé, se estava ligado será desligado e vice versa.
    }
    
    // Som 
    if (comandoDecimal == 120) //################
    {
      digitalWrite(releTres, !digitalRead(releTres));      //O sinal de exclamação inverte a condição do relé, se estava ligado será desligado e vice versa.
      digitalWrite(bts, LOW);                              //"aperta" o botão do receptor bts (que esta em pull up)
      delay(3000);
      digitalWrite(bts, HIGH);
    }
    
    // Reset do bts
    if (comandoDecimal == 1210) //################
    {
      digitalWrite(bts, LOW);                              //soh "aperta" o botão do receptor bts (sem mexer na caixa de som)
      delay(3000);
      digitalWrite(bts, HIGH);
    }

    // Pisca no led o comando executado para conferir
    piscarComando(comandoDecimal);
    //delay(delayFinal);
    
  }
    

}
