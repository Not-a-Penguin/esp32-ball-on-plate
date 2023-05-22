#ifndef SERIALCOMMESP_H
#define SERIALCOMMESP_H

#include <ArduinoJson.h>
//#include <Arduino>

class SerialComm{

  private:
   
    StaticJsonDocument<64> docFromSerial;
    StaticJsonDocument<64> docToSerial;
  
    bool jsonUpdated = false;
  
  public:

    SerialComm();
    ~SerialComm();
    
    void getJson();

    void sendJson(int xPos, int yPos);
    
    void serializeCurrentJson();
    
    bool jsonUpdateCheck();
    void printCurrentJson();
};
#endif // !SERIALCOMMESP_H

