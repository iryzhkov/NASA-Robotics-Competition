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

// Testing settings
// Set testing true if you want to test software or hardware
// Set Software true if you want to test software
// Set Software false if you want to test hardware
#define TESTING false
#define SOFTWARE false

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
    //left_pit_sensor = new Sensor(LEFT_PIT_SENSOR_PIN);   
    //right_pit_sensor = new Sensor(RIGHT_PIT_SENSOR_PIN); 
    left_sensor = new Sensor(LEFT_SENSOR_PIN);
    right_sensor = new Sensor(RIGHT_SENSOR_PIN);
    //middle_sensor = new Sensor(MIDDLE_SENSOR_PIN);

    // setting up compass and beacon sensors
    beacon_direction = new Sensor(DIRECTION_SENSOR_PIN);

    // setting up sensor logic
    //sensor_logic = new Sensor_Logic (beacon_direction, right_sensor, middle_sensor, left_sensor, right_pit_sensor, left_pit_sensor);
    sensor_logic = new Sensor_Logic (beacon_direction, right_sensor, left_sensor);
    
    // setting up robot logic
    robot = new Robot_Logic (drive_control, sensor_logic);
}

void loop() {
    // running unit tests if we are debbuging the program
    if (TESTING) {
        if (SOFTWARE) {
            // setting robot to testing mode
            robot->Set_Testing(true);
         
            // running all the tests
            Test::run();
    
            // setting robot back to regular mode
            robot->Set_Testing(false);
        }
        else {
            // hardware testing here

            // testing right motor
            drive_control->Differential_Turn(1);
            delay (1000);

            drive_control->Differential_Turn(-1);
            delay (1000);
            
            drive_control->Move_Backward();
            delay (1500);
        }
    }
    else {
        robot->main();
        delay(50);

        //Serial.println (analogRead(A0));
        //delay (500);
    }
}
