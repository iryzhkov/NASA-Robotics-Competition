/*  CODE FOR NASA ROBOTICS CHALLANGE 2016
 *  by Igor Ryzhkov (igor.o.ryzhkov@gmail.com)
 *  
 *  Defines methods in Sensor.h
 */ 

int Sensor::Get_Value () {
  /*  Sensor::Get_Value():
   *   
   *  returns the current value of the sensor
   */

     return sensor_value;
}

Sensor::Sensor (byte pin) {
 /* Sensor (pin):
  *  
  * Set pin for recieving, and save it it.
  */
  
    this->sensor_pin = pin;
    pinMode (pin, INPUT);
}

void Sensor::Update_Value() {
 /* Sensor::Update_Value():
  *  
  * read the value from the pin.
  */
  
    this->sensor_value = analogRead(this->sensor_pin); 
}
