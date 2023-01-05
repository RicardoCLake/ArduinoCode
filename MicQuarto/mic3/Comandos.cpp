#include "Comandos.h"

// Construtor
Comandos::Comandos(Pino* pino, int delayEco, int maximoIntervaloCurto, int maximoIntervaloLongo)
{
  this->pino = pino;
  this->delayEco = delayEco; 
  this->maximoIntervaloCurto = maximoIntervaloCurto; 
  this->maximoIntervaloLongo = maximoIntervaloLongo; 
  this->posicaoFinal = 0;
}

// Faz a leitura de qual comando está sendo inserido
// (deve ser chamada após a detecção do primeiro pulso)
bool Comandos::lerComando() 
{
  posicaoFinal = 0;
  return lerComandoDeVerdade();
}
// Uma vez detectado o primeiro pulso, chama-se essa funcao recursiva
bool Comandos::lerComandoDeVerdade() 
{
  delay(delayEco);
  momentoPalma = millis();
  while (millis() - momentoPalma <= maximoIntervaloLongo)
  {
    if (pino->ehPulso())
    {
      if (millis() - momentoPalma <= maximoIntervaloCurto)
      {
        comando[posicaoFinal] = 1;
      }
      else
      {
        comando[posicaoFinal] = 2;
      }
      posicaoFinal++;
      
      if (posicaoFinal >= MAXIMO_DE_PALMAS - 1)  
      {
        return false;
      }
      // else
      return lerComandoDeVerdade();
    }
  }
  comando[posicaoFinal] = 0;
  return true;
}

// Retorna como unsigned long o comando armazenado 
// (1 é um intervalo curto e 2 eh um intervalo longo)
unsigned long Comandos::getComandoDecimal()
{
  unsigned long temporario = 0;
  unsigned long decimal = 1;
  // Calculo da potencia de dez
  for (int i = 0; i < posicaoFinal; i++)
  {
    decimal *= 10;
  }
  // Multiplicacao da potencia de dez pelo digito
  for (int i = 0; i < posicaoFinal; i++)
  {
    temporario += decimal * comando[i];
    decimal = decimal / 10;
  }
  return temporario;
}