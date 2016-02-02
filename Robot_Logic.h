/*  CODE FOR NASA ROBOTICS CHALLANGE 2016
 *  by Igor Ryzhkov (igor.o.ryzhkov@gmail.com)
 *  
 *  This is Robot_Logic header. Does all the logic for the robot control.
 */ 

class Robot_Logic {
    private:
        Movement_Control *control;
        Sensor_Logic *sensors;
    public:
        Robot_Logic (Movement_Control *control, Sensor_Logic *sensors);
        void Update_Sensors ();

        void main ();
};
