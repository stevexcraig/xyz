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

int maxx = 200;

void setup() {
  // put your setup code here, to run once:
  pinMode(vertspeedPin, OUTPUT);
  pinMode(motor1, OUTPUT);
  pinMode(motor2, OUTPUT);
  pinMode(joyvertPin, INPUT);
  Serial.begin(9600);

  pinMode(horizspeedPin, OUTPUT);
  pinMode(motor3, OUTPUT);
  pinMode(motor4, OUTPUT);
  pinMode(joyhorizPin, INPUT);

  pinMode(circlespeedPin, OUTPUT);
  pinMode(motor5, OUTPUT);
  pinMode(motor6, OUTPUT);

  digitalWrite(circlespeedPin, HIGH);

  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  joyvertVal = analogRead(joyvertPin);

  //Serial.println(mSpeed);
  if (joyvertVal < 512) {
    digitalWrite(motor1, LOW);
    digitalWrite(motor2, HIGH);
    vertSpeed = map(joyvertVal, 512, 216, 0, maxx);
    //vertSpeed=(-255./512.)*joyvertVal+255.;
    analogWrite(vertspeedPin, vertSpeed);
  }
  if (joyvertVal >= 512) {
    digitalWrite(motor1, HIGH);
    digitalWrite(motor2, LOW);
    vertSpeed = map(joyvertVal, 512, 794, 0, maxx);
    //vertSpeed=(255./512.)*joyvertVal-255.;
    analogWrite(vertspeedPin, vertSpeed);
  }
  {
    joyhorizVal = analogRead(joyhorizPin);

    //Serial.println(mSpeed);
    if (joyhorizVal < 512) {
      digitalWrite(motor3, LOW);
      digitalWrite(motor4, HIGH);
      horizSpeed = map(joyhorizVal, 512, 216, 0, maxx);
      //horizSpeed=(-255./512.)*joyhorizVal+255.;
      analogWrite(horizspeedPin, horizSpeed);
    }
    if (joyhorizVal >= 512) {
      digitalWrite(motor3, HIGH);
      digitalWrite(motor4, LOW);
      horizSpeed = map(joyhorizVal, 512, 794, 0, maxx);
      //horizSpeed=(255./512.)*joyhorizVal-255.;
      analogWrite(horizspeedPin, horizSpeed);
    }
  }

  {
    digitalWrite(motor5, LOW);   // set leg 1 of the H-bridge low
    digitalWrite(motor6, HIGH);  // set leg 2 of the H-bridge high
    circleSpeed = analogRead(circlePot);
    circleSpeed = map(circleSpeed, 750, 230, 0, 255);
    analogWrite(circlespeedPin, circleSpeed);

 Serial.println(circleSpeed);
  }
}
