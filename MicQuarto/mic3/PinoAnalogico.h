#include "Pino.h"

#ifndef PINOANALOGICO_H
#define PINOANALOGICO_H

#include <Arduino.h>

class PinoAnalogico : public Pino
{
public:
  PinoAnalogico(int pino, double limiar, double alpha);
  bool ehPulso();
  float atualizaMediaMovel();
  int getNumero();

private:
  int pino;
  // Auxiliam na detecção de pulso
  float media; //media movel das leituras 
  double limiar;  //porcetagem da média que define se ha um pulso (trash hold de descida)
  double alpha;   //peso do novo valor na media movel
};

#endif //PINOANALOGICO_H
