#ifndef COMANDOS_H
#define COMANDOS_H

#include "PinoAnalogico.h"
#define MAXIMO_DE_PALMAS 6 //número máximo de palmas em um comando

class Comandos
{
public:
  Comandos(Pino* pino, int delayEco, int maximoIntervaloCurto, int maximoIntervaloLongo);
  ~Comandos();
  bool lerComando();
  unsigned long getComandoDecimal();
  int getMaximoDePalmas();
  int* getComandoVetor();
  
private:
  // Variáveis do construtor
  Pino* pino;
  int delayEco;           //Delay para aguardar a reestabilização do pino de leitura
  int maximoIntervaloCurto;     //Em milissegundos, maxima duração considerada curta entre duas palmas
  int maximoIntervaloLongo;     //Em milissegundos, maxima duração considerada longa entre duas palmas
  // Variáveis auxiliares 
  long momentoPalma = 0;   //Marcador usado para a detecção das palmas, será utilizado junto com a função millis.
  // Armazenamento do comando
  int posicaoFinal = 0;    //posicao no vetor de comandos
  int comando[MAXIMO_DE_PALMAS] = {0};       //Sequencia de comandos (palmas curtas e longas)
  bool lerComandoDeVerdade();
};

#endif //COMANDOS_H
