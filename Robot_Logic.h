/*  CODE FOR NASA ROBOTICS CHALLANGE 2016
 *  by Igor Ryzhkov (igor.o.ryzhkov@gmail.com)
 *  
 *  This is Robot_Logic header. Does all the logic for the robot control.
 */

#define NUM_FUNCTIONS

class Robot_Logic {
    typedef void (Robot_Logic::*Control_Function)();
    
    private:
        Movement_Control *control;
        Sensor_Logic *sensors;

        int process_id, subprocess_id, process_time,
            danger_id, side_id;
        
        Control_Function Tasks[NUM_FUNCTIONS];
        
    public:
        Robot_Logic (Movement_Control *control, Sensor_Logic *sensors);
        void Update_Sensors ();

        void main ();

        void Go_Towards_Beacon ();
        void Move_Forward ();

        void Avoid_Possible_Obstacle_On_Side ();
        void Avoid_Definite_Obstacle_On_Side ();

        void Avoid_Obstacle_In_Front ();

        void Avoid_Pit_On_Side ();
        void Avoid_Pit_In_Front ();

        int Get_Process_ID ();
        int Get_Subprocess_ID ();

        void Set_Testing (bool value);
};
