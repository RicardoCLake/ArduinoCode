#ifndef PINO_H
#define PINO_H

class Pino
{
public:
  Pino(){};
  virtual bool ehPulso()=0;
  virtual int getNumero()=0;
};

#endif //PINO_H