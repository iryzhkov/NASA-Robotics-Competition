/*  CODE FOR NASA ROBOTICS CHALLANGE 2016
    by Igor Ryzhkov (igor.o.ryzhkov@gmail.com)

    Header for Movement_Control class. Allows easy control of the robot's movements.
*/

class Movement_Control {
  private:
    Motor *left_Motor,
          *right_Motor;
  public:
    Movement_Control (Motor *left, Motor *right);
    Movement_Control (int left_PWM_pin, int left_DIR_pin, int right_PWM_pin, int right_DIR_pin);

    void Stop ();

    void Move_Forward ();
    void Move_Backward ();

    void Turn (int side);
    void Turn_Left ();
    void Turn_Right ();

    void Differential_Turn (int side);
    void Differential_Turn_Left ();
    void Differential_Turn_Right ();
};
