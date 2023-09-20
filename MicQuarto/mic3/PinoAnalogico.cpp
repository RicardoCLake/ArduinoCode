#include "PinoAnalogico.h"

PinoAnalogico::PinoAnalogico(int pino, double limiar, double alpha)
{
  this->pino = pino;
  this->limiar = limiar; 
  this->alpha = alpha;
  this->media = analogRead(pino);
  this->leituraAnterior = analogRead(pino);
}

// Decide se no pino analógico há um pulso ou não
bool PinoAnalogico::ehPulso()
{
  if (float(analogRead(this->pino)) <= media * (1 - limiar) &&
      leituraAnterior <= media * (1 - limiar)) 
  // (Essa segunda condiçao e para evitar grandes flutuaçoes da rede, por exemplo um chuveiro ligado)
  {
    leituraAnterior = analogRead(pino);
    return true;
  }
  else
    leituraAnterior = analogRead(pino); 
    return false;
}

// Atualiza a média movel 
float PinoAnalogico::atualizaMediaMovel()
{
    leituraAnterior = analogRead(pino);
    media = media * (1-alpha) + leituraAnterior * alpha;
    return media;
    
}

// Retorna o número do pino
int PinoAnalogico::getNumero()
{
  return this->pino;
}
