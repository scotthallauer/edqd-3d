#include "EDQD-3D/include/Robot.h"
#include "simLib.h"

Robot::Robot(int handle, std::vector<int> motorHandles, std::vector<int> sensorHandles) {
	_handle = handle;
  _run = false;
  _motorHandles = motorHandles;
  _sensorHandles = sensorHandles;
}

int Robot::getHandle() {
  return _handle;
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