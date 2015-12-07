/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>

Servo myservo1;  // create servo object to control a servo
Servo myservo2;                // twelve servo objects can be created on most boards
Servo myservo3;
int servo1Ang = 90;    // variable to store the servo position
int servo2Ang = 90;
int servo3Ang = 90;

void setup()
{
  Serial.begin(9600);

  myservo1.attach(2);  // attaches the servo on pin 9 to the servo object
  myservo2.attach(3);  // attaches the servo on pin 9 to the servo object
  myservo3.attach(4);  // attaches the servo on pin 9 to the servo object
}

void loop()
{
  readData2();
  adjustMotors();
}

void readData() {
  if (Serial.available()) {
    char inChar[20];
    char* prs;
    int i = 0;
    while (Serial.available()) {
      delay(5);
      inChar[i] = Serial.read();
//      if(inChar[i] == 0 && Serial.available()>0)
//        i = 0;
      if (isdigit(!(inChar[i]) || inChar[i] == ' '))
        return;
        
      i++;
    }
    inChar[i] = 0;
    servo1Ang = atoi(strtok(inChar, " "));
    servo2Ang = atoi(strtok(NULL, " "));
    servo3Ang = atoi(strtok(NULL, " "));
    SendMotorsNewAngles();
  }

}
void readData2(){
  while(Serial.available()){
    Serial.read();
  }
}

void adjustMotors() {
  //  myservo1.write(getNewAngle(myservo1.read(), servo1Ang));
  //  myservo2.write(getNewAngle(myservo2.read(), servo2Ang));
  //  myservo3.write(getNewAngle(myservo3.read(), servo3Ang));
  myservo1.write( servo1Ang);
  myservo2.write( servo2Ang);
  myservo3.write(servo3Ang);
}

int getNewAngle(int oldAng, int newAng) {
  if (oldAng == newAng) {
    return oldAng;
  }
  else if (oldAng > newAng) {
    return oldAng - 1;
  }
  else {
    return oldAng + 1;
  }
}

void SendMotorsNewAngles() {

  Serial.println("Servor1: ");
  Serial.println(servo1Ang);

  Serial.println("Servor2: ");
  Serial.println(servo2Ang);

  Serial.println("Servor3: ");
  Serial.println(servo3Ang);
}

