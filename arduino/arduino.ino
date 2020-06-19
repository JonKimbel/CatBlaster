// Simple test code that will just run a servo based on the movement of an
// attached encoder.
//
// Twisting the encoder will rotate all servos back and forth.
// Clicking the encoder will reset all servos to 90 degrees.

#include <Servo.h>

// Connections.

const int SPRAY_SERVO_PWM_PIN = 3;
const int ENCODER_CLK_PIN = 6;
const int ENCODER_DT_PIN = 7;
const int ENCODER_SW_PIN = 8;

// In addition to these, be sure to connect:
//
//  - Servo, Arduino, and Encoder ground to shared ground
//  - Encoder 5V to Arduino 5V
//  - 5V power supply to servo 5V lines (not shared with Arduino/Encoder)

// Global vars.

Servo sprayServo;
int servoPosition = 90;

void setup() {
  setUpEncoder(ENCODER_CLK_PIN, ENCODER_DT_PIN);
  pinMode(ENCODER_SW_PIN, INPUT);

  sprayServo.attach(SPRAY_SERVO_PWM_PIN);

  writeDegreeToAllServos(servoPosition);

  delay (1250);
}

void loop() {
  servoPosition += readEncoder();

  if (servoPosition < 2) {
    servoPosition = 2;
  } else if (servoPosition > 180) {
    servoPosition = 180;
  }
  if (!digitalRead(ENCODER_SW_PIN)) {
    servoPosition = 90;
  }

  writeDegreeToAllServos(servoPosition);
}

void writeDegreeToAllServos(int servoPosition) {
  sprayServo.write(servoPosition);
}
