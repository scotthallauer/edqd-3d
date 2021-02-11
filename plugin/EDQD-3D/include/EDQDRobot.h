/**
 * EDQDRobot
 * =========
 * Represents a EDQD-capable robot in CoppeliaSim
 * 
 * Created on: 10 Feb 2021
 * Author: Scott Hallauer
 */
#include <vector>

#include "EDQD-3D/include/Robot.h"

class EDQDRobot: public Robot {
  
  protected:

    float _backMovementDuration;
    std::vector<float> _backRelativeVelocities;

  public:

		EDQDRobot(int handle, std::vector<int> motorHandles, std::vector<int> sensorHandles, std::vector<float> backRelativeVelocities);
    void setBackMovementDuration(float backMovementDuration);
    float getBackMovementDuration();
    float getBackRelativeVelocity(int motorIndex);

};