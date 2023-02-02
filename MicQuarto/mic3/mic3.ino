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
#define releDois 6   //relê da iluminação
#define releTres 4   //relê do som
#define releQuatro 2 // vazio
#define botao 16     //entrada digital
#define led 13       // saída visual (avisos)
#define mic 14       //entrada do mic

//Definicoes para o pino de leitura do mic
#define LIMIAR_ANALOGICO 0.019 // em porcertagem da média móvel 
#define ALPHA 0.02

//Definições temporais das palmas
const int duracaoEcoPalma = 170;    //Valor representa um tempo em milissegundos, é o tempo que dura o som de uma palma, precisa ser calibrado entre 100 e 250.
const int duracaoEcoBotao = 170;    //Valor representa um tempo em milissegundos, é o tempo que dura o pulso de um botão.
const int maximoIntervaloCurto = 350;     //Em milissegundos, duração considerada curta entre duas palmas
const int maximoIntervaloLongo = 900;     //Em milissegundos, duração considerada longa entre duas palmas

//Definicao do loop
const int delayfinal = 30;       //Valor representa um tempo em milissegundos, esse tempo é aguardado pelo programa para que se inicie novamente o loop.

/************************** VARIÁVEIS AUXILIARES *********************************/
bool pare = false;                //condição para congelar o sistema
unsigned long comandoDecimal = 0;         //Comando em formato de numero decimal
int* comandoVetorial;
PinoAnalogico* pinoMic = new PinoAnalogico(mic, LIMIAR_ANALOGICO, ALPHA);
Comandos* comandoMic   = new Comandos(pinoMic, duracaoEcoPalma, maximoIntervaloCurto, maximoIntervaloLongo);
PinoDigital* pinoBotao = new PinoDigital(botao, "pullup");
Comandos* comandoBotao = new Comandos(pinoBotao, duracaoEcoBotao, maximoIntervaloCurto, maximoIntervaloLongo);

/*************************** FUNÇÕES AUXILIARES *************************************/
void piscarComando(unsigned long nComando, int* comando, int sizeOfComando)
{
  int palma = 7;
  delay(400);
  for(int i =0; i <= sizeOfComando && comando[i] != 0; i++)
  {
    palma = comando[i];
    if (palma == 1)
    {
      digitalWrite(led, HIGH);
      delay(maximoIntervaloCurto);
      digitalWrite(led, LOW);
      delay(550);
    }
    if (palma == 2)
    {
      digitalWrite(led, HIGH);
      delay(maximoIntervaloLongo);
      digitalWrite(led, LOW);
      delay(550);
    }
  }
  //digitalWrite(led, HIGH);
  //delay(maximoIntervaloLongo);
  //digitalWrite(led, LOW);
  //delay(duracaoEcoPalma);
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

  Serial.begin(9600);
}

void loop() 
{
  // Atualizacoes
  pinoMic->atualizaMediaMovel();
  comandoDecimal = 0;

  // Se for detectado um pulso inicial no microfone
  if (pinoMic->ehPulso())
  {
    Serial.println("MicComand:");
    // Se conseguir ler o comando
    if (comandoMic->lerComando())
    {
      comandoDecimal = comandoMic->getComandoDecimal();
      comandoVetorial = comandoMic->getComandoVetor();
      Serial.println("c " + String(comandoDecimal) + "\n");
    }
  }

  // Se for detectado um pulso inicial no botao
  if (pinoBotao->ehPulso())
  {
    Serial.println("ButtonComand:");
    // Se conseguir ler o comando
    if (comandoBotao->lerComando())
    {
      comandoDecimal = comandoBotao->getComandoDecimal();
      comandoVetorial = comandoBotao->getComandoVetor();
      Serial.println("c " + String(comandoDecimal) + "\n");
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
      digitalWrite(releDois, !digitalRead(releDois));  
    }
    
    // Som 
    if (comandoDecimal == 120) //################
    {
      digitalWrite(releTres, !digitalRead(releTres));      
      digitalWrite(bts, LOW);                              //"aperta" o botão do receptor bts (que esta em pullup)
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
    piscarComando(comandoDecimal, comandoVetorial, comandoMic->getMaximoDePalmas());
    //delay(delayFinal);
    
  }
    

}
