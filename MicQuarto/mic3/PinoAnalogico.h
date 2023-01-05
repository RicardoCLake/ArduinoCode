#include "Pino.h"

#ifndef PINOANALOGICO_H
#define PINOANALOGICO_H

#include <Arduino.h>

class PinoAnalogico : public Pino
{
public:
  PinoAnalogico(int pino, double limiar, double alpha);
  bool ehPulso();
  void atualizaMediaEmBaixa();
  int getNumero();

private:
  int pino;
  // Auxiliam na detecção de pulso
  double mediaEmBaixa; //media movel das leituras em baixa
  double limiar;  //porcetagem da médiaEmBaixa que define se ha um pulso (trash hold)
  double alpha;   //peso do novo valor na media movel
};

#endif //PINOANALOGICO_H