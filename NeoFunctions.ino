void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}



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

void HeatStandbyI();
  digitalWrite(rLed, LOW);
  digitalWrite(gLed, LOW);
  digitalWrite(bLed, HIGH);
  delay(100);

void CheckTime() {
  currentTime = millis();
  
  if (currentTime >= indicator) {
    for (int i = 0, i <3, i++) {
      tone(BUZZER, 500, 1000);
      noTone();
      delay(1000);
    }

    previousTime = currentTime;
  }

}


void PowerFailI() {
  digitalWrite(rLed, HIGH);
  digitalWrite(gLed, LOW);
  digitalWrite(bLed, LOW);
  delay(100);

  while (true) {
  tone(BUZZER, 1000, 1000);
  noTone();
  delay(1000);
  }
}


void Heating(); {
  digitalWrite(COIL, HIGH);
  delay(60000);
}