#define BEACON_WOKRING false
#define DEFAULT_BEACON_HEADING 180.0

#define DECLINATION_ANGLE 0.0457 // use ... for the competition

#define OUTPUT_PIN 12

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
    Update_Beacon_Direction ();
  }
  else {
    cli();
    beacon_heading = DEFAULT_BEACON_HEADING;
    sei();
  }
}
