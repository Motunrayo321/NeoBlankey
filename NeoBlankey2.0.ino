int BUZZER = 3;
int rLed = 6;
int gLed = 5;
int bLed = 4;

int SWITCH = 7;
int TEMP = A0;
int COIL = 8;

int highTemp = 32;
int temp = 0;

int onThreshold = 1800000;
int currentOnTime = 0;
int previousOnTime = 0;

int tempTimeThreshold = 300000;
int currentTempOnTime = 0;
int previousTempOnTime = 0;



void PowerSwitchOnI() {
  digitalWrite(rLed, HIGH);
  digitalWrite(gLed, HIGH);
  digitalWrite(bLed, HIGH);
  delay(2000);
}

void PowerSwitchOffI() {
  digitalWrite(rLed, HIGH);
  analogWrite(gLed, 135);
  digitalWrite(bLed, LOW);
  delay(2000);
}

void HeatOnI() {
  digitalWrite(rLed, LOW);
  digitalWrite(gLed, HIGH);
  digitalWrite(bLed, LOW);
  delay(100);
}

void HeatStandbyI() {
  digitalWrite(rLed, LOW);
  digitalWrite(gLed, LOW);
  digitalWrite(bLed, HIGH);
  delay(100);
}

void CheckTime() {
  currentOnTime = millis();
  
  if (currentOnTime >= onThreshold) {
    for (int i = 0; i <3; i++) {
      tone(BUZZER, 500, 1000);
      noTone(BUZZER);
      delay(1000);
    }

    previousOnTime = currentOnTime;
  }

}

void CheckTemp() {
  if (currentTempOnTime >= tempTimeThreshold) {
     // temp = analogRead(TEMP);

    if (temp > highTemp) {
      digitalWrite(COIL, LOW);
      delay(500);

      for (int i = 0; i <3; i++) {
        tone(BUZZER, 500, 1000);
        noTone(BUZZER);
        delay(1000);
      }
    }

    previousTempOnTime = currentTempOnTime;
  }

}


void PowerFailI() {
  digitalWrite(rLed, HIGH);
  digitalWrite(gLed, LOW);
  digitalWrite(bLed, LOW);
  delay(100);

  while (true) {
  tone(BUZZER, 1000, 1000);
  noTone(BUZZER);
  delay(1000);
  }
}


void Heating() {
  digitalWrite(COIL, HIGH);
  delay(60000);
}


void setup() {
  // put your setup code here, to run once:
  pinMode(BUZZER, OUTPUT);
  pinMode(rLed, OUTPUT);
  pinMode(gLed, OUTPUT);
  pinMode(bLed, OUTPUT);

  Serial.begin(115200);

  PowerSwitchOnI();
  previousOnTime = millis(); 
}

void loop() {
  // put your main code here, to run repeatedly:
  int switchMode = analogRead(SWITCH);
  if (SWITCH == HIGH) {
    HeatOnI();
    Heating();

    /*
    CheckIfSafe();
    delay(1000);
    */

    HeatStandbyI();
    delay(120000);

    CheckTime();
    CheckTemp();
  }

  else {
    PowerSwitchOffI();
  }

}
