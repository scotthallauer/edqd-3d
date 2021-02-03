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
  
  private:

    int _handle;
    bool _run;
    float _backMovementDuration;
    std::vector<int> _motorHandles;
    std::vector<int> _sensorHandles;
    std::vector<float>_backRelativeVelocities;

  public:

		Robot(int handle, std::vector<int> motorHandles, std::vector<int> sensorHandles, std::vector<float> backRelativeVelocities);
    int getHandle();
    void setBackMovementDuration(float backMovementDuration);
    float getBackMovementDuration();
    float getBackRelativeVelocity(int motorIndex);
    bool setTargetVelocitySingleMotor(int motorIndex, float targetVelocity);
    bool setTargetVelocityAllMotors(float targetVelocity);
    int readSensor(int sensorIndex);
    void start();
    void stop();
    bool isRunning();

};