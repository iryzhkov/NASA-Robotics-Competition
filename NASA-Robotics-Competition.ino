/*  CODE FOR NASA ROBOTICS CHALLANGE 2016
 *  by Igor Ryzhkov (igor.o.ryzhkov@gmail.com)
 *  
 *  This is the main function. It uses all other classes and functions to control the robot.
 */ 

// imports for the program. (these are the headers for the classes that we will use).
#include "Pin_Declaration.h"
#include "Motor.h"
#include "Movement_Control.h"
#include "Sensor.h"
#include "Sensor_Logic.h"
#include "Robot_Logic.h"

// library for testing the program
// need to run all tests in setup().
// library link: https://github.com/mmurdoch/arduinounit
#include <ArduinoUnit.h>

#define DEBUGGING true

// Global variables
Robot_Logic       *robot;

Movement_Control  *drive_control;

Motor             *left_motor,
                  *right_motor;

Sensor_Logic      *sensor_logic;     

Sensor            *left_pit_sensor,
                  *right_pit_sensor,
                  *left_sensor,
                  *right_sensor,
                  *middle_sensor,
                  *beacon_direction;


void setup() {
    // starting serial communication.
    Serial.begin(9600); 

    // setting up the motors
    left_motor = new Motor (LEFT_MOTOR_PWM_PIN, LEFT_MOTOR_DIR_PIN);
    right_motor = new Motor (RIGHT_MOTOR_PWM_PIN, RIGHT_MOTOR_DIR_PIN);

    // setting up Movement_Control
    drive_control = new Movement_Control(left_motor, right_motor);

    // setting up IR sensors with the testing settings
    left_pit_sensor = new Sensor(LEFT_PIT_SENSOR_PIN);
    left_pit_sensor->Set_Testing(DEBUGGING);
    
    right_pit_sensor = new Sensor(RIGHT_PIT_SENSOR_PIN);
    right_pit_sensor->Set_Testing(DEBUGGING);
    
    left_sensor = new Sensor(LEFT_SENSOR_PIN);
    left_sensor->Set_Testing(DEBUGGING);
    
    right_sensor = new Sensor(RIGHT_SENSOR_PIN);
    right_sensor->Set_Testing(DEBUGGING);
    
    middle_sensor = new Sensor(MIDDLE_SENSOR_PIN);
    middle_sensor->Set_Testing(DEBUGGING);

    // setting up compass and beacon sensors
    beacon_direction = new Sensor(DIRECTION_SENSOR_PIN);
    beacon_direction->Set_Testing(DEBUGGING);

    // setting up sensor logic
    sensor_logic = new Sensor_Logic (beacon_direction, right_sensor, middle_sensor, left_sensor, right_pit_sensor, left_pit_sensor);
    
    // setting up robot logic
    robot = new Robot_Logic (drive_control, sensor_logic);

    // running the unit tests if we are debbuging the program
    if (DEBUGGING) {
        Test::run();

        // Setting sensors back to normal, when we are finished testing.
        left_pit_sensor->Set_Testing(false);
        right_pit_sensor->Set_Testing(false);
        left_sensor->Set_Testing(false);
        right_sensor->Set_Testing(false);
        middle_sensor->Set_Testing(false);
        beacon_direction->Set_Testing(false);
    }
}

void loop() {
    robot->main();
    delay(50);
}
