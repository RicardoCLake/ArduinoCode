#include "PinoDigital.h"

// Contrutor
// (modo = "pullup" ou "pulldown")
PinoDigital::PinoDigital(int pino, String modo)
{
  this->pino = pino;
  this->modo = modo;  
}

// Decide se no pino há um pulso ou não
bool PinoDigital::ehPulso()
{
  if (modo = "pullup" and digitalRead(this->pino) == 0)
  {
    return true;
  }
  if (modo = "pulldown" and digitalRead(this->pino) == 1)
  {
    return true;
  }
  // else
  return false;
}

// Retorna o número do pino
int PinoDigital::getNumero()
{
  return this->pino;
}