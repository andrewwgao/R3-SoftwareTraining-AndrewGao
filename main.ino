/*
Andrew Gao
R3 Software Training
*/

// Motor 1
const int MotorPin1 = 5;
const int MotorPin2 = 6;
// Motor 2
const int MotorPin3 = 10;
const int MotorPin4 = 9;
// Potentiometer
int Potpin = A0;
int speed;
// Dip switch
const int S1 = 7;
const int S2 = 2;
const int S3 = 3;
const int S4 = 4;
// State of each switch
bool s1state;
bool s2state;
bool s3state;
bool s4state;

void setup() {
  // Set motor pins to output
  pinMode(MotorPin1, OUTPUT);
  pinMode(MotorPin2, OUTPUT);
  pinMode(MotorPin3, OUTPUT);
  pinMode(MotorPin4, OUTPUT);
}

void loop() {
  // read the state of each switch
  s1state = digitalRead(S1);
  s2state = digitalRead(S2);
  s3state = digitalRead(S3);
  s4state = digitalRead(S4);
  
  if (s1state == true && s2state == false && s3state == false && s4state == false){ // 1 is on
    // forward
    analogWrite(MotorPin1, speed);
    analogWrite(MotorPin2, LOW);
    analogWrite(MotorPin3, LOW);
    analogWrite(MotorPin4, speed);
  }
  else if (s1state == false && s2state == true && s3state == false && s4state == false){ // 2 is on
    // backwards
    analogWrite(MotorPin1, LOW);
    analogWrite(MotorPin2, speed);
    analogWrite(MotorPin3, speed);
    analogWrite(MotorPin4, LOW);
  }
  else if (s1state == false && s2state == false && s3state == true && s4state == false){ // 3 is on
    // right
    analogWrite(MotorPin1, LOW);
    analogWrite(MotorPin2, speed);
    analogWrite(MotorPin3, LOW);
    analogWrite(MotorPin4, speed);
  }
  else if (s1state == false && s2state == false && s3state == false && s4state == true){ // 4 is on
    // left
    analogWrite(MotorPin1, speed);
    analogWrite(MotorPin2, LOW);
    analogWrite(MotorPin3, speed);
    analogWrite(MotorPin4, LOW);
  }
  else { // any other combination of switches
  	analogWrite(MotorPin1, LOW);
    analogWrite(MotorPin2, LOW);
    analogWrite(MotorPin3, LOW);
    analogWrite(MotorPin4, LOW);
  }
  
  speed = analogRead(Potpin); // Potentiometer reading
  speed = map(speed, 0, 1023, 0, 255); // Potentiometer value range

}