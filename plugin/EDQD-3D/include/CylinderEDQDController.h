#ifndef CYLINDER_EDQD_CONTROLLER_H
#define CYLINDER_EDQD_CONTROLLER_H

#include "EDQD-3D/include/EDQDController.h"

class CylinderEDQDController: public EDQDController {

  public:
    CylinderEDQDController(World *world, int robotEntityHandle);
    ~CylinderEDQDController() {};
    void step(float timeStep);

};

#endif /* CYLINDER_EDQD_CONTROLLER_H */