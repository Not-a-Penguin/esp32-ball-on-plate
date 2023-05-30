#include "serialCommEsp.h"

SerialComm::SerialComm(){
  
};

SerialComm::~SerialComm(){};

//Receives a json from the serial port. This method stores the key pairs in the docFromSerial atribute
//You must access them or put them into your own variables yourself
void SerialComm::getJson(){

  if(Serial.available() > 2){

    DeserializationError err = deserializeJson(this->docFromSerial, Serial);

    if(err == DeserializationError::Ok){
      this->jsonUpdated = true; 
    }
    else{
        Serial.print(F("deserializeJson() failed: "));
        Serial.println(err.f_str());
        while (Serial.available() > 0){
        Serial.read();
      };
    }
  }

};

void SerialComm::sendJson(float xPos, float yPos){

  //Modify method argument to properly build json
  this->docToSerial["xPos"] = xPos;
  this->docToSerial["yPos"] = yPos;
  serializeJson(this->docToSerial, Serial);
};

bool SerialComm::jsonUpdateCheck(){
  if(this->jsonUpdated == true){
    this->jsonUpdated = false;
    return true;
  } else return false;
};

void SerialComm::printCurrentJson(){

  //Adapt to your json
  Serial.println("Got these from serial:");

  Serial.print("Servo 1:"); Serial.println(this->docFromSerial["servo1"].as<int>());
  Serial.print("Servo 2:"); Serial.println(this->docFromSerial["servo2"].as<int>());
  Serial.print("Servo 3:"); Serial.println(this->docFromSerial["servo3"].as<int>());
  Serial.println("--------------------------------------------------------------------");
};

