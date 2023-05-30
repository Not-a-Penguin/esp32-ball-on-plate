#ifndef SERVOCONTROL_H
#define SERVOCONTROL_H

#include <ESP32Servo.h>

class ServoControl{

  public:

    ServoControl(int servo1Pin, int servo2Pin, int servo3Pin);
    ~ServoControl();
    
    void startPosition();
    void moveServos(int angle1, int angle2, int angle3);
    void moveServo(int servo, int angle);

  private:

    Servo servo1;
    Servo servo2;
    Servo servo3;

    Servo servos[3] = {servo1, servo2, servo3};
    
    //Safety limits
  
    int lowerAngleLimit = 10;
    int upperAngleLimit = 140;

    void checkAngleSafety(int* angle);
};

#endif
