#include "EDQD-3D/include/Robot.h"
#include "simLib.h"

Robot::Robot(World *world, int entityHandle, int bodyHandle, std::vector<int> motorHandles, std::vector<int> sensorHandles) {
  _world = world;
	_entityHandle = entityHandle;
  _bodyHandle = bodyHandle;
  _motorHandles = motorHandles;
  _sensorHandles = sensorHandles;
  _run = false;
}

void Robot::getPosition(float* x, float* y, float* z) {
  // get the absolute position (x, y, z) of the robot 
  float position[3];
  simGetObjectPosition(_bodyHandle, -1, position);
  *x = position[0];
  *y = position[1];
  *z = position[2];
}

void Robot::setPosition(float x, float y, float z) {
  // set the absolute position (x, y, z) of the robot 
  float position[3];
  position[0] = x;
  position[1] = y;
  position[2] = z;
  simSetObjectPosition(_bodyHandle, -1, position);
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