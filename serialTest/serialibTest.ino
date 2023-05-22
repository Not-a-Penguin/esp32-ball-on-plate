// Return the returns the character received on Serial after capitalizing it
// More details on:
// https://lucidar.me/en/serialib/cross-plateform-rs232-serial-library/

#include "serialCommEsp.h"

SerialComm serial;

void setup() {
  Serial.begin(115200);
  Serial.println("Starting ESP32");
  serial.sendJson(0,0);
}

// Loop forever
void loop() {

  //Call sendJson() with the proper arguments (defined in the class)
  serial.sendJson(random(1, 100), random(101, 200));
  Serial.println();
  delay(500);

  //TODO: implement getJson();
}