#ifndef my_servo_h
#define my_servo_h

#include <Arduino.h>
#include <Servo.h>

class head
{
  public :
    void nod(int count); // 고개를 끄덕이기
    void shake(int count); // 고개를 가로젓기
}

#endif
