#include <Servo.h>

Servo s;

int servo_pos = 0;

void setup() {
  s.attach(9);

}

void loop() {
  for(servo_pos = 0; servo_pos <= 180; servo_pos += 1) {
    s.write(servo_pos);
    delay(10);
  }

  for(servo_pos = 180; servo_pos >= 0; servo_pos -= 1) {
    s.write(servo_pos);
    delay(10);
  }

}
