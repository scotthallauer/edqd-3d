#include "EDQD-3D/include/CylinderEDQDRobot.h"
#include "EDQD-3D/include/CylinderEDQDController.h"
#include "EDQD-3D/include/World.h"

CylinderEDQDController::CylinderEDQDController(World *world, int robotEntityHandle)
  : EDQDController(world, robotEntityHandle) {
}

void CylinderEDQDController::step(float timeStep) {
  EDQDController::step(timeStep);
  CylinderEDQDRobot* robot = (CylinderEDQDRobot*)_world->getRobotByHandle(_robotEntityHandle);
  if (robot->isRunning())
  { // movement mode
    if (robot->readSensor(3)>0)
      robot->setBackMovementDuration(3.0f); // we detected an obstacle, we move backward for 3 seconds
    if (robot->getBackMovementDuration()>0.0f)
    { // We move backward
      robot->setTargetVelocitySingleMotor(0, -7.0f*robot->getBackRelativeVelocity(0));
      robot->setTargetVelocitySingleMotor(1, -7.0f*robot->getBackRelativeVelocity(1));
      robot->setBackMovementDuration(robot->getBackMovementDuration()-timeStep);
    }
    else
    { // We move forward
      robot->setTargetVelocityAllMotors(7.0f);
    }
  }
}