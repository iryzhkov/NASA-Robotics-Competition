/*  CODE FOR NASA ROBOTICS CHALLANGE 2016
 *  by Igor Ryzhkov (igor.o.ryzhkov@gmail.com)
 *  
 *  This class assumes the configuration of sensors, that we have for the robot. 
 */

class Sensor_Logic {
    private:
        Compass_Sensor *compass;
        Beacon_Sensor *beacon;
        IR_Sensor *middle_obstacle;
    public:
        Sensor_Logic (Compass_Sensor *compass, Beacon_Sensor *beacon, IR_Sensor *middle_obstacle);
        void Update_Sensors ();
        int Get_Compass_Value();
        int Get_Beacon_Value();
        int Get_IR_Value();
};
