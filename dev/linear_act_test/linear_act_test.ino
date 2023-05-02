// opening the hand (linear shrink), and closing it (linear elongated)
// Define Pins
// Motor A
 int enableA = 5;
 int pinA1 = 6;
 int pinA2 = 7;

void setup()   {
  Serial.begin (9600);
  // configure pin modes
  pinMode (enableA, OUTPUT);
  pinMode (pinA1, OUTPUT);
  pinMode (pinA2, OUTPUT);

  // close the hand A
  Serial.println ("Close the hand A");
  digitalWrite (enableA, HIGH);
  digitalWrite (pinA1,LOW);
  digitalWrite (pinA2,HIGH);
  delay(10);
  digitalWrite (enableA, LOW);
  delay (5000);
  
  //open the hand A
  Serial.println ("Open the hand A");
  digitalWrite (enableA, HIGH);
  digitalWrite (pinA1, HIGH);
  digitalWrite (pinA2, LOW);
  digitalWrite (enableA, LOW);
  delay (5000);
}

void loop() {

}
