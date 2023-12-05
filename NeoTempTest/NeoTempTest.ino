#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 10


OneWire oneWire(ONE_WIRE_BUS);

DallasTemperature sensors(&oneWire);


int BUZZER = 3;

int SWITCH = 7;
int TEMP = A0;
int COIL = 8;

int highTemp = 29;
int temp = 0;

// #300000
int tempTimeThreshold = 3000;
int currentTempOnTime = 0;
int previousTempOnTime = 0;


void CheckTemp() {
  if ((currentTempOnTime - previousTempOnTime) >= tempTimeThreshold) {
    float temp = sensors.getTempCByIndex(0);
    Serial.println(temp);

    if (temp > highTemp) {
      digitalWrite(COIL, LOW);
      delay(2000);

      for (int i = 0; i <3; i++) {
        tone(BUZZER, 500, 1000);
        noTone(BUZZER);
        delay(1000);
      }
    }

    previousTempOnTime = currentTempOnTime;
  }

}

void setup() {
  // put your setup code here, to run once:
  pinMode(BUZZER, OUTPUT);

  Serial.begin(115200);

  sensors.requestTemperatures();

}

void loop() {
  // put your main code here, to run repeatedly:
  CheckTemp();
}
