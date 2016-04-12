/*  CODE FOR NASA ROBOTICS CHALLANGE 2016
 *  by Igor Ryzhkov (igor.o.ryzhkov@gmail.com)
 *  
 *  This class assumes the configuration of sensors, that we have for the robot. 
 */

 // defining array indecies, so that it is very clear, what I am refering to.
#define RIGHT 0
#define LEFT 1
//#define MIDDLE 2
//#define RIGHT_PIT 3
//#define LEFT_PIT 4
#define BEACON_DIRECTION 2

#define  PIT_DANGER 300

#define OBSTACLE_WARNING 200
#define OBSTACLE_DANGER 300

#define NUM_SENSORS 3
#define NUM_DANGER_UPDATES 2

class Sensor_Logic {
    typedef void (Sensor_Logic::*Sensor_Logic_Function)();
  
    private:
        Sensor *sensor[NUM_SENSORS];
        int sensor_danger_code[NUM_DANGER_UPDATES];

        Sensor_Logic_Function danger_code_updates[NUM_DANGER_UPDATES];
        
        int danger_id, side_id;

        int Get_Danger_Code_For_Sensor (int which_sensor);
        int Get_Danger_Code_For_Pit_Sensor (int which_sensor);

        void Danger_Check_For_Far_Obstacle ();
        void Danger_Check_For_Close_Obstacle ();
        void Danger_Check_For_Middle_Obstacle ();
        void Danger_Check_For_Pits ();
    public:
        Sensor_Logic (Sensor *beacon_direction, Sensor *right_sensor, Sensor *middle_sensor,
                      Sensor *left_sensor, Sensor *right_pit_sensor, Sensor *left_pit_sensor);

         Sensor_Logic (Sensor *beacon_direction, Sensor *right_sensor, Sensor *left_sensor);
                      
        void Update_Sensors ();

        int Get_Beacon_Direction();
        
        int Get_Danger_ID ();
        int Get_Side_ID ();

        void Set_Testing (bool value);
};
