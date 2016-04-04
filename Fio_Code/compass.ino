#include <Wire.h>
#include <HMC5883L.h>

HMC5883L compass;
int compass_error = 0;

void Set_Up_Compass () {
  Wire.begin(); // Start the I2C interface.
  
  compass = HMC5883L(); // Construct a new HMC5883 compass.
  compass_error = compass.SetScale(1.3); // Set the scale of the compass.
  if(compass_error != 0) // If there is an error, print it out.
    Serial.println(compass.GetErrorText(compass_error));
  compass_error = compass.SetMeasurementMode(Measurement_Continuous); // Set the measurement mode to Continuous
  if(compass_error != 0) // If there is an error, print it out.
    Serial.println(compass.GetErrorText(compass_error));
}

float Get_Compass_Heading () {
  // Retrive the raw values from the compass (not scaled).
  MagnetometerRaw raw = compass.ReadRawAxis();
  // Retrived the scaled values from the compass (scaled to the configured scale).
  MagnetometerScaled scaled = compass.ReadScaledAxis();
  
  // Values are accessed like so:
  int MilliGauss_OnThe_XAxis = scaled.XAxis;// (or YAxis, or ZAxis)

  // Calculate heading when the magnetometer is level, then correct for signs of axis.
  float heading = atan2(scaled.YAxis, scaled.XAxis);
  
  // Once you have your heading, you must then add your 'Declination Angle', which is the 'Error' of the magnetic field in your location.
  // Find yours here: http://www.magnetic-declination.com/
  // Mine is: 2� 37' W, which is 2.617 Degrees, or (which we need) 0.0456752665 radians, I will use 0.0457
  // If you cannot find your Declination, comment out these two lines, your compass will be slightly off.
  heading += DECLINATION_ANGLE;
  
  // Correct for when signs are reversed.
  if(heading < 0)
    heading += 2*PI;
    
  // Check for wrap due to addition of declination.
  if(heading > 2*PI)
    heading -= 2*PI;
   
  // Convert radians to degrees for readability and return the value.
  return heading * 180/M_PI; 
}
