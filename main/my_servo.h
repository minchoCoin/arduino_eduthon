#ifndef my_servo_h
#define my_servo_h

#include <Arduino.h>
#include <Servo.h>

class head
{
  public:
    head(int x_pin, int y_pin); // x축, y축 핀 번호
    void nod(int count); // 고개를 끄덕이기
    void shake(int count); // 고개를 가로젓기

  private:
    int _x_pin;
    int _y_pin;
}

#endif
