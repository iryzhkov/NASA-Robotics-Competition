/*  CODE FOR NASA ROBOTICS CHALLANGE 2016
 *  by Igor Ryzhkov (igor.o.ryzhkov@gmail.com)
 *  
 *  This is the main function. It uses all other classes and functions to control the robot.
 */ 

// Note: ISR stands for Interrupt Service Routine

#include "Motor.h"
#include "Movement_Control.h"
#include "Robot_Logic.h"
#include "Sensor.h"

// Global variables
#define LED 13

volatile bool light = false;

Robot_Logic *Robot;

void setup() 
{
  Serial.begin(9600);

  pinMode(LED, OUTPUT);

  timer_setup(); // setting continious data acquisition.
}

void loop() 
{
  delay(1000);
}
