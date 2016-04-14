#define BEACON_WOKRING false
#define USE_DEFAULT_COMPASS_DIRECTION false

#define SERIAL_PRINT true

#define DEFAULT_BEACON_HEADING 240.0 // Assume that beacon is there, if x-bee doesn't work or is not on.

#define DECLINATION_ANGLE 0.0457 // use ... for the competition
 
#define OUTPUT_PIN 12

volatile float beacon_heading;

// Out setup routine, here we will configure the microcontroller and compass.
void setup()
{
  // Initialize the serial port.

  if (SERIAL_PRINT) {
      Serial.begin (9600);
  }
  
  Set_Up_Compass ();

  if (BEACON_WOKRING) {
      Set_Up_Beacon ();
  }

  beacon_heading = DEFAULT_BEACON_HEADING;

  if (!BEACON_WOKRING && !USE_DEFAULT_COMPASS_DIRECTION) {
    int averaging_number = 10;
    beacon_heading = 0;
      
    for (int i = 0; i < averaging_number; i++) {
      beacon_heading += Get_Compass_Heading();
      delay(50);
    }

    beacon_heading /= averaging_number;

    if (SERIAL_PRINT) {
      Serial.print ("I setup my heading to be: ");
      Serial.println(beacon_heading);
    }
  }
  
  Set_Up_Timer ();
}

// Our main program loop.
void loop()
{
  if (BEACON_WOKRING) { 
    Update_Beacon_Direction ();

    if (SERIAL_PRINT) {
      Serial.print ("Updated beacon heading: ");
      Serial.println (beacon_heading);
    }
  }
  delay(100);
}
