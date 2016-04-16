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
    testing = false;
    this->sensor_pin = pin;
    this->sensor_value = 0;
    pinMode (pin, INPUT);
}

void Sensor::Update_Value() {
 /* Sensor::Update_Value():
  *  
  * read the value from the pin.
  */
    if (!this->testing) {
        this->sensor_value = 0;
        for (int i = 0; i < 10; i++) {
            this->sensor_value += analogRead(this->sensor_pin);
            delay(2);
        }
        this->sensor_value /= 8;
    }
}

void Sensor::Set_Value(int value) {
  /* Sensor::Update_Value():
  *  
  * set the value.
  */

  if (this->testing)
    this->sensor_value = value; 
}

void Sensor::Set_Testing (bool value) {
  /* Sensor::Update                                             _Value():
  *  
  * set the testing value.
  */
  this->testing = value;
}

