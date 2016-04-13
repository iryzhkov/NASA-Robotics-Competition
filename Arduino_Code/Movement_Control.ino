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

    this->current_direction = 0;
}

Movement_Control::Movement_Control (int left_PWM_pin, int left_DIR_pin, int right_PWM_pin, int right_DIR_pin) {
   /*  Movement_Control (left_PWM_pin, left_DIR_pin, right_PWM_pin, right_DIR_pin):
    *   
    *  creates and sets the right and the left motors. 
    */

    this->left_Motor = new Motor(left_PWM_pin, left_DIR_pin);
    this->right_Motor = new Motor(right_PWM_pin, right_DIR_pin);
}

void Movement_Control::Turn (int side) {
    if (side == 0)
        this->Move_Forward();
  
    if (side == -1)
        this->Turn_Left();

    if (side == 1)
        this->Turn_Right();
}

void Movement_Control::Turn_Left () {
   /*  Movement_Control::Turn_Left():
    *   
    *  starts turning left
    */

    this->left_Motor->Set_PWM(140);
    this->right_Motor->Set_PWM(140);
    
    this->left_Motor->Set_DIR(LOW);
    this->right_Motor->Set_DIR(LOW);
}

void Movement_Control::Turn_Right () {
   /*  Movement_Control::Turn_Right():
    *   
    *  starts turning right
    */

    this->left_Motor->Set_PWM(140);
    this->right_Motor->Set_PWM(140);
    
    this->left_Motor->Set_DIR(HIGH);
    this->right_Motor->Set_DIR(HIGH);
}

void Movement_Control::Differential_Turn (int side) {
    if (side == 0)
        this->Move_Forward();
  
    if (side == -1)
        this->Differential_Turn_Left();

    if (side == 1)
        this->Differential_Turn_Right();
}

void Movement_Control::Differential_Turn_Left () {
   /*  Movement_Control::Differential_Turn_Left():
    *   
    *  starts turning left
    */

    if (this->current_direction == -1) {
      this->Stop();
    }

    this->current_direction = 1;

    this->left_Motor->Set_PWM(125);
    this->right_Motor->Set_PWM(175);
    
    this->left_Motor->Set_DIR(HIGH);
    this->right_Motor->Set_DIR(LOW);
}

void Movement_Control::Differential_Turn_Right () {
   /*  Movement_Control::Differential_Turn_Right():
    *   
    *  starts turning right
    */

    if (this->current_direction == -1) {
      this->Stop();
    }

    this->current_direction = 1;

    this->left_Motor->Set_PWM(175);
    this->right_Motor->Set_PWM(125);
    
    this->left_Motor->Set_DIR(HIGH);
    this->right_Motor->Set_DIR(LOW);
}

void Movement_Control::Move_Forward () {
   /*  Movement_Control::Stop():
    *   
    *  starts moving forward of the robot by setting PWM and DIR pins
    */

    if (this->current_direction == -1) {
      this->Stop();
    }

    this->current_direction = 1;
    
    left_motor->Set_PWM(140);
    right_motor->Set_PWM(140);
    
    right_motor->Set_DIR(LOW);
    left_motor->Set_DIR(HIGH);  
}

void Movement_Control::Move_Backward () {
   /*  Movement_Control::Move_Backwardp():
    *   
    *  starts moving backward of the robot by setting PWM and DIR pins
    */

    if (this->current_direction == 1) {
      this->Stop();
    }

    this->current_direction = -1;

    left_motor->Set_PWM(140);
    right_motor->Set_PWM(140);
    
    left_motor->Set_DIR(LOW);
    right_motor->Set_DIR(HIGH);
}

void Movement_Control::Stop () {
   /*  Movement_Controll::Stop():
    *   
    *  stops the movement of the robot by setting PWM of both motors to 0.
    */
    if (this->current_direction != 0) {
        if (this->current_direction == 1) {
            left_motor->Set_DIR(LOW);
            right_motor->Set_DIR(HIGH);
        }
        else if (this->current_direction == -1) {
            right_motor->Set_DIR(LOW);
            left_motor->Set_DIR(HIGH);
        }

        left_motor->Set_PWM(50);
        right_motor->Set_PWM(50);

        delay(60);
        this->current_direction = 0;
    }
  
    left_Motor->Set_PWM(0);
    right_Motor->Set_PWM(0);

    delay(50);
}
