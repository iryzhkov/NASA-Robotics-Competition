/*  CODE FOR NASA ROBOTICS CHALLANGE 2016
 *  by Igor Ryzhkov (igor.o.ryzhkov@gmail.com)
 *  
 *  Defines methods in Robot_Logic.h
 */

Robot_Logic::Robot_Logic (Movement_Control *control, Sensor_Logic *sensors) {
    this->control = control;
    this->sensors = sensors;
}


void Robot_Logic::Update_Sensors () {
    this->sensors->Update_Sensors();
}

void Robot_Logic::main () {
    int t = sensors->Get_IR_Value() / 10;
    for (int i = 0; i < t; i++)
        Serial.print("-");
    Serial.println();
}
