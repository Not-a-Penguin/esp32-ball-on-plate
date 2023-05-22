#include "serialCommEsp.h"

SerialComm::SerialComm(){
  
};

SerialComm::~SerialComm(){};


//Not working yet (but will soon!)
void SerialComm::getJson(){

  if(Serial.available() > 0){

    DeserializationError err = deserializeJson(this->docFromSerial, Serial);

    if(err == DeserializationError::Ok){
      this->jsonUpdated = true;      
    }
    else{
        while (Serial.available() > 0){
        Serial.read();
      };
    }
  }

};

void SerialComm::sendJson(int xPos, int yPos){

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
  Serial.println("Print Current Json function not implemented.");
};

