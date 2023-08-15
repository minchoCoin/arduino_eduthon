#define NOISE_PIN A0

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
void setup() {
  // put your setup code here, to run once:
  pinMode(NOISE_PIN,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
}