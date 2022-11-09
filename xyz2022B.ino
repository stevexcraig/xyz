int vertspeedPin = 3;
int motor1 = 4;
int motor2 = 5;
int vertSpeed;
int joyvertPin = A0;
int joyvertVal;

int horizspeedPin = 9;
int motor3 = 7;
int motor4 = 8;
int horizSpeed;
int joyhorizPin = A1;
int joyhorizVal;

int circlespeedPin = 10;
int motor5 = 11;
int motor6 = 12;
int circleSpeed;
int circlePot = A2;

int maxx = 215;

void setup() {
 
  pinMode(vertspeedPin, OUTPUT);
  pinMode(motor1, OUTPUT);
  pinMode(motor2, OUTPUT);
  pinMode(joyvertPin, INPUT);


  pinMode(horizspeedPin, OUTPUT);
  pinMode(motor3, OUTPUT);
  pinMode(motor4, OUTPUT);
  pinMode(joyhorizPin, INPUT);

  pinMode(circlespeedPin, OUTPUT);
  pinMode(motor5, OUTPUT);
  pinMode(motor6, OUTPUT);

  digitalWrite(vertspeedPin, HIGH);
  digitalWrite(horizspeedPin, HIGH);
  digitalWrite(circlespeedPin, HIGH);

  Serial.begin(9600);

}

void loop() {

  joyvertVal = analogRead(joyvertPin);

  if (joyvertVal < 490) {
    digitalWrite(motor1, LOW);
    digitalWrite(motor2, HIGH);
    vertSpeed = map(joyvertVal, 500, 210, 0, maxx);
    analogWrite(vertspeedPin, vertSpeed);
  }
  if (joyvertVal >= 510) {
    digitalWrite(motor1, HIGH);
    digitalWrite(motor2, LOW);
    vertSpeed = map(joyvertVal, 500, 794, 0, maxx);
    analogWrite(vertspeedPin, vertSpeed);
  }
  else if ((joyvertVal > 490) && (joyvertVal < 510)) {
    digitalWrite(motor1, LOW);
    digitalWrite(motor2, LOW);
  }

    joyhorizVal = analogRead(joyhorizPin);

    if (joyhorizVal < 490) {
      digitalWrite(motor3, LOW);
      digitalWrite(motor4, HIGH);
      horizSpeed = map(joyhorizVal, 500, 220, 0, maxx);
      analogWrite(horizspeedPin, horizSpeed);
    }
    if (joyhorizVal >= 510) {
      digitalWrite(motor3, HIGH);
      digitalWrite(motor4, LOW);
      horizSpeed = map(joyhorizVal, 500, 794, 0, maxx);
      analogWrite(horizspeedPin, horizSpeed);
    }
  

  {
    digitalWrite(motor5, LOW);   // set leg 1 of the H-bridge low
    digitalWrite(motor6, HIGH);  // set leg 2 of the H-bridge high
    circleSpeed = analogRead(circlePot);
    circleSpeed = map(circleSpeed, 1023, 0, 0, 180);
    analogWrite(circlespeedPin, circleSpeed);

  }

Serial.print(joyvertVal);
Serial.print("\t");

Serial.print(joyhorizVal);
Serial.print("\t");

Serial.print(circleSpeed);
Serial.println("\t");
//Serial.println();
//delay(250);
}
