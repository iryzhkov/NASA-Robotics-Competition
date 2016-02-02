/*  CODE FOR NASA ROBOTICS CHALLANGE 2016
 *  by Igor Ryzhkov (igor.o.ryzhkov@gmail.com)
 */ 

 int Sensor::Get_Value () {
  /*  Sensor::Get_Value():
   *   
   *   returns the current value of the sensor
   */

    // disable interrupts (so that the value doesn't update, while we are copying it), and get the sensor input.
    noInterrupts();
    this->sensor_value = sensor_input;

    // enable interrupts
    interrupts();

     return sensor_value;
 }

 void Serial_Sensor::Update_Value () {
  /*  Serial_Sensor::Update_Value ()
   *  
   *  updates the sensor_input in serial sensors
   */

   // see if there is data in Serial
   if (Serial.available()) {
      // see if the first character of the input is the trigger
      if (Serial.peek() == this->trigger_value) {
          // skip the trigger and read the and the number in, if triggered.
          Serial.read();
          this->sensor_input = Serial.parseInt(); 

          // !!! Figure out, if it reads the new line character.
      }
   }
 }

