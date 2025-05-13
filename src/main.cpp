#include <Arduino.h>
#include "land_mode.h"
#include "drone_mode.h"
int in1=13;
int in2=12;
int in3=11;
int in4=10;
int enA=1;
int enB=2;
int mode = 0;

void setup() {
  Serial.begin(9600);
  pinMode(enA, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
}

void loop() {
  // your main loop
  digitalWrite(in1, HIGH);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, HIGH);
  digitalWrite(enA, 255);
  digitalWrite(enB, 255);
  delay(1000);
}
