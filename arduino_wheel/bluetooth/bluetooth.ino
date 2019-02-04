#include<SoftwareSerial.h>

#define TxD 3
#define RxD 2
#define LED_PIN 8

const int leftBehindForward = 8;
const int leftBehindBackward = 9;
const int rightBehindForward = 6;
const int rightBehindBackward = 7;
const int leftFrontForward = 10;
const int leftFrontBackward = 11;
const int rightFrontForward = 5;
const int rightFrontBackward = 4;

SoftwareSerial bluetoothSerial(TxD, RxD);

char c;

void setup() {
  bluetoothSerial.begin(9600);
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  }

void loop() {
  char dat = check();
  if(dat == 'F') {
    digitalWrite(leftBehindForward, HIGH);
    digitalWrite(leftBehindBackward, LOW);
    digitalWrite(rightBehindForward, HIGH);
    digitalWrite(rightBehindBackward, LOW);
  }
  else if(dat == 'B') {
    digitalWrite(leftBehindForward, LOW);
    digitalWrite(leftBehindBackward, HIGH);
    digitalWrite(rightBehindForward, LOW);
    digitalWrite(rightBehindBackward, HIGH);
  }
  else if(dat == 'R') {
    digitalWrite(leftBehindForward, HIGH);
    digitalWrite(leftBehindBackward, LOW);
  }
  else if(dat == 'L') {
     digitalWrite(rightBehindForward, HIGH);
    digitalWrite(rightBehindBackward, LOW);
  }
  else {
    digitalWrite(leftBehindForward, LOW);
    digitalWrite(leftBehindBackward, LOW);
    digitalWrite(rightBehindForward, LOW);
    digitalWrite(rightBehindBackward, LOW);
  }
}

int check() {
  if(bluetoothSerial.available()){
    c = bluetoothSerial.read();
    return c;
  }
}

