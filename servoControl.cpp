#include "servoControl.h"

ServoControl::ServoControl(int servo1Pin, int servo2Pin, int servo3Pin){

  this->servo1.attach(servo1Pin);
  this->servo2.attach(servo2Pin);
  this->servo3.attach(servo3Pin);

}

ServoControl::~ServoControl(){/* :^) */}

void ServoControl::startPosition(){
  
  this->servo1.write(90);
  this->servo2.write(90);
  this->servo3.write(90);

}

void ServoControl::moveServo(int servo, int angle){
  
  Serial.println("Inside moveServo()");
  this->checkAngleSafety(&angle); 
  this->servos[servo-1].write(angle);
}

void ServoControl::moveServos(int angle1, int angle2, int angle3){
  
  this->checkAngleSafety(&angle1);
  this->checkAngleSafety(&angle2);
  this->checkAngleSafety(&angle3);

  this->servo1.write(angle1);
  this->servo2.write(angle2);
  this->servo3.write(angle3);
}

void ServoControl::checkAngleSafety(int* angle){
  if(*angle < this->lowerAngleLimit){
    *angle = this->lowerAngleLimit;
    Serial.println("Exceeds lower limit");
  }
  else if(*angle > this->upperAngleLimit){
    *angle = this->upperAngleLimit;
    Serial.println("Exceeds upper limit");
  }
}
