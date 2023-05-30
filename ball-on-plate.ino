#include "serialCommEsp.h"
#include "touchScreen.h"
#include "servoControl.h"

ServoControl servos(12, 13, 14);
TouchScreen ts(27, 26, 32, 33, 25);
SerialComm serial;

screenCoordinates coords;

void setup() {

  Serial.begin(115200);
  Serial.println("Esp start");
  // servos.moveServo(3, 100);
  ts.setScreenDelay(30);
  Serial.println("End of setup");
}

void loop() {

  coords = ts.getCoordinates();

  if(ts.screenUpdated()){
    serial.sendJson(coords.x, coords.y);
    Serial.println();
  }
  
  serial.getJson();
  if(serial.jsonUpdateCheck()){
    servos.moveServos(
      serial.docFromSerial["servo1"].as<int>(), 
      serial.docFromSerial["servo2"].as<int>(), 
      serial.docFromSerial["servo3"].as<int>()); 
  }

}
