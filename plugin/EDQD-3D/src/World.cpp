#include "EDQD-3D/include/World.h"

World::World() {
  _iterations = 0;
}

Robot* World::getRobot(int index) {
  return _robots[index];
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