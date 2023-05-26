// wrist control test
#include <Servo.h>

const int SERVO_PIN = 12;
Servo wrist;

int pos = 0;

void setup(){
  wrist.attach(SERVO_PIN);
}

void loop() {
  for (pos = 0; pos <= 180; pos += 1){
    wrist.write(pos);
    delay(15);
    }
  for (pos = 180; pos >= 0; pos -= 1){
    wrist.write(pos);
    delay (15);
    }
}
