#define NOISE_PIN A0

bool isNoise(){
  return analogRead(NOISE_PIN)>=40;
}



void setup() {
  // put your setup code here, to run once:
  pinMode(NOISE_PIN,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
}