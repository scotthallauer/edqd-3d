/**
 * EDQDRobot
 * =========
 * Represents a EDQD-capable robot in CoppeliaSim
 * 
 * Created on: 10 Feb 2021
 * Author: Scott Hallauer
 */

#ifndef EDQD_ROBOT_H
#define EDQD_ROBOT_H

#include <vector>

#include "EDQD-3D/include/Robot.h"
#include "EDQD-3D/include/EDQDController.h"

class EDQDRobot: public Robot {
  
  protected:
    float _backMovementDuration;
    std::vector<float> _backRelativeVelocities;

  public:
		EDQDRobot(World *world, int entityHandle, int bodyHandle, std::vector<int> motorHandles, std::vector<int> sensorHandles, std::vector<float> backRelativeVelocities);
    virtual ~EDQDRobot();
    EDQDController* getController() { return (EDQDController*)Robot::getController(); }
    void setBackMovementDuration(float backMovementDuration);
    float getBackMovementDuration();
    float getBackRelativeVelocity(int motorIndex);

};

#endif /* EDQD_ROBOT_H */