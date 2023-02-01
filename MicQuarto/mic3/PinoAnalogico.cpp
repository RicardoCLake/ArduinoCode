#include "PinoAnalogico.h"

PinoAnalogico::PinoAnalogico(int pino, double limiar, double alpha)
{
  this->pino = pino;
  this->limiar = limiar; 
  this->alpha = alpha;
  this->media = analogRead(pino);  
}

// Decide se no pino analógico há um pulso ou não
bool PinoAnalogico::ehPulso()
{
  if (float(analogRead(this->pino)) <= media * (1 - limiar))
  {
    return true;
  }
  else 
    return false;
}

// Atualiza a média movel 
float PinoAnalogico::atualizaMediaMovel()
{
    media = media * (1-alpha) + analogRead(pino) * alpha;
    return media;
    
}

// Retorna o número do pino
int PinoAnalogico::getNumero()
{
  return this->pino;
}
