#define BEACON_WOKRING true
#define USE_DEFAULT_COMPASS_DIRECTION false

#define SERIAL_PRINT true

#define DECLINATION_ANGLE 0.150389 // use ... for the competition
 
#define OUTPUT_PIN 9

byte beacon_heading;

// Out setup routine, here we will configure the microcontroller and compass.
void setup()
{
  // Initialize the serial port.

  if (SERIAL_PRINT) {
      Serial.begin (9600);
  }
  pinMode (OUTPUT_PIN, OUTPUT);
  Set_Up_Compass ();

  if (BEACON_WOKRING) {
      Set_Up_Beacon ();
  }

  beacon_heading = 0;

  if (!USE_DEFAULT_COMPASS_DIRECTION) {
    int averaging_number = 10;
    beacon_heading = 0;
      
    for (int i = 0; i < averaging_number; i++) {
      beacon_heading += Get_Compass_Heading();
      delay(50);
    }

    beacon_heading /= averaging_number;
  }
  
  Set_Up_Timer ();
}

// Our main program loop.
void loop()
{
  if (BEACON_WOKRING) { 
    Update_Beacon_Direction ();
    Serial.print ("Beacon direction: ");
    Serial.println (beacon_heading);
  }
}
