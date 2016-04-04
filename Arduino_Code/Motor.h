/*  CODE FOR NASA ROBOTICS CHALLANGE 2016
 *  by Igor Ryzhkov (igor.o.ryzhkov@gmail.com)
 *  
 *  This is header for Motor class. It provides the interface for the motors.
 */ 

class Motor {
    private:
        byte PWM_pin, 
             DIR_pin,
             PWM,
             DIR;
  
    public:
        Motor(byte PWM_pin, byte DIR_pin);

        // setter methods
        void Set_DIR (byte);
        void Set_PWM (byte);

        // getter methods
        byte Get_DIR ();
        byte Get_PWM ();  
};
