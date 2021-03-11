#include "EDQD-3D/include/Controller.h"

Controller::Controller(World *world, int robotEntityHandle) {
	_world = world;
  _robotEntityHandle = robotEntityHandle;
}