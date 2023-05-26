// Gripper control test
const int ENA = 39;
const int IN1 = 41;
const int IN2 = 43;

void setup() {
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(ENA, HIGH);

  Serial.begin(9600);
}

void loop() {
  //set initial rotation direction
  Serial.println("Init gripper");
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  delay(500);

  Serial.println("Gripper reverse");
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  delay(500);
}
