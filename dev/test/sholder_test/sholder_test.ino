// Robot arm control test
#include <Stepper.h>

//Number of steps per output rotation stepper
const int stepsPerRevolution = 200;

Stepper sholder(stepsPerRevolution, 39, 37,35, 33);

void setup() {
  sholder.setSpeed(100);
  Serial.begin(9600);

  Serial.println("clockwise");
  sholder.step(200);
  delay(500);
  //Serial.println("counerclockwise");
  //sholder.step(-stepsPerRevolution);
  //delay(500);
}

void loop() {}
