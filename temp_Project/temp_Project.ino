#include <TimerOne.h>

const int ledPin = 13;
const int fanPin = 9;
const int startPin = 2;
unsigned long blinkSpeed = 100;
int fanSpeed = 255;
String inputString = "";
bool startGame = false;
void setup() {
  //Intialize serial
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(fanPin, OUTPUT);
  pinMode(startPin, OUTPUT);
  digitalWrite(2, HIGH);

  attachInterrupt(0, startGameButtonClicked, FALLING);
}

void loop() {
  serialFan();

  //blink();
}
//
//void blink() {
//  digitalWrite(ledPin, HIGH);   // turn the LED on (HIGH is the voltage level)
//  delay(blinkSpeed);              // wait for a second
//  digitalWrite(ledPin, LOW);    // turn the LED off by making the voltage LOW
//  delay(blinkSpeed);
//}

void serialFan() {
  char inChar = 0;
  if (Serial.available() ) {
    while (Serial.available() > 0) {
      inChar = (char)Serial.read();
    }
    blinkSpeed = inChar * 10;
    fanSpeed = (inChar - '0') * 28.3;
    analogWrite(fanPin, fanSpeed);
    Serial.println(fanSpeed);
  }

}

void startGameButtonClicked() {
  Serial.println("Start");
}

