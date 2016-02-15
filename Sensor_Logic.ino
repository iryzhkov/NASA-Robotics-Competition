/*  CODE FOR NASA ROBOTICS CHALLANGE 2016
 *  by Igor Ryzhkov (igor.o.ryzhkov@gmail.com)
 *  
 *  Defines methods in Sensor_Lobic.h
 */

#define pit_danger_threshold 255

#define obstacle_proximity_warning 255
#define obstacle_proximity_danger 123

Sensor_Logic::Sensor_Logic (Sensor *beacon_direction, Sensor *right_sensor, Sensor *middle_sensor,
                            Sensor *left_sensor, Sensor *right_pit_sensor, Sensor *left_pit_sensor) {
    
    this->beacon_direction = beacon_direction;
    this->right_sensor = right_sensor;
    this->middle_sensor = middle_sensor;
    this->left_sensor = left_sensor;
    this->right_pit_sensor = right_pit_sensor;
    this->left_pit_sensor = left_pit_sensor;
}

void Sensor_Logic::Update_Sensors() {
    this->beacon_direction->Update_Value();
    
    this->right_sensor->Update_Value();
    this->middle_sensor->Update_Value();
    this->left_sensor->Update_Value();

    this->right_pit_sensor->Update_Value();
    this->left_pit_sensor->Update_Value();
}

int Sensor_Logic::Get_Beacon_Direction() {
    return this->beacon_direction->Get_Value();
}

int Sensor_Logic::Get_Danger_ID () {
    return this->danger_id;
}

int Sensor_Logic::Get_Side_ID () {
    return this->side_id;
}
