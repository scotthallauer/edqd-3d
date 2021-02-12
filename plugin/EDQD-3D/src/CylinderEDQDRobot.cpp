#include "EDQD-3D/include/CylinderEDQDRobot.h"
#include "simLib.h"

CylinderEDQDRobot::CylinderEDQDRobot(int handle, std::vector<int> motorHandles, std::vector<int> sensorHandles, std::vector<float> backRelativeVelocities)
  : EDQDRobot(handle, motorHandles, sensorHandles, backRelativeVelocities) {
}

CylinderEDQDRobot::~CylinderEDQDRobot() {}

void CylinderEDQDRobot::stepController(float timeStep) {
  if (this->isRunning())
  { // movement mode
    if (this->readSensor(3)>0)
      this->setBackMovementDuration(3.0f); // we detected an obstacle, we move backward for 3 seconds
    if (this->getBackMovementDuration()>0.0f)
    { // We move backward
      this->setTargetVelocitySingleMotor(0, -7.0f*this->getBackRelativeVelocity(0));
      this->setTargetVelocitySingleMotor(1, -7.0f*this->getBackRelativeVelocity(1));
      this->setBackMovementDuration(this->getBackMovementDuration()-timeStep);
    }
    else
    { // We move forward
      this->setTargetVelocityAllMotors(7.0f);
    }
  }
}