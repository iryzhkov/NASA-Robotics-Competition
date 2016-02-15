/*  CODE FOR NASA ROBOTICS CHALLANGE 2016
 *  by Igor Ryzhkov (igor.o.ryzhkov@gmail.com)
 *  
 *  This is the main function. It uses all other classes and functions to control the robot.
 */ 

// imports for the program.
#include "Pin_Declaration.h"
#include "Motor.h"
#include "Movement_Control.h"
#include "Sensor.h"
#include "Sensor_Logic.h"
#include "Robot_Logic.h"

// Global variables
Robot_Logic       *robot;

Movement_Control  *drive_Control;

Motor             *left_Motor,
                  *right_Motor;

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
    left_Motor = new Motor (left_motor_pwm_pin, left_motor_dir_pin);
    right_Motor = new Motor (right_motor_pwm_pin, right_motor_dir_pin);

    // setting up Movement_Control
    drive_Control = new Movement_Control(left_Motor, right_Motor);

    // setting up IR sensors
    left_pit_sensor = new Sensor(left_pit_sensor_pin);
    right_pit_sensor = new Sensor(right_pit_sensor_pin);
    left_sensor = new Sensor(left_sensor_pin);
    right_sensor = new Sensor(right_sensor_pin);
    middle_sensor = new Sensor(middle_sensor_pin);

    // setting up compass and beacon sensors
    beacon_direction = new Sensor(direction_pin);

    // setting up sensor logic
    // !!! have to add more to this (The IR sensors, all of them).
    sensor_logic = new Sensor_Logic (beacon_direction, right_sensor, middle_sensor, left_sensor, right_pit_sensor, left_pit_sensor);
    
    // setting up robot logic
    robot = new Robot_Logic (drive_Control, sensor_logic);
}

void loop() {
    robot->main();
    delay(50);
}
