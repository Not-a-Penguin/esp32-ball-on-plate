#ifndef SERIALCOMMESP_H
#define SERIALCOMMESP_H

#include <ArduinoJson.h>
//#include <Arduino>

class SerialComm{

  private:
   
    StaticJsonDocument<64> docToSerial;
  
    bool jsonUpdated = false;
  
  public:

    SerialComm();
    ~SerialComm();
    
    void getJson();

    void sendJson(float xPos, float yPos);
    
    void serializeCurrentJson();
    
    bool jsonUpdateCheck();
    void printCurrentJson();

    StaticJsonDocument<128> docFromSerial;
};
#endif // !SERIALCOMMESP_H

