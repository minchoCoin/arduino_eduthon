#define NOISE_PIN A0

int getNoiseStep(){
  int value = analogRead(NOISE_PIN);

  if(value<=20) return 0;
  else if(20<value&&value<=25) return 1;
  else if(value<25&&value<=30) return 2;
  else if(value<30&&value<=35) return 3;
  else if(value<35&&value<=40) return 4;
  else if(value<40&&value<=45) return 5;
  else if(value<45&&value<=50) return 6;
  else if(value<50&&value<=55) return 7;
  else if(value<55&&value<=60) return 8;
  else if(value<60&&value<=65) return 9;
  else if(value<65&&value<=70) return 10;
  else if(value<70&&value<=75) return 11;
  else if(value<75&&value<=80) return 12;
  else return 13;
}
void setup() {
  // put your setup code here, to run once:
  pinMode(NOISE_PIN,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
}