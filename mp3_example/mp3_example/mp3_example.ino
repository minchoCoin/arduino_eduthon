#include <SoftwareSerial.h> //Library SoftwareSerial
#include <DFPlayer_Mini_Mp3.h> //Library DFPlayer mini MP3
SoftwareSerial serial(6, 7); // pin TX, RX //mp3

/*
그래 0
다시한번 물어봐 1
돼 2
마음대로 해 3
아니 4
안돼 5
하지마 6
*/
void setup (){
 serial.begin (9600);
 mp3_set_serial (serial); 
 delay(5); 
 mp3_set_volume (20);   //0~30
 delay(1000);
}
void testmp3(){
    boolean play_state = digitalRead(3);// connect Pin3 to BUSY pin of player(버즈핀 3번)
    while(play_state == HIGH){
        mp3_next ();
        //후에 테스트 중간에 끝낼 수 있는 거 하면 좋음
    }
}
// 딜레이 1초
void volumeup(int volume){
    mp3_set_volume(volume+1)
}
void volumedown(int volume){
    mp3_set_volume(volume-1)
}
void mp3_ground(int a){
    mp3_play(a);
    delay(1000);
}
//sleep 전력 절전 모드 0
//일반 모드 1
void mode(int mode){
    if(mode==0){
        mp3_sleep();
    }
    if(mode==1){
        mp3_outputDevice(DFPLAYER_DEVICE_SD);
    }
}
void loop (){ 
}
