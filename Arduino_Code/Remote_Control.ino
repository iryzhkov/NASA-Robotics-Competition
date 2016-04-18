void Execute_Current_Command () {
  Serial.println (current_command);

  if (current_command == 0) drive_control->Stop();
  if (current_command == 1) drive_control->Move_Forward();
  if (current_command == 2) drive_control->Move_Backward();
  if (current_command == 3) drive_control->Turn_Right();
  if (current_command == 4) drive_control->Turn_Left();
  if (current_command == 5) drive_control->Differential_Turn_Right();
  if (current_command == 6) drive_control->Differential_Turn_Left();
}

void Get_New_Command () {
  if (Serial.available()) {
    char c = Serial.read();

    if (c == 'w') current_command = 1;
    if (c == 's') current_command = 2;
    if (c == 'a') current_command = 3;
    if (c == 'd') current_command = 4;
    if (c == 'q') current_command = 5;
    if (c == 'e') current_command = 6;
    if (c == 'x') current_command = 0;
  }
}

