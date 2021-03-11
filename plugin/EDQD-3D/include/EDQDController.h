#ifndef EDQD_CONTROLLER_H
#define EDQD_CONTROLLER_H

#include "EDQD-3D/include/Controller.h"

class EDQDController: public Controller {

  protected:
    int _iteration;

  public:
    EDQDController(World *world, int robotEntityHandle);
    ~EDQDController() {};
    void reset();
    void step(float timeStep);

};

#endif /* EDQD_CONTROLLER_H */