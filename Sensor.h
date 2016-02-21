/*  CODE FOR NASA ROBOTICS CHALLANGE 2016
 *  by Igor Ryzhkov (igor.o.ryzhkov@gmail.com)
 *  
 *  Sensor classes, for easy interface with sensors.
 */

class Sensor {
    protected:
        int sensor_value, previous_value;
        byte sensor_pin;
        bool testing;
    public:
        Sensor (byte sensor_pin);
        void Update_Value ();
        int  Get_Value ();
        void Set_Value (int value);
        void Set_Testing (bool value);
};
