/**
 * Robot
 * =====
 * Represents a robot in CoppeliaSim
 * 
 * Created on: 3 Feb 2021
 * Author: Scott Hallauer
 */
#include <vector>

class Robot {
  
  protected:

    int _handle;
    bool _run;
    std::vector<int> _motorHandles;
    std::vector<int> _sensorHandles;

  public:

		Robot(int handle, std::vector<int> motorHandles, std::vector<int> sensorHandles);
    int getHandle();
    bool setTargetVelocitySingleMotor(int motorIndex, float targetVelocity);
    bool setTargetVelocityAllMotors(float targetVelocity);
    int readSensor(int sensorIndex);
    void start();
    void stop();
    bool isRunning();

};