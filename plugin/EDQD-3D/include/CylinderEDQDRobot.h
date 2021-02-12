/**
 * CylinderEDQDRobot
 * =================
 * Represents a cylindrical, EDQD-capable robot in CoppeliaSim
 * 
 * Created on: 11 Feb 2021
 * Author: Scott Hallauer
 */
#include <vector>

#include "EDQD-3D/include/EDQDRobot.h"

class CylinderEDQDRobot: public EDQDRobot {
  
  protected:

  public:

		CylinderEDQDRobot(int handle, std::vector<int> motorHandles, std::vector<int> sensorHandles, std::vector<float> backRelativeVelocities);
    void stepController(float timeStep);

};