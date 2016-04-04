void Set_Up_Timer () {
  cli();//stop interrupts

  //set timer1 interrupt at 1Hz
  TCCR1A = 0;// set entire TCCR1A register to 0
  TCCR1B = 0;// same for TCCR1B
  TCNT1  = 0;//initialize counter value to 0
  // set compare match register for 1hz increments
  OCR1A = 15624;// = (16*10^6) / (1*1024) - 1 (must be <65536)
  // turn on CTC mode
  TCCR1B |= (1 << WGM12);
  // Set CS12 and CS10 bits for 1024 prescaler
  TCCR1B |= (1 << CS12) | (1 << CS10);  
  // enable timer compare interrupt
  TIMSK1 |= (1 << OCIE1A);

  sei();//allow interrupts 
}

ISR(TIMER1_COMPA_vect){//timer1 interrupt 1Hz updates the pin value depending on the direction and beacon direation
  //generates pulse wave of frequency 1Hz/2 = 0.5kHz (takes two cycles for full wave- toggle high then toggle low)
  float compass_heading = Get_Compass_Heading();
  
  if (compass_heading > beacon_heading){
    if (compass_heading - beacon_heading <= 180) {
      // turn left
    }
    else {
      // turn right
    }
  }
  else {
    if (beacon_heading - compass_heading <= 180) {
      // turn right
    }
    else {
      // turn left
    }
  }
}
