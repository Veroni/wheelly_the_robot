// Controlling elbow

const int ENA = 30;
const int IN1 = 28;
const int IN2 = 26;

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
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  delay(2200);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  delay(2200);

}
