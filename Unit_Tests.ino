/*  CODE FOR NASA ROBOTICS CHALLANGE 2016
 *  by Igor Ryzhkov (igor.o.ryzhkov@gmail.com)
 *  
 *  Defines unit tests for this project
 *  
 *  Used to quickly test the program before it enters loop();
 *  
 *  Uses library for testing
 *  library link: https://github.com/mmurdoch/arduinounit
 */

void Set_Sensors_To_Zero () {
    left_pit_sensor->Set_Value(0);
    right_pit_sensor->Set_Value(0);
    left_sensor->Set_Value(0);
    right_sensor->Set_Value(0);
    middle_sensor->Set_Value(0);
    beacon_direction->Set_Value(0);
}

test (correct_danger_id_for_no_dangers){
    Set_Sensors_To_Zero();
    fail();
}

test (correct_danger_id_for_far_obstacle){
    Set_Sensors_To_Zero();
    fail();
}

test (correct_side_id_for_far_obstacle) {
    Set_Sensors_To_Zero();
    fail();
}

test (correct_danger_id_for_close_obstacles){
    Set_Sensors_To_Zero();
    fail();
}

test (correct_side_id_for_close_obstacles){
    Set_Sensors_To_Zero();
    fail();
}

test (correct_danger_id_for_pit){
    Set_Sensors_To_Zero();
    fail();
}

test (correct_side_id_for_pit){
    Set_Sensors_To_Zero();
    fail();
}
