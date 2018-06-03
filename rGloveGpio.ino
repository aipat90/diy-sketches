#include <Wire.h>
#include <GpioExpander.h>
#include <TroykaIMU.h>
#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"

float datapack[10];

RF24 radio(9,10);
int channelNumber = 5;
int i = 0;
int fingers[3];
GpioExpander adio(42);
Gyroscope gyro;
Accelerometer accel;

void setup() {
  Wire.begin();
  gyro.begin();
  accel.begin();
  radio.begin();
  radio.setAutoAck(false);
  radio.setChannel(channelNumber);
  delay(150);
}

void loop() {
  //sensorNow = adio.analogRead(0);
  datapack[0] = adio.analogRead(0);
  datapack[1] = adio.analogRead(1);
  datapack[2] = adio.analogRead(2);
  datapack[3] = adio.analogRead(3);
  datapack[4] = gyro.readDegPerSecX();
  datapack[5] = gyro.readDegPerSecY();
  datapack[6] = gyro.readDegPerSecZ();
  datapack[7] = accel.readAX();
  datapack[8] = accel.readAY();
  datapack[9] = accel.readAZ();
  radio.write(&datapack, sizeof(datapack));
}
