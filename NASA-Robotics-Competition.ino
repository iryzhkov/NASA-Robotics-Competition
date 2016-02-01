/*  CODE FOR NASA ROBOTICS CHALLANGE 2016
 *  by Igor Ryzhkov (igor.o.ryzhkov@gmail.com)
 */ 

// Note: ISR stands for Interrupt Service Routine

// Global variables
volatile int  realTargetDirection = 0, 
              targetDirection = 0, 
              currentDirection = 0;

volatile byte dangerCode = 0;

void setup() 
{
  Serial.begin(9600);
  timer_setup();
  motors_setup();
  sensors_setup();
}

void loop() 
{
  if (Serial.available()) 
  {
    Serial.read();
    Serial.println("I am here");
  }
}
