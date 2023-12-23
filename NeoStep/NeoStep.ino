// Digital pins
int BUZZER = 3;
int rLed = 6;
int gLed = 5;
int bLed = 4;

int COIL = 8;  // Heater pin (For switch - transistor)

int POWER = A1; // Battery input pin for checking battery percentage

int power = 0;


// Dht 11 values
#include <DHT.h>
#define DHT_TYPE DHT11
#define DHT_PIN 2

// Initialize DHT sensor
DHT dht(DHT_PIN, DHT_TYPE);


/*    For advanced timing check (Probably mutithreaded) 
int onThreshold = 1800000;
int currentOnTime = 0;
int previousonTime  = 0;
*/

int onTime = 5000;  // Time for active heating
int offTime = 10000;  // Time for heating standby mode (coil is off). Usually 2* onTime

// Temperature
int tempThreshold = 36.5;



// Buzzer function
void BuzzerOn(int frequency, int timer, int num) {  // Audio alarm for all functions
  for (int i = num; i > 0; i--) {
    tone(BUZZER, frequency);
    delay(timer);
    noTone(BUZZER);
    delay(timer);
    Serial.println("Buzzer function");

  }
}


// Power indicators
void PowerSwitchOnI() { // Light indication after device comes on
  digitalWrite(rLed, HIGH);
  digitalWrite(gLed, HIGH);
  digitalWrite(bLed, HIGH);
  delay(2000);
}

void PowerSwitchOffI() {  // Light indication to move to heating mode
  digitalWrite(rLed, LOW);
  analogWrite(gLed, LOW);
  digitalWrite(bLed, LOW);
  delay(200);
}

/* Heating on */
// Heating mode indicators
void HeatOnI() {  // Light to show that heating coil is actively on
  digitalWrite(rLed, LOW);
  digitalWrite(gLed, HIGH);
  digitalWrite(bLed, LOW);
  delay(100);
}

/* Heating standby */
// Indicator
void HeatStandbyI() { // Light to show that heating coil is temporarily off
  digitalWrite(rLed, LOW);
  digitalWrite(gLed, LOW);
  digitalWrite(bLed, HIGH);
  delay(100);
}


// Actual heating
void HeatingOn() {  // Function to give power and turn on (pass current) into heating coil
  digitalWrite(COIL, HIGH);
  delay(onTime);
}

// Heating on standby
void HeatingOff() { // Function to cut off power (open circuit) to heating coil
  digitalWrite(COIL, LOW);
  delay(offTime);
}

void DangerAlert() {  // Alert for emergency. Usually related to temperature. Repeats indefinitely
  digitalWrite(COIL, LOW);    // First turn off heating coil
  delay(500);

  while true {    // Commence while loop so heating stays off until user intervenes.
    digitalWrite(rLed, HIGH);
    digitalWrite(gLed, LOW);
    digitalWrite(bLed, LOW);
    delay(100);

    BuzzerOn(500, 2000, 2);   // Repeatedely sound alarm

    delay(1000);
  }
}

void PowerLowAlert() {    // Alert that battery is low. Device should still function (for at least 30 minutes) before turning off. User can swap batteries and charge them now

  digitalWrite(rLed, HIGH);
  digitalWrite(gLed, LOW);
  digitalWrite(bLed, LOW);
  delay(100);

  BuzzerOn(500, 2000, 4);

  delay(1000);

}


void TempCheck() {    // Function to check the temperature at regular intervals to make sure it is within the safe range
  // Delay for a few seconds between measurements
  delay(500);

  // Read temperature as Celsius
  float temperature = dht.readTemperature();

  // Check if reading was successful
  if (isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    DangerAlert(); (Adjust the alert to come on when reading is faulty more than once or when above threshold)    //Sound alarm as temp sensor may be detached from device (Needs improvement so it checks at least twice)

  } else {
    // Display temperature
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println(" °C");
  }

  if (temperature >= tempThreshold) {   // If the temperature is greater than the threshold, shut down the system while sounding an alert
    DangerAlert();
  }
}


// Battery percentage check
void PowerCheck() {   // Check the voltage left in the battery (Add another function for coil battery)
  power = analogRead(POWER);
  power = map(POWER, 0, 5, 0, 7.5);   // Map 5 volts on arduino to 7.4 (average) volts from the battery
  power = constrain(power, 0, 5);

  Serial.print("Battery voltage: ");
  Serial.println(power);
  }

  if (power <== 5.5) {    // 5.5 volts should still last 30 minutes. Should give user enough time to charge
    PowerLowAlert();
  }
}

void OnTimer() {    // Regular beeps to notify user that device is on
  BuzzerOn(500, 2000, 2);
}


void setup() {
  // put your setup code here, to run once:
  pinMode(BUZZER, OUTPUT);
  pinMode(rLed, OUTPUT);
  pinMode(gLed, OUTPUT);
  pinMode(bLed, OUTPUT);

  pinMode(POWER, INPUT);

  dht.begin();

  Serial.begin(115200);

  PowerSwitchOnI();   // Turn on power indicator when device first comes on
  PowerSwitchOffI();

  BuzzerOn(500, 2000, 3);
  Serial.println("Buzzer");   // Make sound after switching on


  // previousOnTime = millis(); 
}


void loop() {
  HeatOnI();  // Show heating light on
  Serial.println("Heat light on");
  HeatingOn();    // Start heating
  Serial.println("Heat on");
  OnTimer();    // Indicate that device is still on


  HeatStandbyI();   // Show heating light off
  Serial.println("Heat light off");
  HeatingOff();   // Stop heating
  Serial.println("Heat off");
  OnTimer();


  TempCheck();   // Check temperature

  PowerCheck();   // Check battery power

}
