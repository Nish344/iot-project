#include <Servo.h>

Servo radarServo;

// Pin definitions
const int TRIG = 9;
const int ECHO = 10;
const int SERVO_PIN = 6;

// Radar settings
const int MIN_ANGLE = 0;
const int MAX_ANGLE = 180;
const int STEP = 1;        // Move servo 1 degree per step
const int MIN_DISTANCE = 10; // cm – below this, send -1
const int MAX_DISTANCE = 400; // HC-SR04 limit

void setup() {
  Serial.begin(9600);

  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  radarServo.attach(SERVO_PIN);
  radarServo.write(MIN_ANGLE);
  delay(500);
}

long measureDistance() {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  long duration = pulseIn(ECHO, HIGH, 25000); // 25 ms timeout → about 400 cm

  if (duration == 0) {
    return -1;
  }

  long distance = duration * 0.034 / 2;

  if (distance < MIN_DISTANCE || distance > MAX_DISTANCE) {
    return -1;
  }

  return distance;
}

void loop() {
  
  // Sweep forward
  for (int angle = MIN_ANGLE; angle <= MAX_ANGLE; angle += STEP) {
    radarServo.write(angle);
    delay(15);  // allow servo movement

    long distance = measureDistance();

    Serial.print(angle);
    Serial.print(",");
    Serial.println(distance);
  }

  // Sweep backward
  for (int angle = MAX_ANGLE; angle >= MIN_ANGLE; angle -= STEP) {
    radarServo.write(angle);
    delay(15);

    long distance = measureDistance();

    Serial.print(angle);
    Serial.print(",");
    Serial.println(distance);
  }
}
