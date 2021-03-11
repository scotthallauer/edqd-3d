#include "EDQD-3D/include/EDQDController.h"

EDQDController::EDQDController(World *world, int robotEntityHandle)
  : Controller(world, robotEntityHandle) {
	_iteration = 0;
}

void EDQDController::reset() {
  _iteration = 0;
}

void EDQDController::step(float timeStep) {
  _iteration++;
}