const int sensorPin = A0;
int value;
int smax=0;
int smin=1024;

void calibrate(){
  Serial.print(" start calibrate ... ");
  Serial.print(" readeding max ");
  smax=analogRead(sensorPin);
  delay(3000);
  Serial.print(" reading min ");
  smin=analogRead(sensorPin);
}

void setup() {
  // put your setup code here, to run once:
  pinMode(9, INPUT);
  Serial.begin(115200); 
}

void loop() {
  value = analogRead(sensorPin);
  Serial.print(" sensor value ");
  Serial.println(value);
  // put your main code here, to run repeatedly:
  delay(600);
}
