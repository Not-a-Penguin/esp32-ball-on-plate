#ifndef TOUCHSCREEN_H
#define TOUCHSCREEN_H

#define TOUCHSCREEN_H

/*
 * Library for interfacing with a 5-wire resistive touchScreen. 
 */

//definition of struct where the current values of x and y will be stored:
struct screenCoordinates{
  int x = 0;
  int y = 0;  
};

class TouchScreen{

  private:

    //functions

    //Analog read of specified axis. Also takes care of setting the correct pins HIGH or LOW
    int readCoordinate(String coordinate);
    void alternateReading();
    void setPins();

    //variables for calculating when the screen should be read
    int _interval= 30; //in milliseconds -> can be set in setScreenDelay()
    unsigned long _previousMillis = 0;

    screenCoordinates _currentScreenCoordinates;
  
    //Signals when a new reading of the coordinates has been made
    bool _newReading;

    //Variables for the digital pins corresponding to the four corners of the display.
    int _upperLeftPin;
    int _upperRightPin;
    
    int _lowerLeftPin;
    int _lowerRightPin;

    //ADC
    //The middle pin of the display which corresponds to the analog value of the voltage divider when there
    //is a voltage gradient in the screen
    int _sensorPin; 

  public:

    TouchScreen(int upperLeft, int upperRight, int lowerLeft, int lowerRight, int sensorPin);
    ~TouchScreen();

    screenCoordinates getCoordinates();
    void setScreenDelay(int milliseconds);
    bool screenUpdated();

    
};
#endif // !TOUCHSCREEN_H
