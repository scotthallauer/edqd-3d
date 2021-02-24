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

class Robot {
  
  protected:
    int _handle; // handle is the internal reference to the robot
    bool _run;
    int _robotHandle; // robotHandle is the reference to the robot object in CoppeliaSim
    std::vector<int> _motorHandles;
    std::vector<int> _sensorHandles;

  public:
		Robot(int handle, int robotHandle, std::vector<int> motorHandles, std::vector<int> sensorHandles);
    virtual ~Robot() {};
    int getHandle() { return _handle; };
    int getRobotHandle() { return _robotHandle; };
    void getPosition(float* x, float* y, float* z);
    bool setTargetVelocitySingleMotor(int motorIndex, float targetVelocity);
    bool setTargetVelocityAllMotors(float targetVelocity);
    int readSensor(int sensorIndex);
    void start() { _run = true; };
    void stop() { _run = false; };
    bool isRunning() { return _run; };

};

#endif /* ROBOT_H */