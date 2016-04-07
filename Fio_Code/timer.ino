void Set_Up_Timer () {
  cli();//stop interrupts

  TCCR1A = 0;// set entire TCCR1A register to 0
  TCCR1B = 0;// same for TCCR1B
  TCNT1  = 0;//initialize counter value to 0
  // set compare match register for 1hz increments
  OCR1A = 15624;// = (16*10^6) / (1*1024) - 1 (must be <65536)
  // turn on CTC mode
  TCCR1B |= (1 << WGM12);
  // Set CS10 and CS12 bits for 1024 prescaler
  TCCR1B |= (1 << CS12) | (0 << CS11);  
  // enable timer compare interrupt
  TIMSK1 |= (1 << OCIE1A);

  sei();//allow interrupts 
}

ISR(TIMER1_COMPA_vect){//timer1 interrupt 1Hz updates the pin value depending on the direction and beacon direation
  sei();
  float compass_heading = Get_Compass_Heading();
  cli();

  //Serial.print (compass_heading);
  //Serial.print (" ");
  
  if (compass_heading > beacon_heading){
    if (compass_heading - beacon_heading <= 180) {
      // Beacon is to the left
      digitalWrite(OUTPUT_PIN, LOW);
      //Serial.println ("-1");
    }
    else {
      // Beacon is to the right
      digitalWrite(OUTPUT_PIN, HIGH);
      //Serial.println ("1");
    }
  }
  else {
    if (beacon_heading - compass_heading <= 180) {
      // Beacon is to the right
      digitalWrite(OUTPUT_PIN, HIGH);
      //Serial.println ("1");
    }
    else {
      // Beacon is to the left
      digitalWrite(OUTPUT_PIN, LOW);
      //Serial.println ("-1");
    }
  }
}
