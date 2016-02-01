/*  CODE FOR NASA ROBOTICS CHALLANGE 2016
 *  by Igor Ryzhkov (igor.o.ryzhkov@gmail.com)
 *  
 *  This is the main function. It uses all other classes and functions to control the robot.
 */ 

// Note: ISR stands for Interrupt Service Routine

// Global variables
#define LED 13

volatile  unsigned  long  timerCounter = 0;
          unsigned  long  previousTimerCounter = 0;

volatile  int   realTargetDirection = 0, 
                targetDirection = 0, 
                currentDirection = 0;

volatile  byte  dangerCode = 0;

volatile  bool  light = false;



void setup() 
{
  Serial.begin(9600);

  pinMode(LED, OUTPUT);
}

void loop() 
{
  noInterrupts();
  unsigned long t = timerCounter;
  timerCounter = 0;
  interrupts();

  Serial.print ("# of timer counters: ");
  Serial.println (t);
  delay(1000);
}
