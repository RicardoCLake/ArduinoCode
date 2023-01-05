#include "Pino.h"

#ifndef PINODIGITAL_H
#define PINODIGITAL_H

#include <Arduino.h>

class PinoDigital : public Pino
{
public:
  PinoDigital(int pino, String modo);
  bool ehPulso();
  int getNumero();

private:
  int pino;
  String modo; //"pullup" ou "pulldown"
};

#endif //PINODIGITAL_H