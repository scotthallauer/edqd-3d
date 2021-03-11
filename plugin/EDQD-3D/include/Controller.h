/**
 * Controller
 * ==========
 * Represents a robot's controller in CoppeliaSim
 * 
 * Created on: 4 Mar 2021
 * Author: Scott Hallauer
 */

#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>

class World;

class Controller {

	protected:
		World *_world;
		int _robotEntityHandle;

	public:
		Controller(World *world, int robotEntityHandle);
    virtual ~Controller() {};
		virtual void reset() = 0;
		virtual void step(float timeStep) = 0;

};

#endif /* CONTROLLER_H */