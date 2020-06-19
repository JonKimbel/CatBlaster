# CatBlaster

I needed to keep my cat off the counter. How was I gonna do it? Machine learning.

[Planning doc](https://docs.google.com/document/d/1KNuEtG3Wgm6QG2y88D0SqNwudclRFZjXtyDJKQjURqY/edit)

## Project Status

*   V1 - MVP, reliable automatic cat sprayer w/ turret. **0% complete.**

## Construction

### Electronics

*   [OPTIONAL] Buy an Uno-compatible Arduino for testing the mechanism
*   Buy a [Google Coral Dev Board](https://coral.ai/products/dev-board) &
    [Camera](https://coral.ai/products/camera/)
*   Buy 3? [standard-size servos capable of rotating at least 180°](https://smile.amazon.com/gp/product/B07BVR816V/)
*   Buy a power supply capable of powering the servos (5V @ ~3A)

#### Wiring

TODO: figure out & document non-Arduino connections.

### Mechanism

*   3D print all of the non-"mock" objects in
    [this Onshape project](https://cad.onshape.com/documents/47c72d516ac62e140d6938a8/w/27975d840fed51e4dc37090b/e/f8ad727473f5e898687cdebd)
    *   TODO: add STL download link once complete
*   Buy [these spray bottles](https://smile.amazon.com/gp/product/B077GHR4B3)
*   TODO: document required bolts, inserts, etc.

TODO: pictures of where to put inserts, bolts, how things go together.

## Software

### Coral (ML cat detection)

#### Before you begin

TODO: document setup

#### Compiling

TODO: document compilation

#### Using

TODO: document

### Arduino (Optional mechanism verification)

#### Compiling & flashing

Ensure you have the Arduino wired up properly as described in
[arduino.ino](arduino/arduino.ino).

Open [arduino.ino](arduino/arduino.ino) in Arduino IDE. Click `Tools` -> `Board`
-> `Arduino Uno`. Connect the Uno to your computer via USB. Click `Sketch` ->
`Upload`.

See docs at top of [arduino.ino](arduino/arduino.ino) for usage.

#### Using

TODO: document
