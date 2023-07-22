#include "my_servo.h"

Servo x_servo;
Servo y_servo;

head::head(int x_pin, int y_pin) {
  _x_pin = x_pin;
  _y_pin = y_pin;
  x_servo.attach(x_pin);
  y_servo.attach(y_pin);
  x_servo.write(90);
  y_servo.write(90);
}

void head::nod(int count) {
  for (int i = 0; i < count; i++) {
    y_servo.write(45);
    delay(500);
    y_servo.write(135);
    delay(500);
  }
  y_servo.write(90);
}

void head::shake(int count) {
  for (int i = 0; i < count; i++) {
    x_servo.write(45);
    delay(500);
    x_servo.write(135);
    delay(500);
  }
  x_servo.write(90);
}
