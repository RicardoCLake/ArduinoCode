#include "PinoAnalogico.h"

// Contrutor
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
    //Serial.print("EH PULSO NO PINO ");
    //Serial.println(this->pino);
    return true;
  }
  else 
    //Serial.print("NAO EH PULSO NO PINO ");
    //Serial.println(this->pino);
    return false;
}

// Atualiza a média movel 
void PinoAnalogico::atualizaMediaMovel()
{
  if (this->ehPulso() == false) 
  {
    media = media * (1-alpha) + analogRead(pino) * alpha;
  }
}

// Retorna o número do pino
int PinoAnalogico::getNumero()
{
  return this->pino;
}
