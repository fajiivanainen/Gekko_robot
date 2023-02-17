
// Include the servo in the system

#include <Servo.h>

Servo myservo1;  // create servo object to control a servo
Servo myservo2;

const int magnet1 = 8;
const int magnet2 = 7;
const int magnet3 = 6;
const int magnet4 = 5;

const int turningMagnet = 4;

void setup() {
  myservo1.attach(9);  // attaches the servo on pin 9 to the servo object
  myservo2.attach(10);
  pinMode(magnet1,OUTPUT);
  pinMode(magnet2,OUTPUT);
  pinMode(magnet3,OUTPUT);
  pinMode(magnet4,OUTPUT);
  pinMode(turningMagnet,OUTPUT);
}

void loop() {
  digitalWrite(magnet1,HIGH);
  digitalWrite(magnet4,HIGH);
  digitalWrite(magnet2,HIGH);
  digitalWrite(magnet3,HIGH);
  digitalWrite(turningMagnet,LOW);
  forward(5);
  turn(90);
  forward(5);
  turn(90);
  forward(5);
  turn(90);
  forward(5);
  turn(90);
}
