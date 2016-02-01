/*  CODE FOR NASA ROBOTICS CHALLANGE 2016
 *  by Igor Ryzhkov (igor.o.ryzhkov@gmail.com)
 */ 

void timer_setup () {
  // setting Timer1 for 100 miliseconds. (this will be the timer, that checks the inputs from the sensors, and decides what to do next.
  //http://www.instructables.com/id/Arduino-Timer-Interrupts/?ALLSTEPS
  TCCR1A = 0;// set entire TCCR1A register to 0
  TCCR1B = 0;// same for TCCR1B
  TCNT1  = 0;//initialize counter value to 0
  // set compare match register for 1000000hz increments with 8 bits prescaler
  OCR1A = 20;//better to put this line AFTER configuring TCCR1A and B, but in Arduino 1.6.0 it appears to be ok here (may crash code in older versions, see comment by "Thorsten" here: http://www.righto.com/2009/07/secrets-of-arduino-pwm.html
  // turn on CTC mode [Clear Timer on Compare match---to make timer restart at OCR1A; see datasheet pg. 133]
  TCCR1B |= (1 << WGM12); 
  // Set CS11 bit for 8 prescaler [0.5us ticks, datasheet pg. 135]. Each timer has a different bit code to each prescaler
  TCCR1B |= (1 << CS12);
  TCCR1B |= (1 << CS10);
  // enable timer compare match 1A interrupt; NOW YOU *MUST* SET UP THE CORRESPONDING ISR OR THIS LINE BREAKS THE CODE
  TIMSK1 |= (1 << OCIE1A); 
}

// Interupt Service Routine for updating sensor inputs, and changing danger code.
ISR(TIMER1_COMPA_vect)
{
  //insert your code here that you want to run every time the counter reaches OCR1A
  int b = 2 + 2;
  use_sensors();
}
