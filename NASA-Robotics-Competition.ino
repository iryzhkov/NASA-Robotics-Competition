#include <decision.h>

#define IR1in 1
#define IR1out 2
#define IR2in 3
#define IR2out 4

#define LeftMotors 5
#define RightMotors 6

void setup() {
  // put your setup code here, to run once:
}

void loop() {
  doScanning();
  if (haveUpdates()) {getUpdates();}
  
  if (inDanger()) {
    quickBreak();
  }
}

bool inDanger () {
  return false;
}

bool haveUpdates() {
  return false;
}

void getUpdates() {
  int a = 1 + 1;
}

void quickBreak() {
  int b = 2 + 2;
}

void doScanning() {
  int c = 3 + 3;
}
