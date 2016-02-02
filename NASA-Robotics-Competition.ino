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

Compass_Sensor    *compass_sensor;

Beacon_Sensor     *beacon_sensor;

IR_Sensor         *left_Hole_Sensor,
                  *right_Hole_Sensor,
                  *left_Obstacle_Sensor,
                  *right_Obstacle_Sensor,
                  *middle_Obstacle_Sensor;

void setup() {
    Serial.begin(9600); // starting serial communication.

    // setting up the motors
    left_Motor = new Motor (left_motor_pwm_pin, left_motor_dir_pin);
    right_Motor = new Motor (right_motor_pwm_pin, right_motor_dir_pin);

    // setting up Movement_Control
    drive_Control = new Movement_Control(left_Motor, right_Motor);

    // setting up IR sensors
    left_Hole_Sensor = new IR_Sensor(left_hole_sensor_pin);
    right_Hole_Sensor = new IR_Sensor(right_hole_sensor_pin);
    left_Obstacle_Sensor = new IR_Sensor(left_obstacle_sensor_pin);
    right_Obstacle_Sensor = new IR_Sensor(right_obstacle_sensor_pin);
    middle_Obstacle_Sensor = new IR_Sensor(middle_obstacle_sensor_pin);

    // setting up compass and beacon sensors
    compass_sensor = new Compass_Sensor();
    beacon_sensor = new Beacon_Sensor();

    // setting up sensor logic
    sensor_logic = new Sensor_Logic (compass_sensor, beacon_sensor);
    
    // setting up robot logic
    robot = new Robot_Logic (drive_Control, sensor_logic);
  
    timer_setup(); // setting continious data acquisition.
}

void loop() {
  robot->main();
  delay(100);
}
