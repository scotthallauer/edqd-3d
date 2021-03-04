/**
 * CylinderEDQDRobot
 * =================
 * Represents a cylindrical, EDQD-capable robot in CoppeliaSim
 * 
 * Created on: 11 Feb 2021
 * Author: Scott Hallauer
 */

#ifndef CYLINDER_EDQD_ROBOT_H
#define CYLINDER_EDQD_ROBOT_H

#include <vector>

#include "EDQD-3D/include/EDQDRobot.h"

class CylinderEDQDRobot: public EDQDRobot {
  
  protected:

  public:
		CylinderEDQDRobot(int entityHandle, int bodyHandle, std::vector<int> motorHandles, std::vector<int> sensorHandles, std::vector<float> backRelativeVelocities);
    virtual ~CylinderEDQDRobot();
    void stepController(float timeStep);

};

#endif /* CYLINDER_EDQD_ROBOT_H */