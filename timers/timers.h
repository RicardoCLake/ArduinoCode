#ifndef TIMERS_H
#define TIMERS_H

class timers
{
private:
  int timerNumber;

public:
  timers(int timerNumber);
  ~timers();
  int start();
  int stop();
  int getNumber();
};

timers::timers(int timerNumber)
{
}

int timers::start()
{
}

int timers::stop()
{
}

timers::~timers()
{
}





#endif 