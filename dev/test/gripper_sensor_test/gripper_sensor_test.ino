#define sensorPinRR A0
#define sensorPinRL A1 
#define sensorPinLR A2
#define sensorPinLL A3

void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensorReading = analogRead(sensorPinRR);
  Serial.println(sensorReading);
  delay(50);
}
