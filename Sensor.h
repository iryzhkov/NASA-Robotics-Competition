/*  CODE FOR NASA ROBOTICS CHALLANGE 2016
 *  by Igor Ryzhkov (igor.o.ryzhkov@gmail.com)
 */

class Sensor {
    protected:
        int sensor_value;
        volatile int sensor_input;
    public:
        virtual void Update_Value () = 0;
        int  Get_Value ();
};

class IR_Sensor: public Sensor {
    private:
        byte sensor_pin;
    public:
        IR_Sensor (byte pin);
        void Update_Value ();
};

class Serial_Sensor: public Sensor {
    protected:
        char trigger_value;
    public:
        Serial_Sensor (char trigger);
        void Update_Value ();
};

class Compass_Sensor: public Serial_Sensor {
    public:
        Compass_Sensor ();
};

class Beacon_Sensor: public Serial_Sensor {
    public:
        Beacon_Sensor ();
};
