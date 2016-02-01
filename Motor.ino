/*  CODE FOR NASA ROBOTICS CHALLANGE 2016
 *  by Igor Ryzhkov (igor.o.ryzhkov@gmail.com)
 *  
 *  This is Motor class. It provides the interface for the motors.
 */ 

class Motor {
    private:
        byte PWMpin, 
             DIRpin,
             PWM,
             DIR;
  
    public:
        Motor(byte PWMpin, byte DIRpin);
        
        void setDIR (byte);
        byte getDIR ();
        void setPWM (byte);
        byte getPWM ();  
};

Motor::Motor (byte PWMpin, byte DIRpin) {
  /*  Motor (PWMpin, DIRpin)
   *  
   *  assign pins, and set them up.
   */
   
    this->DIRpin = DIRpin;
    this->PWMpin = PWMpin;
    
    pinMode(this->DIRpin, OUTPUT);
    pinMode(this->PWMpin, OUTPUT);
}

void Motor::setDIR (byte dir) {
    /*  setDIR (dir):
     *  
     *  0 <= dir <= 1
     *  
     *  sets the direction pin to the specified value. 
     */

    // Save the value, and write it to the pin.
    this->DIR = dir;
    digitalWrite (DIRpin, DIR); 
}

byte Motor::getDIR(){
    /*  getDIR():
     *   
     *  returns current setting of DIR pin 
     */
     
    return DIR;
}

void Motor::setPWM (byte pwm) {
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
    analogWrite(PWMpin, PWM);
}

byte Motor::getPWM () {
     /*  getDIR():
     *   
     *  returns current setting of PWM pin 
     */
     
    return this->PWM;
}

