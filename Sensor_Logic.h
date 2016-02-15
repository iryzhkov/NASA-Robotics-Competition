/*  CODE FOR NASA ROBOTICS CHALLANGE 2016
 *  by Igor Ryzhkov (igor.o.ryzhkov@gmail.com)
 *  
 *  This class assumes the configuration of sensors, that we have for the robot. 
 */

class Sensor_Logic {
    private:
        Sensor *beacon_direction;
        Sensor *middle_sensor,
               *left_sensor,
               *right_sensor,
               *left_pit_sensor,
               *right_pit_sensor;

        int danger_id, side_id;
    public:
        Sensor_Logic (Sensor *beacon_direction, Sensor *right_sensor, Sensor *middle_sensor,
                      Sensor *left_sensor, Sensor *right_pit_sensor, Sensor *left_pit_sensor);
                      
        void Update_Sensors ();

        int Get_Beacon_Direction();
        
        int Get_Danger_ID ();
        int Get_Side_ID ();
};
