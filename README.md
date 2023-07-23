# arduino_eduthon
arduino_eduthon - Magic Conch

author : 김태훈, 김정원, 박재홍, 이성훈

**구현해야하는 기능**
 1. mp3모듈
 2. 서브모터(2개)(2개 축)(고개를 끄덕이는 것, 몸을 상하로 움직이는 기능)
 3. 상황에 따른 음성인식
 4. 로봇에 이름을 "코코"라고 부르면 명령을 인식하는 것으로 하기

**Arduino driver - CH340**
 - https://j2hun-1315.tistory.com/19

**아두이노 음성인식 관련**
 - 필요한 라이브러리 : MechaSolution Voice Recognition Module
 - https://blog.naver.com/roboholic84/222739724592 
 - 선 연결 : PIN 4, PIN 5
 
**OLED 관련**
 - 필요한 라이브러리 : Adafruit_GFX, Adafruit_SSD1306
 - 상품상세설명참조 : https://www.devicemart.co.kr/goods/view?no=1384296
 - https://m.blog.naver.com/steamedu123/221469846798
 - 예제 : http://www.elecrow.com/download/ELecrow%20OLED96.zip
 - 선 연결 : 9,10,11,12,13
 
**서보모터 관련**
 - 필요한 라이브러리 : Servo
 - https://m.blog.naver.com/no1_devicemart/221980598037 (무한회전 서보모터)
 - https://codingrun.com/110 (180도 서보모터) 
 - 선 연결 : 2,3
 
 **LCD 관련**
 - 필요한 라이브러리 : LiquidCrystal i2c
 - https://blog.naver.com/intopion/221481704847
 - 선 연결 : A4, A5
 you can download library on library manager

 **TTS 관련**
 - DFPlayer_mini 사용하기 :https://deneb21.tistory.com/418
 - 클로바 더빙 사용하기 : https://clovadubbing.naver.com/
 - 선 연결 : 0,1

 **소리감지관련**
 - https://m.blog.naver.com/icbanq/222588844355
 - 핀 연결 : A0

 **스피커 관련**
 - https://m.blog.naver.com/emperonics/222197590991
 - 핀 연결 : 4,5(RX,TX)