#include "touchScreen.h"

//upper left - upper right - lower left- lower right - input
TouchScreen ts(27, 26, 32, 33, 25);

screenCoordinates coords;

void setup() { 

  Serial.begin(115200);
  Serial.println("Esp starting");
  ts.setScreenDelay(30);
 
}

void loop() {

  coords = ts.getCoordinates();

  if(ts.screenUpdated()){

    Serial.print("X: "); Serial.println(coords.x);
    Serial.print("Y: "); Serial.println(coords.y);
    Serial.println("---------------------------------");

  }


}
