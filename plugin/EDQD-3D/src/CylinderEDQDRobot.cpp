#include "EDQD-3D/include/CylinderEDQDRobot.h"
#include "simLib.h"

CylinderEDQDRobot::CylinderEDQDRobot(World *world, int entityHandle, int bodyHandle, std::vector<int> motorHandles, std::vector<int> sensorHandles, std::vector<float> backRelativeVelocities)
  : EDQDRobot(world, entityHandle, bodyHandle, motorHandles, sensorHandles, backRelativeVelocities) {
  _controller = new CylinderEDQDController(world, entityHandle);
}

CylinderEDQDRobot::~CylinderEDQDRobot() {}

void CylinderEDQDRobot::stepController(float timeStep) {
  this->getController()->step(timeStep);
}