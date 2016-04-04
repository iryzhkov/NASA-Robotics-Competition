/*  CODE FOR NASA ROBOTICS CHALLANGE 2016
 *  by Igor Ryzhkov (igor.o.ryzhkov@gmail.com)
 *  
 *  Defines unit tests for this project
 *  
 *  Seems like this code takes up most of the program space. 
 *  
 *  When all code is tested, we could comment out this testing code, in case we run into memory issues.
 *  
 *  Used to quickly test the program before it enters loop();
 *  
 *  Uses library for testing
 *  library link: https://github.com/mmurdoch/arduinounit
 */

/*
void Set_To_Zero_State () {
    left_pit_sensor->Set_Value(PIT_DANGER+5);
    right_pit_sensor->Set_Value(PIT_DANGER+5);
    left_sensor->Set_Value(0);
    right_sensor->Set_Value(0);
    middle_sensor->Set_Value(0);
    beacon_direction->Set_Value(0);

    robot->Set_Process_ID (0);
}

test (no_dangers){
    Set_To_Zero_State();
    sensor_logic->Update_Sensors();
    assertEqual(0, sensor_logic->Get_Danger_ID());
}

test (danger_far_obstacle){
    Set_To_Zero_State();
    left_sensor->Set_Value(OBSTACLE_WARNING+5);
    sensor_logic->Update_Sensors();
  
    assertEqual(2, sensor_logic->Get_Danger_ID());

    right_sensor->Set_Value(OBSTACLE_WARNING+5);
    left_sensor->Set_Value(0);
    sensor_logic->Update_Sensors();

    assertEqual(2, sensor_logic->Get_Danger_ID());
}

test (side_far_obstacle) {
    Set_To_Zero_State();
    left_sensor->Set_Value(OBSTACLE_WARNING+5);
    sensor_logic->Update_Sensors();
  
    assertEqual(1, sensor_logic->Get_Side_ID());

    right_sensor->Set_Value(OBSTACLE_WARNING+5);
    left_sensor->Set_Value(0);
    sensor_logic->Update_Sensors();

    assertEqual(-1, sensor_logic->Get_Side_ID());
}

test (danger_close_obstacles){
    Set_To_Zero_State();
    left_sensor->Set_Value(OBSTACLE_DANGER+5);
    sensor_logic->Update_Sensors();
  
    assertEqual(3, sensor_logic->Get_Danger_ID());

    right_sensor->Set_Value(OBSTACLE_DANGER+5);
    left_sensor->Set_Value(0);
    sensor_logic->Update_Sensors();

    assertEqual(3, sensor_logic->Get_Danger_ID());
}

test (side_close_obstacles){
    Set_To_Zero_State();
    left_sensor->Set_Value(OBSTACLE_DANGER+5);
    sensor_logic->Update_Sensors();
  
    assertEqual(1, sensor_logic->Get_Side_ID());

    right_sensor->Set_Value(OBSTACLE_DANGER+5);
    left_sensor->Set_Value(0);
    sensor_logic->Update_Sensors();

    assertEqual(-1, sensor_logic->Get_Side_ID());
}

test (danger_pit){
    left_pit_sensor->Set_Value(PIT_DANGER-5);
    sensor_logic->Update_Sensors();
  
    assertEqual(6, sensor_logic->Get_Danger_ID());

    right_pit_sensor->Set_Value(PIT_DANGER-5);
    left_pit_sensor->Set_Value(PIT_DANGER+5);
    sensor_logic->Update_Sensors();

    assertEqual(6, sensor_logic->Get_Danger_ID());
}

test (side_pit){
    left_pit_sensor->Set_Value(PIT_DANGER-5);
    sensor_logic->Update_Sensors();
  
    assertEqual(1, sensor_logic->Get_Side_ID());

    right_pit_sensor->Set_Value(PIT_DANGER-5);
    left_pit_sensor->Set_Value(PIT_DANGER+5);
    sensor_logic->Update_Sensors();

    assertEqual(-1, sensor_logic->Get_Side_ID());
} 
*/

void testMotor (Motor *test_motor) {
    test_motor->Set_DIR(HIGH);
    test_motor->Set_PWM(2);

    delay (500);

    test_motor->Set_DIR(LOW);

    delay (500);
    test_motor->Set_PWM(0);
}

void testTwoMotors (Movement_Control *control) {
    control->Move_Forward();

    delay(750);

    control->Move_Backward();

    delay(750);

    control->Turn_Right();

    delay(750);

    control->Turn_Left();

    delay(750);

    left_motor->Set_PWM(0);
    right_motor->Set_PWM(0);
}
