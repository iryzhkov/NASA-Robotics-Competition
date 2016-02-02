/*  CODE FOR NASA ROBOTICS CHALLANGE 2016
 *  by Igor Ryzhkov (igor.o.ryzhkov@gmail.com)
 *  
 *  Defines methods in Sensor.h
 */ 

int Sensor::Get_Value () {
  /*  Sensor::Get_Value():
   *   
   *   returns the current value of the sensor
   */

    // disable interrupts (so that the value doesn't update, while we are copying it), and get the sensor input.
    noInterrupts();
    this->sensor_value = sensor_input;

    // enable interrupts (would be bad if we forget it).
    interrupts();

     return sensor_value;
}

Serial_Sensor::Serial_Sensor (char trigger) {
 /* Serial_Sensor():
  *  
  * initialize the Serial_Sensor, and set the trigger value.
  * 
  */
    this->trigger_value = trigger;
}

void Serial_Sensor::Update_Value () {
  /*  Serial_Sensor::Update_Value ()
   *  
   *  updates the sensor_input in serial sensors
   */

   // see if there is data in Serial
   if (Serial.available()) {

      delayMicroseconds (10);
      // see if the first character of the input is the triggert
      if (Serial.peek() == this->trigger_value) {
          // skip the trigger and read the and the number in, if triggered.
          Serial.read();

          // read in number. (Serial.parseInt() for some reason works incredibaly bad)
          this->sensor_input = 0;
          byte t;
          while (Serial.available()) {
              t = Serial.read();
              if (isDigit(t))
                this->sensor_input = this->sensor_input*10 + t - '0';
              else
                break;
          }
      }
   }
}

IR_Sensor::IR_Sensor (byte pin) {
 /* IR_Sensor (pin):
  *  
  * Set pin for recieving, and save it it.
  */
  
    this->sensor_pin = pin;
    pinMode (pin, INPUT);
}

void IR_Sensor::Update_Value() {
 /* IR_Sensor::Update_Value():
  *  
  * read the value from the pin.
  */
  
    this->sensor_input = analogRead(this->sensor_pin); 
}

Compass_Sensor::Compass_Sensor (): Serial_Sensor('c') {
 /* Compass_Sensor():
  *  
  * initialize Compass_Sensor, and set 'c' to be trigger_value;
  * 
  */
}

Beacon_Sensor::Beacon_Sensor (): Serial_Sensor('b') {
 /* Beacon_Sensor():
  *  
  * initialize Beacon_Sensor, and set 'b' to be trigger_value;
  * 
  */
}
