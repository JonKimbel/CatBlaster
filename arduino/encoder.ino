// Usage:
// Put this in the same directory as the code using it, then just call the
// methods directly.

// Encoder variables.
int encoderClkPin = 3;  // Connected to CLK on KY-040
int encoderDtPin = 2;  // Connected to DT on KY-040
int encoderClkPinLast;
boolean skipNext = false;

void setUpEncoder(int _encoderClkPin, int _encoderDtPin) {
  encoderClkPin = _encoderClkPin;
  encoderDtPin = _encoderDtPin;
  // Encoder setup.
  pinMode(encoderClkPin,INPUT);
  pinMode(encoderDtPin,INPUT);
  // Read initial encoder state.
  encoderClkPinLast = digitalRead(encoderClkPin);
}

// There's an issue with this, it occasionally reads CCW rotation as CW.
int readEncoder() {
  int aVal = digitalRead(encoderClkPin);
  if (aVal != encoderClkPinLast) {
    // The knob is rotating.
    encoderClkPinLast = aVal;

    // For some reason the encoder counts twice per step? Get rid of that.
    if (skipNext) {
      skipNext = false;
      return 0;
    }
    skipNext = true;

    if (digitalRead(encoderDtPin) != aVal) {
      // We're rotating CCW.
      return -1;
    } else {
      // CW.
      return 1;
    }
  }

  return 0;
}
