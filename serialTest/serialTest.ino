#include "serialCommEsp.h"


SerialComm serial;

float i = 0;

unsigned long currentMillis = millis();
unsigned long previousMillis = 0;
int interval = 2000;

void setup() {
  Serial.begin(115200);
  Serial.println("Starting ESP32");
  serial.sendJson(0,0);
}

// Loop forever
void loop() {

  currentMillis = millis();

  if(currentMillis - previousMillis > interval){

    //Call sendJson() with the proper arguments (defined in the class)
    serial.sendJson(10*sin(i), 10*cos(i));
    Serial.println();
    i += 0.1;
    previousMillis = currentMillis;
  }

  //Get json from serial and print it to screen
  serial.getJson();
  if(serial.jsonUpdateCheck()){
    // serial.printCurrentJson();
  }
}
