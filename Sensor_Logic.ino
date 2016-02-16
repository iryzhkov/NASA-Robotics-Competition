/*  CODE FOR NASA ROBOTICS CHALLANGE 2016
 *  by Igor Ryzhkov (igor.o.ryzhkov@gmail.com)
 *  
 *  Defines methods in Sensor_Lobic.h
 */

// defining array indecies, so that it is very clear, what I am refering to.
#define RIGHT 0
#define LEFT 1
#define MIDDLE 2
#define RIGHT_PIT 3
#define LEFT_PIT 4
#define BEACON_DIRECTION 5

#define pit_danger 255

#define obstacle_proximity_warning 255
#define obstacle_proximity_danger 123

Sensor_Logic::Sensor_Logic (Sensor *beacon_direction, Sensor *right_sensor, Sensor *middle_sensor,
                            Sensor *left_sensor, Sensor *right_pit_sensor, Sensor *left_pit_sensor) {

    this->sensor[RIGHT] = right_sensor;
    this->sensor[LEFT] = left_sensor;
    this->sensor[MIDDLE] = middle_sensor;

    this->sensor[RIGHT_PIT] = right_pit_sensor;
    this->sensor[LEFT_PIT] = left_pit_sensor;

    this->sensor[BEACON_DIRECTION] = beacon_direction;
}

void Sensor_Logic::Update_Sensors() {
    for (int i = 0; i < 6; i++)
        this->sensor[i]->Update_Value();
}

int Sensor_Logic::Get_Beacon_Direction() {
    return 0;
}

int Sensor_Logic::Get_Danger_ID () {
    return this->danger_id;
}

int Sensor_Logic::Get_Side_ID () {
    return this->side_id;
}
