// Line Following Robot Code using Arduino Uno
// IR sensors connected to digital pins
// Motor Driver (L298N or similar) connected to Arduino

// Pin Definitions
const int leftSensor = 2;     // Left IR sensor
const int rightSensor = 3;    // Right IR sensor

const int ENA = 9;            // Enable pin for left motor
const int IN1 = 8;
const int IN2 = 7;

const int ENB = 10;           // Enable pin for right motor
const int IN3 = 6;
const int IN4 = 5;

void setup() {
  // Sensor pins
  pinMode(leftSensor, INPUT);
  pinMode(rightSensor, INPUT);

  // Motor pins
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // Start motors stopped
  stopMotors();
}

void loop() {
  int leftValue = digitalRead(leftSensor);
  int rightValue = digitalRead(rightSensor);

  if (leftValue == LOW && rightValue == LOW) {
    // Both sensors on black line: move forward
    moveForward();
  } else if (leftValue == LOW && rightValue == HIGH) {
    // Left sensor on line, right on white: turn left
    turnLeft();
  } else if (leftValue == HIGH && rightValue == LOW) {
    // Right sensor on line, left on white: turn right
    turnRight();
  } else {
    // Both on white: stop
    stopMotors();
  }
}

void moveForward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 150);
  analogWrite(ENB, 150);
}

void turnLeft() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 120);
  analogWrite(ENB, 120);
}

void turnRight() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, 120);
  analogWrite(ENB, 120);
}

void stopMotors() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}