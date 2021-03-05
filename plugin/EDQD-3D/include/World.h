/*
 */

#ifndef WORLD_H
#define WORLD_H

#include <vector>

class Robot;

class World {

	protected:
		int _iterations;
    std::vector<Robot*> _robots;

  public:
		World();
		virtual ~World() {};
		Robot* getRobot(int index);
		void addRobot(Robot *robot);
    void deleteRobot(int index);
    void clearRobots();
		int getIterations();
		int getNbOfRobots();
};

#endif // WORLD_H