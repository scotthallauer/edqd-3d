#include "EDQD-3D/include/Robot.h"
#include "simLib.h"

Robot::Robot(int handle, int robotHandle, std::vector<int> motorHandles, std::vector<int> sensorHandles) {
	_handle = handle;
  _run = false;
  _robotHandle = robotHandle;
  _motorHandles = motorHandles;
  _sensorHandles = sensorHandles;
}

void Robot::getPosition(float* x, float* y, float* z) {
  // get the absolute position (x, y, z) of the robot 
  float position[3];
  simGetObjectPosition(_robotHandle, -1, position);
  *x = position[0];
  *y = position[1];
  *z = position[2];
}

bool Robot::setTargetVelocitySingleMotor(int motorIndex, float targetVelocity) {
  int result = simSetJointTargetVelocity(_motorHandles[motorIndex], targetVelocity);
  return (result >= 0);
}

bool Robot::setTargetVelocityAllMotors(float targetVelocity) {
  bool success = true;
  for(size_t i = 0; i < _motorHandles.size(); i++) {
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