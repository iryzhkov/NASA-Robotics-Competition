/*  CODE FOR NASA ROBOTICS CHALLANGE 2016
 *  by Igor Ryzhkov (igor.o.ryzhkov@gmail.com)
 *  
 *  Defines methods in Motor.h
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
     
     // check for validity of the input
     if (dir > 1) {
        return;
    }

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
