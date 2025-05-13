#include "land_mode.h"
#include <Arduino.h>
#include <AFMotor.h>

int in1 = 2;
int in2 = 4;
int enA = 3;
int in3 = 5;
int in4 = 7;
int enB = 5;
int sA = 255;
int sB = 200;

void LandMode(char command) {
  switch (command)
  {
  case 'W':
    Maju(sA, sB);
  case 'S':
    Belakang();
  case 'A':
    Kiri();
  case 'D':
    Kanan();
  

  }
}

void Maju(int sA, int sB){
digitalWrite(in1, HIGH);
digitalWrite(in2, LOW);
digitalWrite(in3, LOW);
digitalWrite(in4, HIGH);
digitalRead(enA, sA);
digitalRead(enB, sB);
}

void Kiri(){
digitalWrite(in1, LOW);
digitalWrite(in2, HIGH);
digitalWrite(in3, HIGH);
digitalWrite(in4, HIGH);
digitalRead(enA, sA);
digitalRead(enB, sB);
}

void Belakang(){
digitalWrite(in1, LOW);
digitalWrite(in1, LOW);
digitalWrite(in1, LOW);
digitalWrite(in1, LOW);
digitalRead(enA, sA);
digitalRead(enB, sB);
}

void Kanan(){
digitalWrite(in1, HIGH);
digitalWrite(in1, LOW);
digitalWrite(in1, LOW);
digitalWrite(in1, LOW);
digitalRead(enA, sA);
digitalRead(enB, sB);
}