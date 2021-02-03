#include "EDQD-3D/include/Robot.h"
#include "simLib.h"

Robot::Robot(int handle, std::vector<int> motorHandles, std::vector<int> sensorHandles, std::vector<float> backRelativeVelocities) {
	_handle = handle;
  _run = false;
  _backMovementDuration = 0.0f;
  _backRelativeVelocities = backRelativeVelocities;
  _motorHandles = motorHandles;
  _sensorHandles = sensorHandles;
}

int Robot::getHandle() {
  return _handle;
}

void Robot::setBackMovementDuration(float backMovementDuration) {
  _backMovementDuration = backMovementDuration;
}

float Robot::getBackMovementDuration() {
  return _backMovementDuration;
}

float Robot::getBackRelativeVelocity(int motorIndex) {
  return _backRelativeVelocities[motorIndex];
}

bool Robot::setTargetVelocitySingleMotor(int motorIndex, float targetVelocity) {
  int result = simSetJointTargetVelocity(_motorHandles[motorIndex], targetVelocity);
  return (result >= 0);
}

bool Robot::setTargetVelocityAllMotors(float targetVelocity) {
  bool success = true;
  for(int i = 0; i < _motorHandles.size(); i++) {
    if(!setTargetVelocitySingleMotor(i, targetVelocity)) {
      success = false;
    }
  }
  return success;
}

int Robot::readSensor(int sensorIndex) {
  int result = simReadProximitySensor(_sensorHandles[sensorIndex], NULL, NULL, NULL);
  return result;
}

void Robot::start() {
  simAuxiliaryConsolePrint(0,"simExtEDQDRobot: We're running!\n");
  _run = true;
}

void Robot::stop() {
  _run = false;
}

bool Robot::isRunning() {
  return _run;
}