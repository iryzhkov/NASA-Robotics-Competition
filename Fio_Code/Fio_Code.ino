#define BEACON_WOKRING false
#define DEFAULT_BEACON_HEADING 180.0 // Assume that beacon is there, if x-bee doesn't work or is not on.

#define DECLINATION_ANGLE 0.0457 // use ... for the competition
 
#define OUTPUT_PIN 13

volatile float beacon_heading;

// Out setup routine, here we will configure the microcontroller and compass.
void setup()
{
  // Initialize the serial port.
  Serial.begin (9600);
  Set_Up_Compass ();
  Set_Up_Beacon ();
  Set_Up_Timer ();
}

// Our main program loop.
void loop()
{
  if (BEACON_WOKRING) { 
    Update_Beacon_Direction ();
  }
  else {
    cli();
    beacon_heading = DEFAULT_BEACON_HEADING;
    sei();
  }
  delay (500);
}
