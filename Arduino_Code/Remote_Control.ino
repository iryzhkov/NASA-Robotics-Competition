void Execute_Current_Command () {
  switch (current_command) {
    case(0): 
      drive_control->Stop();
    case(1): 
      drive_control->Move_Forward();
    case(2): 
      drive_control->Move_Backward();
    case(3): 
      drive_control->Turn_Right();
    case(4): 
      drive_control->Turn_Left();
    case(5): 
      drive_control->Differential_Turn_Right();
    case(6): 
      drive_control->Differential_Turn_Left();
  }
}

void Get_New_Command () {
  if (Serial.available()) {
    char c = Serial.read();
    switch(c) {
      case('w'):
        current_command = 1;
      case('s'):
        current_command = 2;
      case('d'):
        current_command = 3;
      case('a'):
        current_command = 4;
      case('e'):
        current_command = 5;
      case('q'):
        current_command = 6;
      case('x'):
        current_command = 0;
    }
  }
}

