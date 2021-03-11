#include "EDQD-3D/include/EDQDRobot.h"

EDQDRobot::EDQDRobot(World *world, int entityHandle, int bodyHandle, std::vector<int> motorHandles, std::vector<int> sensorHandles, std::vector<float> backRelativeVelocities)
  : Robot(world, entityHandle, bodyHandle, motorHandles, sensorHandles) {
  _controller = new EDQDController(world, entityHandle);
  _backMovementDuration = 0.0f;
  _backRelativeVelocities = backRelativeVelocities;
}

EDQDRobot::~EDQDRobot() {}

void EDQDRobot::setBackMovementDuration(float backMovementDuration) {
  _backMovementDuration = backMovementDuration;
}

float EDQDRobot::getBackMovementDuration() {
  return _backMovementDuration;
}

float EDQDRobot::getBackRelativeVelocity(int motorIndex) {
  return _backRelativeVelocities[motorIndex];
}