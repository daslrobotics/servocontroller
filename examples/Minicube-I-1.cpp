#include "TestBase.h"

class Example : public TestBase
{
  public:
    Example(string envfile,string controller,bool showgui=true) :
       TestBase(envfile,controller,showgui) {};
    void run(dReal step, bool realtime=true);
};

void Example::run(dReal step, bool realtime)
{
  stringstream os,is;
  is << "setamplitude 50 50 ";
  pcontroller->SendCommand(os,is);

  is << "setinitialphase 0 120 ";
  pcontroller->SendCommand(os,is);

  is << "setoffset 0 0 ";
  pcontroller->SendCommand(os,is);

  is << "setperiod 1.5 ";
  pcontroller->SendCommand(os,is);

  is << "oscillation on ";
  pcontroller->SendCommand(os,is);

  penv->StartSimulation(step);

  while(1);
}

int main(void)
{
  Example example("models/Minicube-I.env.xml","sinoscontroller");
  usleep(100000);
  example.SetCamera(0.427, 0.285, 0.47, 0.718, 0.59, 0.078, 0.263);
  example.run(0.005);

  return 0;
}

