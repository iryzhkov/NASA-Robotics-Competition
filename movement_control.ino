/*  CODE FOR NASA ROBOTICS CHALLANGE 2016
 *  by Igor Ryzhkov (igor.o.ryzhkov@gmail.com)
 *  
 *  Defines methods in Movement_Control.h
 */

Movement_Control::Movement_Control (Motor *left, Motor *right) {
   /*  Movement_Control (left, right):
    *   
    *  sets the right and the left motors. 
    */

    this->left_Motor = left;
    this->right_Motor = right;
}

Movement_Control::Movement_Control (int left_PWM_pin, int left_DIR_pin, int right_PWM_pin, int right_DIR_pin) {
   /*  Movement_Control (left_PWM_pin, left_DIR_pin, right_PWM_pin, right_DIR_pin):
    *   
    *  creates and sets the right and the left motors. 
    */

    this->left_Motor = new Motor(left_PWM_pin, left_DIR_pin);
    this->right_Motor = new Motor(right_PWM_pin, right_DIR_pin);
}

void Movement_Control::Stop () {
   /*  Stop():
    *   
    *  stops the movement of the robot by setting PWM of both motors to 0.
    */
   
    left_Motor->set_PWM(0);
    right_Motor->set_PWM(0);
}
