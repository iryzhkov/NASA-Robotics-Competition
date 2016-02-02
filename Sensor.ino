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

Serial_Sensor::Serial_Sensor (char trigger) {
    this->trigger_value = trigger;
}

void Serial_Sensor::Update_Value () {
  /*  Serial_Sensor::Update_Value ()
   *  
   *  updates the sensor_input in serial sensors
   */

   // see if there is data in Serial
   if (Serial.available()) {
      // see if the first character of the input is the triggert
      if (Serial.peek() == this->trigger_value) {
          // skip the trigger and read the and the number in, if triggered.
          Serial.read();

          this->sensor_input = 0;
          byte t;

          // read in number. (Serial.parseInt() for some reason works incredibaly bad)
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
    this->sensor_pin = pin;
    pinMode (pin, INPUT);
}

void IR_Sensor::Update_Value() {
    this->sensor_input = analogRead(this->sensor_pin); 
}

Compass_Sensor::Compass_Sensor (): Serial_Sensor('c') {
}

Beacon_Sensor::Beacon_Sensor (): Serial_Sensor('b') {
}
