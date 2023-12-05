int BUZZER = 3;
int rLed = 6;
int gLed = 5;
int bLed = 4;

int COIL = 9;

int onThreshold = 1800000;
int currentOnTime = 0;
int previousOnTime = 0;


// Buzzer function
void BuzzerOn(int frequency, int timer, int num) {
  for (int i = num; i > 0; i--) {
    tone(BUZZER, frequency);
    delay(timer);
    noTone(BUZZER);
    delay(timer);
  }
}


// Power indicators
void PowerSwitchOnI() {
  digitalWrite(rLed, HIGH);
  digitalWrite(gLed, HIGH);
  digitalWrite(bLed, HIGH);
  delay(2000);
}

void PowerSwitchOffI() {
  digitalWrite(rLed, LOW);
  analogWrite(gLed, LOW);
  digitalWrite(bLed, LOW);
  delay(200);
}

/* Heating on */
// Heating mode indicators
void HeatOnI() {
  digitalWrite(rLed, LOW);
  digitalWrite(gLed, HIGH);
  digitalWrite(bLed, LOW);
  delay(100);
}

// Actual heating
void HeatingOn() {
  digitalWrite(COIL, HIGH);
  delay(2000);
}

/* Heating standby */
// Indicator
void HeatStandbyI() {
  digitalWrite(rLed, LOW);
  digitalWrite(gLed, LOW);
  digitalWrite(bLed, HIGH);
  delay(100);
}

// Heating on standby
void HeatingOff() {
  digitalWrite(COIL, LOW);
  delay(6000);
}


void setup() {
  // put your setup code here, to run once:
  pinMode(BUZZER, OUTPUT);
  pinMode(rLed, OUTPUT);
  pinMode(gLed, OUTPUT);
  pinMode(bLed, OUTPUT);

  Serial.begin(115200);

  PowerSwitchOnI();
  PowerSwitchOffI();

  BuzzerOn(500, 2000, 2);

  previousOnTime = millis(); 
}


void loop() {
  HeatOnI();
  HeatingOn();

  HeatStandbyI();
  HeatingOff();
}
