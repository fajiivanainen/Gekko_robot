
// Function for going forward and backward

void forward(int steps){
  
  digitalWrite(magnet1,LOW);
  digitalWrite(magnet4,LOW);
  digitalWrite(magnet2,HIGH);
  digitalWrite(magnet3,HIGH);
  digitalWrite(turningMagnet,LOW);

  const int maxpos = 60;  // variable to clarify how much the servo turns
  int stepsTaken = 0;   // variable to store the steps taken
  
  for(stepsTaken = 0; stepsTaken <= steps; stepsTaken += 1){  
    int pos = 0;    // variable to store the servo position
    for (pos = 0; pos <= maxpos; pos += 1) { // goes from 0 degrees to maxpos
      // in steps of 1 degree
      myservo1.write(pos);              // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15 ms for the servo to reach the position
    }

    delay(1000);
    digitalWrite(magnet1,HIGH);       // turns on magnet1
    digitalWrite(magnet4,HIGH);
    delay(1000);
    digitalWrite(magnet2,LOW);
    digitalWrite(magnet3,LOW);

    for (pos = maxpos; pos >= 0; pos -= 1) { // goes from maxpos degrees to 0 degrees
      myservo1.write(pos);              // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 10 ms for the servo to reach the position
    }

    delay(1000);
    digitalWrite(magnet2,HIGH);
    digitalWrite(magnet3,HIGH);
    delay(1000);
    digitalWrite(magnet1,LOW);
    digitalWrite(magnet4,LOW);
  }
}

 // Function for turning

void turn(int degrees){
  int angle = 0;

  digitalWrite(turningMagnet,HIGH);
  delay(1000);
  digitalWrite(magnet2,LOW);
  digitalWrite(magnet3,LOW);
  digitalWrite(magnet1,LOW);
  digitalWrite(magnet4,LOW);

  for(angle = 0; angle <= degrees; angle += 1){
    myservo2.write(angle);
    delay(15);
  }         // turns the vehicle

  digitalWrite(magnet2,HIGH);
  digitalWrite(magnet3,HIGH);
  digitalWrite(magnet1,HIGH);
  digitalWrite(magnet4,HIGH);
  delay(1000);
  digitalWrite(turningMagnet,LOW);

  for(angle = degrees; angle >= 0; angle -= 1){
    myservo2.write(angle);
    delay(15);
  }         // turns the turning magnet back to its original position


}