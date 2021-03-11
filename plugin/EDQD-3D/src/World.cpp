#include "EDQD-3D/include/World.h"
#include "EDQD-3D/include/Robot.h"

World::World() {
  _iterations = 0;
}

Robot* World::getRobotByIndex(int index) {
  return _robots[index];
}

Robot* World::getRobotByHandle(int entityHandle) {
  for(int i = 0; i < getNbOfRobots(); i++) {
    if (_robots[i]->getEntityHandle() == entityHandle)
      return _robots[i];
  }
  throw "No robot exists with the specified entity handle.";
}

void World::addRobot(Robot *robot) {
  _robots.push_back(robot);
}

void World::deleteRobot(int index) {
  _robots.erase(_robots.begin()+index);
}

void World::clearRobots() {
  _robots.clear();
}

int World::getIterations() {
	return _iterations;
}

int World::getNbOfRobots() {
	return (int)_robots.size();
}