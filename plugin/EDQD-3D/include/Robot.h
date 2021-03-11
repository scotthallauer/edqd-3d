/**
 * Robot
 * =====
 * Represents a robot in CoppeliaSim
 * 
 * Created on: 3 Feb 2021
 * Author: Scott Hallauer
 */

#ifndef ROBOT_H
#define ROBOT_H

#include <vector>

class Controller;
class World;

class Robot {
  
  protected:
    int _entityHandle; // entityHandle is the internal reference to the robot
    int _bodyHandle; // bodyHandle is the reference to the robot object in CoppeliaSim
    std::vector<int> _motorHandles;
    std::vector<int> _sensorHandles;
    Controller *_controller;
    World *_world;
    bool _run;

  public:
		Robot(World *world, int entityHandle, int bodyHandle, std::vector<int> motorHandles, std::vector<int> sensorHandles);
    virtual ~Robot() {};
    int getEntityHandle() { return _entityHandle; };
    int getBodyHandle() { return _bodyHandle; };
    Controller* getController() { return _controller; };
    World* getWorld() { return _world; };
    void getPosition(float* x, float* y, float* z);
    void setPosition(float x, float y, float z);
    bool setTargetVelocitySingleMotor(int motorIndex, float targetVelocity);
    bool setTargetVelocityAllMotors(float targetVelocity);
    int readSensor(int sensorIndex);
    void start() { _run = true; };
    void stop() { _run = false; };
    bool isRunning() { return _run; };

};

#endif /* ROBOT_H */