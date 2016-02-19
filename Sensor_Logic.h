/*  CODE FOR NASA ROBOTICS CHALLANGE 2016
 *  by Igor Ryzhkov (igor.o.ryzhkov@gmail.com)
 *  
 *  This class assumes the configuration of sensors, that we have for the robot. 
 */

 // defining array indecies, so that it is very clear, what I am refering to.
#define RIGHT 0
#define LEFT 1
#define MIDDLE 2
#define RIGHT_PIT 3
#define LEFT_PIT 4
#define BEACON_DIRECTION 5

#define  PIT_DANGER 300

#define OBSTACLE_WARNING 150
#define OBSTACLE_DANGER 600

#define NUM_SENSORS 8

class Sensor_Logic {
    private:
        Sensor *sensor[NUM_SENSORS];
        int sensor_danger_code[NUM_SENSORS];
        
        int danger_id, side_id;

        int Get_Danger_Code_For_Sensor (int which_sensor);
        int Get_Danger_Code_For_Pit_Sensor (int which_sensor);
    public:
        Sensor_Logic (Sensor *beacon_direction, Sensor *right_sensor, Sensor *middle_sensor,
                      Sensor *left_sensor, Sensor *right_pit_sensor, Sensor *left_pit_sensor);
                      
        void Update_Sensors ();

        int Get_Beacon_Direction();
        
        int Get_Danger_ID ();
        int Get_Side_ID ();

        void Set_Testing (bool value);
};
