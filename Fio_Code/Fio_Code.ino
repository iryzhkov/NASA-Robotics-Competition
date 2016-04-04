// Reference the I2C Library
#include <Wire.h>
#include <HMC5883L.h>

#define BEACON_WOKRING false
#define DEFAULT_BEACON_HEADING 180.0

#define DECLINATION_ANGLE 0.0457 // use ... for the competition

#define OUTPUT_PIN 12;

// Store our compass as a variable.
HMC5883L compass;
int compass_error = 0;

float volatile beacon_heading;

// Out setup routine, here we will configure the microcontroller and compass.
void setup()
{
  // Initialize the serial port.
  Serial.begin(9600);
  Set_Up_Compass ();
  Set_Up_Timer ();
}

// Our main program loop.
void loop()
{
  if (BEACON_WOKRING) { 
  }
  else {
    Set_Beacon_Heading(DEFAULT_BEACON_HEADING);
  }
}

void Set_Beacon_Heading (float new_heading) {
  cli();
  beacon_heading = new_heading;
  sei();
}

int Get_Turning_Side () {
  return 0; 
}

