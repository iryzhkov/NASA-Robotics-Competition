/*  CODE FOR NASA ROBOTICS CHALLANGE 2016
 *  by Igor Ryzhkov (igor.o.ryzhkov@gmail.com)
 *  
 *  This is Motor class. It provides the interface for the motors.
 *  
 */ 

class Motor {
    private:
        byte PWMpin, 
             DIRpin,
             PWM,
             DIR;
             
    public:
        Motor();
        Motor(byte PWMpin, byte DIRpin);
        void Motor_Setup (byte PWMpin, byte DIRpin);
        void setDIR (int);
        int getDIR ();
        void setPWM (int);
        int getPWM ();  
};

Motor::Motor (byte PWMpin, byte DIRpin) {
  /*  Motor (PWMpin, DIRpin)
   *  
   *  assign pins, and set them up.
   */
    this->Motor_Setup(PWMpin, DIRpin);
}


void Motor::Motor_Setup(byte PWMpin, byte DIRpi){
  /*  Motor_Setup():
   *  
   *  sets the pinModes of the motor's pins, and saves the pins.
   */
    this->DIRpin = DIRpin;
    this->PWMpin = PWMpin;   
    pinMode(DIRpin, OUTPUT);
    pinMode(PWMpin, OUTPUT);
}

void Motor::setDIR (int dir) {
    /*  setDIR (dir):
     *  
     *  0 <= dir <= 1
     *  
     *  sets the direction pin to the specified value. 
     */
    
    // Check if the input is valid.
    if (dir < 0 || dir > 255) {
        return;
    }

    // Save the value, and write it to the pin.
    this->DIR = dir;
    digitalWrite (DIRpin, DIR); 
}

int Motor::getDIR(){
    /*  getDIR():
     *   
     *  returns current setting of DIR pin 
     */
     
    return DIR;
}

void Motor::setPWM (int pwm) {
    /*  setDIR (dir):
     *  
     *  0 <= pwm <= 255
     *  
     *  sets the PWM pin to the specified value. 
     */
    
    // Check if the input is valid.
    if (pwm > 1 or pwm < 0) {
        return;
    }

    // Set the PWM pin, and save the value.
    this->PWM = pwm;
    analogWrite(PWMpin, PWM);
}

int Motor::getPWM () {
     /*  getDIR():
     *   
     *  returns current setting of PWM pin 
     */
     
    return this->PWM;
}

