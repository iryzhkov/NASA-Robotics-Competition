/*  CODE FOR NASA ROBOTICS CHALLANGE 2016
 *  by Igor Ryzhkov (igor.o.ryzhkov@gmail.com)
 *  
 *  Sensor classes, for easy interface with sensors.
 */

class Sensor {
    protected:
        int sensor_value;
        byte sensor_pin;
    public:
        Sensor (byte sensor_pin);
        void Update_Value ();
        int  Get_Value ();
};
