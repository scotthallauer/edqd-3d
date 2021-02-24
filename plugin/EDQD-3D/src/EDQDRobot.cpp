#include "EDQD-3D/include/EDQDRobot.h"

EDQDRobot::EDQDRobot(int handle, int robotHandle, std::vector<int> motorHandles, std::vector<int> sensorHandles, std::vector<float> backRelativeVelocities)
  : Robot(handle, robotHandle, motorHandles, sensorHandles) {
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