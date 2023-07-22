#include <Servo.h>

Servo myServo;

void setup(){
  myServo.attach(2);  // ~PWM 아두이노 핀 번호를 선언한다.
  myServo.write(0);   // 서보모터의 초기 각도 값을 '0'으로 선언한다.
}

void loop(){
  
}