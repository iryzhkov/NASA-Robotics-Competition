/*  CODE FOR NASA ROBOTICS CHALLANGE 2016
 *  by Igor Ryzhkov (igor.o.ryzhkov@gmail.com)
 *  
 *  Class, that allows easy control of the robot. 
 */ 

class Movement_Control {
    private:
        Motor leftMotor, 
              rightMotor;
    public:
        Movement_Control (Motor left, Motor right);
        
        void Stop ();
        
        void Move_Forward ();
        void Move_Backward ();

        void Turn_Left ();
        void Turn_Right ();

        void Differential_Turn_Left ();
        void Differential_Turn_Right ();
};

Movement_Control::Movement_Control (Motor left, Motor right) {
   /*  Movement_Control (left, right):
    *   
    *  sets the right and the left motors. 
    * 
    */

    this->leftMotor = left;
    this->rightMotor = right;
}

void Movement_Control::Stop () {
   /*  Stop():
    *   
    *  stops the movement of the robot
    */
   
    leftMotor.setPWM(0);
    rightMotor.setPWM(0);
}

