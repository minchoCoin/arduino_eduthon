#include <Servo.h>

//please README.md before programming!

Servo x_servo;
Servo y_servo;

void nod(int count) { // 고개 끄덕이기
  for (int i = 0; i < count; i++) {
    y_servo.write(45);
    delay(500);
    y_servo.write(135);
    delay(500);
  }
  y_servo.write(90);
}

void shake(int count) { // 고개 가로젓기
  for (int i = 0; i < count; i++) {
    x_servo.write(45);
    delay(500);
    x_servo.write(135);
    delay(500);
  }
  x_servo.write(90);
}

void setup() {
  // put your setup code here, to run once:
  x_servo.attach(2);
  y_servo.attach(3);
  x_servo.write(90); // 서보모터 초기화
  y_servo.write(90); // 서보모터 초기화
}

void loop() {
  // put your main code here, to run repeatedly:
}
