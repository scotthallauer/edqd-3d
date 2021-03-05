#include "EDQD-3D/include/EDQDController.h"

EDQDController::EDQDController() {
	_iteration = 0;
}

void EDQDController::reset() {
  _iteration = 0;
}

void EDQDController::step() {
  _iteration++;
}