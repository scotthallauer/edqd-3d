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

class Controller {

	public:
		Controller() {};
    virtual ~Controller() {};
		virtual void reset() = 0;
		virtual void step() = 0;

};

#endif /* CONTROLLER_H */