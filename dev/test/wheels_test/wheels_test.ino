// controlling wheels

const int PWML = A5;
const int PWMR = A4;
const int DIRL = 5;
const int DIRR = 3;
const int BRKL = 6;
const int BRKR = 4;

void backward(){
    digitalWrite(BRKL, LOW);
    digitalWrite(BRKR, LOW);
    digitalWrite(DIRL, LOW);
    digitalWrite(DIRR, HIGH);
    analogWrite(PWML, 12); // max 255
    analogWrite(PWMR, 12);
    Serial.println(analogRead(PWML));
    Serial.println("both wheels forward");
}

void forward(){
    digitalWrite(BRKL, LOW);
    digitalWrite(BRKR, LOW);
    digitalWrite(DIRL, HIGH);
    digitalWrite(DIRR, LOW);
    analogWrite(PWML, 12);
    analogWrite(PWMR, 12);
    Serial.println("both wheels backward");
}

void right(){
  //right
    digitalWrite(BRKL, LOW);
    digitalWrite(BRKR, LOW);
    digitalWrite(DIRL, HIGH);
    digitalWrite(DIRR, HIGH);
    analogWrite(PWML, 12);
    analogWrite(PWMR, 12);
    Serial.println("wheels right");
}

void left(){
    digitalWrite(BRKL, LOW);
    digitalWrite(BRKR, LOW);
    digitalWrite(DIRL, LOW);
    digitalWrite(DIRR, LOW);
    analogWrite(PWML, 12);
    analogWrite(PWMR, 12);
    Serial.println("wheels left");
}

void brake(){
    // stop
    analogWrite(PWML, 0);
    analogWrite(PWMR, 0);
    digitalWrite(BRKL, HIGH);
    digitalWrite(BRKR, HIGH);
    Serial.println("wheels stop");
}

void setup() {
    pinMode(PWML, OUTPUT);
    pinMode(PWMR, OUTPUT);
    pinMode(DIRL, OUTPUT);
    pinMode(DIRR, OUTPUT);
    pinMode(BRKL, OUTPUT);
    pinMode(BRKR, OUTPUT);

    Serial.begin(9600);

    forward();
    delay(2000);
    brake();
    delay(1000);
    backward();
    delay(2000);
    brake();
    delay(1000);
    right();
    delay(1500);
    brake();
    delay(1000);
    left();
    delay(1500);
    brake();
    delay(1000);
}

void loop() {}
