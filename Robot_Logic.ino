/*  CODE FOR NASA ROBOTICS CHALLANGE 2016
 *  by Igor Ryzhkov (igor.o.ryzhkov@gmail.com)
 *  
 *  This is Robot_Logic class. Does all the logic for robot contorl.
 */

Robot_Logic::Robot_Logic (Movement_Control *control, Sensor_Logic *sensors) {
    this->control = control;
    this->sensors = sensors;
}


void Robot_Logic::Update_Sensors () {
    this->sensors->Update_Sensors();
}

void Robot_Logic::main () {
    Serial.print ("Compass sensor value: ");
    Serial.print (sensors->Get_Compass_Value());
    Serial.print ("\tBeacon sensor value: ");
    Serial.println (sensors->Get_Beacon_Value());
}

