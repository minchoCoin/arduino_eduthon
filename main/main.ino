#include <SoftwareSerial.h> //Library SoftwareSerial
#include <DFPlayer_Mini_Mp3.h> //Library DFPlayer mini MP3
#include <Servo.h>
#include "expression.h"

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include <Arduino.h>
#include <Mecha_VoiceRecognition.h>

#define OLED_DC 11
#define OLED_CS 12
#define OLED_CLK 10
#define OLED_MOSI 9
#define OLED_RESET 13
Adafruit_SSD1306 display(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);


SoftwareSerial mp3_serial(6, 7); // pin TX, RX //mp3

SoftwareSerial uart_voice(2, 3); //voice recognition
Mecha_VoiceRecognition voice(&uart_voice);

#define NOISE_PIN A0

Servo x_servo;
Servo y_servo;

//mp3 module

void testmp3(){
    boolean play_state = digitalRead(3);// connect Pin3 to BUSY pin of player(버즈핀 3번)
    while(play_state == HIGH){
        mp3_next ();
        //후에 테스트 중간에 끝낼 수 있는 거 하면 좋음
    }
}
// 딜레이 1초
void volumeup(int volume){
    mp3_set_volume(volume+1);
}
void volumedown(int volume){
    mp3_set_volume(volume-1);
}
void mp3_ground(int a){
    mp3_play(a);
    delay(1000);
}
//sleep 전력 절전 모드 0
//일반 모드 1
/*
void mp3_mode(int mode){
    if(mode==0){
        mp3_sleep();
    }
    if(mode==1){
        mp3_outputDevice(DFPLAYER_DEVICE_SD);
    }
}
*/
//mp3 module

//servo
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
//servo

//soundDetection
int getNoiseStep(){
  int value = analogRead(NOISE_PIN);

  value = value - 1; //error value

  if(value<50) return 0;
  else if(50<=value && value<70) return 1;
  else if(70<=value && value<90) return 2;
  else if(90<=value && value<110) return 3;
  else if(110<=value && value<130) return 4;
  else if(130<=value && value<150) return 5;
  else if(150<=value && value<170) return 6;
  else if(170<=value && value<190) return 7;
  else return 8;
  
 
}
//soundDetection

//OLED


void display_1(){
   display.clearDisplay();  // Clear OLED
  display.drawBitmap(0, 0,  exp_1, 128, 64, 1); // drawbitmap (X,Y,*unsigned char,W,H,1)
  display.display(); // display OLED
}
void display_2(){
   display.clearDisplay();  // Clear OLED
  display.drawBitmap(0, 0,  exp_2, 128, 64, 1); // drawbitmap (X,Y,*unsigned char,W,H,1)
  display.display(); // display OLED
}
void display_3(){
   display.clearDisplay();  // Clear OLED
  display.drawBitmap(0, 0,  exp_3, 128, 64, 1); // drawbitmap (X,Y,*unsigned char,W,H,1)
  display.display(); // display OLED
}
void display_4(){
   display.clearDisplay();  // Clear OLED
  display.drawBitmap(0, 0,  exp_4, 128, 64, 1); // drawbitmap (X,Y,*unsigned char,W,H,1)
  display.display(); // display OLED
}

void display_5(){
   display.clearDisplay();  // Clear OLED
  display.drawBitmap(0, 0,  exp_5, 128, 64, 1); // drawbitmap (X,Y,*unsigned char,W,H,1)
  display.display(); // display OLED
}

void display_6(){
   display.clearDisplay();  // Clear OLED
  display.drawBitmap(0, 0,  exp_6, 128, 64, 1); // drawbitmap (X,Y,*unsigned char,W,H,1)
  display.display(); // display OLED
}

bool isExpressionDefault=1;

//OLED

