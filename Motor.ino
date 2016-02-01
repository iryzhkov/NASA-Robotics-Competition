/*  CODE FOR NASA ROBOTICS CHALLANGE 2016
 *  by Igor Ryzhkov (igor.o.ryzhkov@gmail.com)
 *  
 *  This is Motor class. It provides the interface for the motors.
 */ 

Motor::Motor (byte PWM_pin, byte DIR_pin) {
  /*  Motor (PWMpin, DIRpin)
   *  
   *  assign pins, and set them up.
   */
   
    this->DIR_pin = DIR_pin;
    this->PWM_pin = PWM_pin;
    
    pinMode(this->DIR_pin, OUTPUT);
    pinMode(this->PWM_pin, OUTPUT);
}

void Motor::set_DIR (byte dir) {
    /*  setDIR (dir):
     *  
     *  0 <= dir <= 1
     *  
     *  sets the direction pin to the specified value. 
     */

    // Save the value, and write it to the pin.
    this->DIR = dir;
    digitalWrite (DIR_pin, DIR); 
}

byte Motor::get_DIR(){
    /*  getDIR():
     *   
     *  returns current setting of DIR pin 
     */
     
    return DIR;
}

void Motor::set_PWM (byte pwm) {
    /*  setDIR (dir):
     *  
     *  0 <= pwm <= 255
     *  
     *  sets the PWM pin to the specified value. 
     */
    
    // Check if the input is valid.
    if (pwm > 1) {
        return;
    }

    // Set the PWM pin, and save the value.
    this->PWM = pwm;
    analogWrite(PWM_pin, PWM);
}

byte Motor::get_PWM () {
     /*  getDIR():
     *   
     *  returns current setting of PWM pin 
     */
     
    return this->PWM;
}

