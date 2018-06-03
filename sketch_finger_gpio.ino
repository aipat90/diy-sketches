#include <Wire.h>
#include <GpioExpander.h>
int i = 0;
int minSensor = 1000;
int maxSensor = 0;
int sensorNow = 0;
int fingerState = 0;
GpioExpander adio(42);
void setup() {
  // put your setup code here, to run once:
  Wire.begin();
  Serial.begin(115200);
  Serial.println("Calibration Begin");
  for (i=0; i<300; i++){
    sensorNow = adio.analogRead(0);
    if (sensorNow > maxSensor){
      maxSensor = sensorNow;
    }
    if (sensorNow < minSensor){
      minSensor = sensorNow;
    }
    delay(10);
  }
  Serial.println("Calibration Finished");
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorNow = adio.analogRead(0);
  fingerState = map(sensorNow, minSensor, maxSensor, 0, 3);
  Serial.print(" finger = ");
  Serial.println(fingerState);
  delay(20);
}
