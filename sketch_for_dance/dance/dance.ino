void dance(){
    int voiceRecognitionNum;
    int xAngle = 90; //45 90 135
    int yAngle = 80; //80 107   135

    int type = 1;
    int isPlus = 1;
   
    x_servo.write(xAngle);
    y_servo.write(yAngle);
    delay(100);
    while(1){
    if(getVoiceRecognition()==1){
      display_4();
      y_servo.write(90);
      x_servo.write(45);
      unsigned long start = millis();

      while(1){
      voiceRecognitionNum = getVoiceRecognition();
      if(voiceRecognitionNum == 1) start = millis();
      
      if(millis() - start>5000 || voiceRecognitionNum!=0 && voiceRecognitionNum!=1){
        x_servo.write(90);
        break;
      }
      }
      if(voiceRecognitionNum == 5){
        x_servo.write(90);
        y_servo.write(90);
        break;
      }

    }
    int num = random(4);
    switch(num){
      case 0:
        display_1();
        break;
      case 1:
        display_3();
        break;
      case 2:
        display_4();
        break;
      case 3:
        display_5();
        break;
    }
    if(type==0){
      x_servo.write(45);
      y_servo.write(135);
      delay(5);
    }
    else if(type==1){
      x_servo.write(90);
      y_servo.write(80);
      delay(5);
    }
    else{
      x_servo.write(135);
      y_servo.write(135);
      delay(5);
    }

    if(type<=0 || type>=2) isPlus = !isPlus;

    if(isPlus) type++;
    else type--;

  }
  
}