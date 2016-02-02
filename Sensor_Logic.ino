/*  CODE FOR NASA ROBOTICS CHALLANGE 2016
 *  by Igor Ryzhkov (igor.o.ryzhkov@gmail.com)
 *  
 *  Defines methods in Sensor_Lobic.h
 */

Sensor_Logic::Sensor_Logic (Compass_Sensor *compass, Beacon_Sensor *beacon, IR_Sensor *middle_obstacle) {
    this->compass = compass;
    this->beacon = beacon;
    this->middle_obstacle = middle_obstacle;
}

void Sensor_Logic::Update_Sensors() {
    this->compass->Update_Value();
    this->beacon->Update_Value();
    this->middle_obstacle->Update_Value();

    if (Serial.available())
      if (Serial.peek() != 'c' && Serial.peek() != 'b')
        Serial.read();
}

int Sensor_Logic::Get_Compass_Value() {
    return this->compass->Get_Value();
}

int Sensor_Logic::Get_Beacon_Value() {
    return this->beacon->Get_Value();
}

int Sensor_Logic::Get_IR_Value() {
    return this->middle_obstacle->Get_Value();
}