//voice recognition
/*
그래 0
다시한번 물어봐 1
돼 2
마음대로 해 3
아니 4
안돼 5
하지마 6
*/
int getVoiceRecognition(){
  VOICE_InstructionTypeDef response = voice.getInstruction();
  switch (response) {
    case VOICE_INSTRUCTION_1: // 1번 명령 인식됨.
      Serial.println("Voice_1");
      return 1;
      break;
    case VOICE_INSTRUCTION_2: // 2번 명령 인식됨.
      Serial.println("Yellow");
      return 2;
      break;
    case VOICE_INSTRUCTION_3: // 3번 명령 인식됨.
      Serial.println("Green");
      return 3;
      break;
    case VOICE_INSTRUCTION_4: // 4번 명령 인식됨.
      Serial.println("White");
      return 4;
      break;
    case VOICE_INSTRUCTION_5: // 5번 명령 인식됨.
      Serial.println("Black");
     return 5;
      break;
    case VOICE_INSTRUCTION_ERROR: // 에러 발생
      Serial.println("error");
      break;
    case VOICE_INSTRUCTION_NOTHING: // 명령 인식되지 않음
      // no data recieved
      break;
  }
  return 0;
}
//voice recognition

void mp3_setup(){
  mp3_serial.begin (9600);
  mp3_set_serial (mp3_serial); 
  delay(5); 
  mp3_set_volume (20);   //0~30
  delay(1000);
}

void servo_setup(){
  x_servo.attach(2);
  y_servo.attach(3);
  x_servo.write(90); // 서보모터 초기화
  y_servo.write(90); // 서보모터 초기화
}

void noise_setup(){
  pinMode(NOISE_PIN,INPUT);
}

void display_setup(){
  display.begin(SSD1306_SWITCHCAPVCC);  // Switch OLED
  display.clearDisplay();  // Clear OLED
  display.drawBitmap(0, 0,  exp_1, 128, 64, 1); // drawbitmap (X,Y,*unsigned char,W,H,1)
  display.display(); // display OLED
}

void voice_recognition_setup(){
  Serial.begin(14400);
  voice.setDebugOn(&Serial);  // 디버깅 ON, 디버깅을 위한 통신 객체 전달
  voice.setGroup(VOICE_GROUP_1);  // 인식에 사용할 그룹을 1로 설정
  voice.init();                   // voice 객체 초기화

  voice.setMode(VOICE_MODE_RECOGNITION);  // 모듈을 인식 모드로 설정
}

void setup() {
  // put your setup code here, to run once:
  mp3_setup();
  servo_setup();
  noise_setup();
  display_setup();
  voice_recognition_setup();
  randomSeed(analogRead(0));
}

//custom

void randAnswer(){
  int ans = random(7);
  
  if(ans==0){
    display_1();
    mp3_ground(0);
    nod(1);
  }
  else if(ans==1){
    display_2();
    mp3_ground(1);
  }
  else if(ans==2){
    display_3();
    mp3_ground(2);
  }
  else if(ans==3){
    display_4();
    mp3_ground(3);
  }
  else if(ans==4){
    display_2();
    mp3_ground(4);
    shake(1);
  }
  else if(ans==5){
    display_6();
    mp3_ground(5);
    shake(2);
  }
  else if(ans==6){
    display_6();
    mp3_ground(6);
    shake(3);
  }
}

void dance(){
  display_5();
  nod(2);
  shake(2);
  display_1();
}

void loop() {
  // put your main code here, to run repeatedly:


  /*
  void mp3_ground(int a) : a번 mp3 실행 그래 0, 다시한번 물어봐 1, 돼 2 ,마음대로 해 3, 아니 4, 안돼 5, 하지마 6
  void nod(int count) : count번 끄덕임
  void shake(int count) : count번 도리도리
  int getNoiseStep() : 데시벨에 따라 0~8까지 반환
  void display_1() : 1번 표정(긍정) 표시
  void display_2() : 3번 표정(부정) 표시
  void display_3() : 3번 표정(눈웃음) 표시
  void display_4() : 4번 표정(0w0) 표시
  void display_5() : 5번 표정(>.<) 표시
  void display_6() : 6번 표정(화남) 표시
  int getVoiceRecognition() : 반환값은 몇번째 말로 인식했는지 알려줌(1~5) 0번은 인식안됨
  */

  int voiceRecognitionNum = getVoiceRecognition();

  switch(voiceRecognitionNum){
    case 1:
      randAnswer();
      isExpressionDefault=0;
      break;
    case 2:
      isExpressionDefault=0;
      break;
    case 3:
      isExpressionDefault=0;
      break;
    case 4:
      isExpressionDefault=0;
      break;
    case 5:
      isExpressionDefault=0;
      break;
    default:
      if(!isExpressionDefault){
        display_1();
        isExpressionDefault=1;
      }
      break;
  }
}
