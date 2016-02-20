/*  CODE FOR NASA ROBOTICS CHALLANGE 2016
 *  by Igor Ryzhkov (igor.o.ryzhkov@gmail.com)
 *  
 *  Defines methods in Sensor_Lobic.h
 */

Sensor_Logic::Sensor_Logic (Sensor *beacon_direction, Sensor *right_sensor, Sensor *middle_sensor,
                            Sensor *left_sensor, Sensor *right_pit_sensor, Sensor *left_pit_sensor) {

    this->sensor[RIGHT] = right_sensor;
    this->sensor[LEFT] = left_sensor;
    this->sensor[MIDDLE] = middle_sensor;

    this->sensor[RIGHT_PIT] = right_pit_sensor;
    this->sensor[LEFT_PIT] = left_pit_sensor;

    this->sensor[BEACON_DIRECTION] = beacon_direction;

    danger_code_updates[0] = &Sensor_Logic::Danger_Check_For_Far_Obstacle;
    danger_code_updates[1] = &Sensor_Logic::Danger_Check_For_Far_Obstacle;
    danger_code_updates[2] = &Sensor_Logic::Danger_Check_For_Far_Obstacle;
    danger_code_updates[3] = &Sensor_Logic::Danger_Check_For_Far_Obstacle;
    danger_code_updates[4] = &Sensor_Logic::Danger_Check_For_Far_Obstacle;
    danger_code_updates[5] = &Sensor_Logic::Danger_Check_For_Far_Obstacle;
    danger_code_updates[6] = &Sensor_Logic::Danger_Check_For_Far_Obstacle;
    danger_code_updates[7] = &Sensor_Logic::Danger_Check_For_Far_Obstacle;
    danger_code_updates[8] = &Sensor_Logic::Danger_Check_For_Far_Obstacle;
}

void Sensor_Logic::Danger_Check_For_Far_Obstacle () {
    if (this->sensor_danger_code[RIGHT] == 1 || this->sensor_danger_code[LEFT] == 1) {
        this->danger_id = 2;

        if (this->sensor_danger_code[RIGHT] == 1)
            this->side_id = -1;
        else
            this->side_id = 1;
    }
    
    if (this->sensor_danger_code[RIGHT] == 1 && this->sensor_danger_code[LEFT] == 1) {
        this->danger_id = 3;
        this->side_id = 0;
    }
}

void Sensor_Logic::Set_Testing (bool value) {
    for (int i = 0; i < NUM_SENSORS; i++)
        this->sensor[i]->Set_Testing (value);
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

    this->danger_id = 0;
    this->side_id = 0;

    for (int i = 0; i < NUM_DANGER_UPDATES; i++)
      (this->*this->danger_code_updates[i])();    
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
