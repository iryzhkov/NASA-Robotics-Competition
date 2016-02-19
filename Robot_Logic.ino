/*  CODE FOR NASA ROBOTICS CHALLANGE 2016
 *  by Igor Ryzhkov (igor.o.ryzhkov@gmail.com)
 *  
 *  Defines methods in Robot_Logic.h
 */

Robot_Logic::Robot_Logic (Movement_Control *control, Sensor_Logic *sensors) {
    this->control = control;
    this->sensors = sensors;
    
    this->process_id = 0;

    this->Tasks[0] = &Robot_Logic::Go_Towards_Beacon;
    this->Tasks[1] = &Robot_Logic::Move_Forward;
    this->Tasks[2] = &Robot_Logic::Avoid_Possible_Obstacle_On_Side;
    this->Tasks[3] = &Robot_Logic::Avoid_Definite_Obstacle_On_Side;
    this->Tasks[4] = &Robot_Logic::Avoid_Obstacle_In_Front;
    this->Tasks[5] = &Robot_Logic::Avoid_Pit_On_Side;
    this->Tasks[6] = &Robot_Logic::Avoid_Pit_In_Front;
}

int Robot_Logic::Get_Process_ID () {
    return this->process_id;
}

int Robot_Logic::Get_Subprocess_ID () {
    return this->subprocess_id;
}

void Robot_Logic::Update_Sensors () {
    this->sensors->Update_Sensors();

    this->danger_id = this->sensors->Get_Danger_ID();
    this->side_id = this->sensors->Get_Side_ID();
}

void Robot_Logic::main () {
    this->sensors->Update_Sensors();
  
    if (this->danger_id > this->process_id) {
        this->process_id = this->danger_id;
        this->subprocess_id = 0;
    }

    // Don't freak out about the next line of code.
    // It calls a function from the array
    // This is supposed to make the code cleaner.
    // As you can see I don't need to do the switch
    // And this is very modifiable (i.e. adding another function to array does not change this code)
    (this->*Tasks[process_id])();
}

void Robot_Logic::Go_Towards_Beacon () {
   /* Robot_Logic::Go_Towards_Beacon
   * 
   * Moves the robot towards the beacon
   * 
   * I didn't decide if I am going to use regular or differential turn.
   */

    // This takes care of all the cases conected with going towards the beacon. 
    // Isn't it just beautiful?
    
    this->subprocess_id = this->sensors->Get_Beacon_Direction();
    this->control->Differential_Turn(this->subprocess_id);
}


void Robot_Logic::Move_Forward () {
  /* Robot_Logic::Move_Forward
   * 
   * goes forward for (process_time / 20) seconds or until there is something ahead (whichever one is quicker)
   * 
   * before calling it, please set the process_time to the nedded value.
   */
    
    if (process_time <= 0)
        this->process_id = 0;
        return;

    process_time -= 1;
    this->control->Move_Forward();
}

void Robot_Logic::Avoid_Possible_Obstacle_On_Side () {
    // This will be the usual look of the functions with several subprocesses. 
    // At subprocess 0 we initialize, and set subproces to 1
    // At subprocess 1 we do 1 step, if we finished the step, we either change subprocess anr process id.
    // Same for other integers.
  
    switch (this->subprocess_id) {
    case 0: {
        this->process_time = 20;
        this->subprocess_id = 1;
    };
    case 1: {     
        // take 50 miliseconds away from requierd time
        // and set controls to do the turn towards the side without obstacles
        this->process_time -= 1;
        this->control->Differential_Turn(this->side_id);

        // if we are finished exit this process.
        if (this->process_time <= 0) {
          
            // Start going forward for some time
            this->process_time = 10;
            this->process_id = 1;
            break;
        }
    };
    }
}

void Robot_Logic::Avoid_Definite_Obstacle_On_Side () {
    this->process_id = 1;
}

void Robot_Logic::Avoid_Obstacle_In_Front () {
    this->process_id = 1;
}

void Robot_Logic::Avoid_Pit_On_Side () {
    this->process_id = 1;
}

void Robot_Logic::Avoid_Pit_In_Front () {
     this->process_id = 1;
}
