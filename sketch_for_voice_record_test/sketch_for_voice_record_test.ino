#include <Arduino.h>
#include <Mecha_VoiceRecognition.h>
#include <SoftwareSerial.h>

#define PIN_LED_GREEN 4   // 4번 핀에 초록색 LED 연결됨
#define PIN_LED_YELLOW 5  // 5번 핀에 노란색 LED 연결됨
#define PIN_LED_RED 6     // 6번 핀에 빨간색 LED 연결됨

// 모듈과의 통신을 위한 SoftwareSerial 객체 생성.
// 2번핀에 모듈의 Tx, 3번핀에 Rx가 연결됨.
SoftwareSerial uart_voice(2, 3);

// voice 객체 생성
// 이때 모듈의 UART 통신을 위해 앞서 생성한 uart_voice를 함께 전달
Mecha_VoiceRecognition voice(&uart_voice);

void setup() {
  // GPIO 초기화
  

  // 디버그용 하드웨어 시리얼 통신 초기화
  Serial.begin(9600);

  // voice 객체 설정 및 초기화
  voice.setDebugOn(&Serial);  // 디버깅 ON, 디버깅을 위한 통신 객체 전달
  voice.setGroup(VOICE_GROUP_1);  // 인식에 사용할 그룹을 1로 설정
  voice.init();                   // voice 객체 초기화

  voice.setMode(VOICE_MODE_RECOGNITION);  // 모듈을 인식 모드로 설정
}

void loop() {
  // 모듈의 응답을 response 변수에 저장.
  // VOICE_InstructionTypeDef 자료형은 열거형으로, 아래 상태를 가짐.
  // VOICE_INSTRUCTION_1: 선택된 그룹의 1번 명령 인식됨
  // VOICE_INSTRUCTION_2: 선택된 그룹의 2번 명령 인식됨
  // VOICE_INSTRUCTION_3: 선택된 그룹의 3번 명령 인식됨
  // VOICE_INSTRUCTION_4: 선택된 그룹의 4번 명령 인식됨
  // VOICE_INSTRUCTION_5: 선택된 그룹의 5번 명령 인식됨
  // VOICE_INSTRUCTION_NOTHING: 아무 내용도 인식되지 않음
  // VOICE_INSTRUCTION_ERROR: 예외 발생

  VOICE_InstructionTypeDef response = voice.getInstruction();
  switch (response) {
    case VOICE_INSTRUCTION_1: // 1번 명령 인식됨.
      Serial.println("Coco");
      
      break;
    case VOICE_INSTRUCTION_2: // 2번 명령 인식됨.
      Serial.println("can");
      
      break;
    case VOICE_INSTRUCTION_3: // 3번 명령 인식됨.
      Serial.println("cant");
     
      break;
    case VOICE_INSTRUCTION_4: // 4번 명령 인식됨.
      Serial.println("dance");
      
      break;
    case VOICE_INSTRUCTION_5: // 5번 명령 인식됨.
      Serial.println("stop");
      
      break;
    case VOICE_INSTRUCTION_ERROR: // 에러 발생
      Serial.println("error");
      break;
    case VOICE_INSTRUCTION_NOTHING: // 명령 인식되지 않음
      // no data recieved
     
      break;
  }
}