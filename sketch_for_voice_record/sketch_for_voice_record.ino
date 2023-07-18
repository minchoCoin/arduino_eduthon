#include <Arduino.h>
#include <Mecha_VoiceRecognition.h>
#include <SoftwareSerial.h>

// 모듈과의 통신을 위한 SoftwareSerial 객체 생성.
// 2번핀에 모듈의 Tx, 3번핀에 Rx가 연결됨.
SoftwareSerial uart_voice(2, 3);

// voice 객체 생성
// 이때 모듈의 UART 통신을 위해 앞서 생성한 uart_voice를 함께 전달
Mecha_VoiceRecognition voice(&uart_voice);

void setup() {
  // 디버그용 하드웨어 시리얼 통신 초기화
  Serial.begin(9600);
  
  // voice 객체 설정 및 초기화
  voice.setDebugOn(&Serial);  // 디버깅 ON, 디버깅을 위한 통신 객체 전달
  voice.setGroup(VOICE_GROUP_1);  // 녹음에 사용할 그룹을 1로 설정
  voice.init();                   // voice 객체 초기화

  voice.setMode(VOICE_MODE_RECORDING); // 모듈을 녹음 모드로 설정(녹음 시작)
}

void loop() {
}