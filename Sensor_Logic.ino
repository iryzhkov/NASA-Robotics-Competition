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

#define  PIT_DANGER 300

#define OBSTACLE_WARNING 150
#define OBSTACLE_DANGER 600

Sensor_Logic::Sensor_Logic (Sensor *beacon_direction, Sensor *right_sensor, Sensor *middle_sensor,
                            Sensor *left_sensor, Sensor *right_pit_sensor, Sensor *left_pit_sensor) {

    this->sensor[RIGHT] = right_sensor;
    this->sensor[LEFT] = left_sensor;
    this->sensor[MIDDLE] = middle_sensor;

    this->sensor[RIGHT_PIT] = right_pit_sensor;
    this->sensor[LEFT_PIT] = left_pit_sensor;

    this->sensor[BEACON_DIRECTION] = beacon_direction;
}

int Sensor_Logic::Get_Danger_Code_For_Sensor (int which_sensor) {
    int result = 0;

    if (this->sensor[which_sensor]->Get_Value() > OBSTACLE_WARNING)
      result = 1;

    if (this->sensor[which_sensor]->Get_Value() > OBSTACLE_DANGER)
      result = 2;

    return result;
}

int Sensor_Logic::Get_Danger_Code_For_Pit_Sensor (int which_sensor) {
    int result = 0;

    if (this->sensor[which_sensor]->Get_Value() < PIT_DANGER)
      result = 1;

    return result;
}


void Sensor_Logic::Update_Sensors() {
    // Clean way to update all sensors' values
    for (int i = 0; i < NUM_SENSORS; i++)
        this->sensor[i]->Update_Value();

    this->sensor_danger_code[RIGHT] = this->Get_Danger_Code_For_Sensor (RIGHT);
    this->sensor_danger_code[LEFT] = this->Get_Danger_Code_For_Sensor (LEFT);
    this->sensor_danger_code[MIDDLE] = this->Get_Danger_Code_For_Sensor (MIDDLE);

    this->sensor_danger_code[RIGHT_PIT] = this->Get_Danger_Code_For_Pit_Sensor (RIGHT_PIT);
    this->sensor_danger_code[LEFT_PIT] = this->Get_Danger_Code_For_Pit_Sensor (LEFT_PIT);
}

int Sensor_Logic::Get_Beacon_Direction() {
    // Returns 0 if we are withing 15 deg from the beacon
    // Returns -1 if we are too left
    // return 1 if we are too right
    
    return 0;
}

int Sensor_Logic::Get_Danger_ID () {
    return this->danger_id;
}

int Sensor_Logic::Get_Side_ID () {
    return this->side_id;
}
