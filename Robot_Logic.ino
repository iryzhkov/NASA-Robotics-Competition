/*  CODE FOR NASA ROBOTICS CHALLANGE 2016
 *  by Igor Ryzhkov (igor.o.ryzhkov@gmail.com)
 *  
 *  Defines methods in Robot_Logic.h
 */

Robot_Logic::Robot_Logic (Movement_Control *control, Sensor_Logic *sensors) {
    this->control = control;
    this->sensors = sensors;

    this->Tasks[0] = &Robot_Logic::Go_Towards_Beacon;
    this->Tasks[1] = &Robot_Logic::Move_Forward;
    this->Tasks[2] = &Robot_Logic::Avoid_Possible_Obstacle_On_Side;
    this->Tasks[3] = &Robot_Logic::Avoid_Definite_Obstacle_On_Side;
    this->Tasks[4] = &Robot_Logic::Avoid_Obstacle_In_Front;
    this->Tasks[5] = &Robot_Logic::Avoid_Pit_On_Side;
    this->Tasks[6] = &Robot_Logic::Avoid_Pit_In_Front;
}


void Robot_Logic::Update_Sensors () {
    this->sensors->Update_Sensors();

    this->danger_id = this->sensors->Get_Danger_ID();
    this->side_id = this->sensors->Get_Side_ID();
}

void Robot_Logic::main () {
    this->sensors->Update_Sensors();
  
    if (this->danger_id > this->process_id)
        this->process_id = this->danger_id;

     
}

void Robot_Logic::Go_Towards_Beacon () {
}

void Robot_Logic::Move_Forward () {
}

void Robot_Logic::Avoid_Possible_Obstacle_On_Side () {
}

void Robot_Logic::Avoid_Definite_Obstacle_On_Side () {
}

void Robot_Logic::Avoid_Obstacle_In_Front () {
}

void Robot_Logic::Avoid_Pit_On_Side () {
}

void Robot_Logic::Avoid_Pit_In_Front () {
}
