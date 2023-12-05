int BUZZER = 3;
int rLed = 6;
int gLed = 5;
int bLed = 4;

int SWITCH = 7;
int TEMP = A0;
int COIL = 8;

int onThreshold = 3000;
int currentOnTime = 0;
int previousOnTime = 0;


void CheckTime() {
  currentOnTime = millis();
  
  Serial.println(currentOnTime);
  Serial.println(previousOnTime);
  
  if ((currentOnTime - previousOnTime) >= onThreshold) {
    for (int i = 0; i <3; i++) {
      tone(BUZZER, 500, 1000);
      noTone(BUZZER);
      delay(1000);
    }

    previousOnTime = currentOnTime;
  }

}


void setup() {
  // put your setup code here, to run once:
  pinMode(BUZZER, OUTPUT);
  pinMode(rLed, OUTPUT);
  pinMode(gLed, OUTPUT);
  pinMode(bLed, OUTPUT);

  Serial.begin(115200);

  // PowerSwitchOnI();
  previousOnTime = millis(); 
}

void loop() {
  // put your main code here, to run repeatedly:
  CheckTime();
}
