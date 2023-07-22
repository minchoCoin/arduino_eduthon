#include <SoftwareSerial.h>             //Library SoftwareSerial
#include <DFPlayer_Mini_Mp3.h>  //Library DFPlayer mini MP3
 SoftwareSerial serial(10, 11);            // pin TX, RX
 void setup (){
  serial.begin (9600);  
  mp3_set_serial (serial);         
  delay(5); 
  mp3_set_volume (20);          
  delay(1000);
}

void loop (){  
  mp3_play(1);                         
  delay(240000);                    
  mp3_next();
  mp3_play(2);                        
  delay(10000);                       
  mp3_stop();                         
}
