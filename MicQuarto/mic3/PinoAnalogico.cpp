#include "PinoAnalogico.h"

// Contrutor
PinoAnalogico::PinoAnalogico(int pino, double limiar, double alpha)
{
  this->pino = pino;
  this->limiar = limiar; 
  this->alpha = alpha;
  this->mediaEmBaixa = analogRead(pino);  
}

// Decide se no pino analógico há um pulso ou não
bool PinoAnalogico::ehPulso()
{
  if (float(analogRead(this->pino)) >= mediaEmBaixa * limiar)
  {
    return true;
  }
  else 
    return false;
}

// Atualiza a média movel em baixa tensao
void PinoAnalogico::atualizaMediaEmBaixa()
{
  if (this->ehPulso() == false) 
  {
    mediaEmBaixa = mediaEmBaixa * (1-alpha) + analogRead(pino) * alpha;
  }
}

// Retorna o número do pino
int PinoAnalogico::getNumero()
{
  return this->pino;
}