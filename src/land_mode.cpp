#include "land_mode.h"
#include <Arduino.h>

int in1 = 13;
int in2 = 12;
int in3 = 11;
int in4 = 10;
int enA = 9;
int enB = 8;
int SpeedSlowA = 80;
int SpeedSlowB = 80;
int SpeedMediumA = 128;
int SpeedMediumB = 128;
int SpeedFastA = 255;
int SpeedFastB = 255;

void LandMode(char command, char speed) {
    switch (command){
    case 'W':
        if (speed == 'S') forward(SpeedSlowA, SpeedSlowB);
        else if (speed == 'M') forward(SpeedMediumA, SpeedMediumB);
        else if (speed == 'F') forward(SpeedFastA, SpeedFastB);
        break;

    case 'A':
        if (speed == 'S') left(SpeedSlowA, SpeedSlowB);
        else if (speed == 'M') left(SpeedMediumA, SpeedMediumB);
        else if (speed == 'F') left(SpeedFastA, SpeedFastB);
        break;

    case 'S':
        if (speed == 'S') backward(SpeedSlowA, SpeedSlowB);
        else if (speed == 'M') backward(SpeedMediumA, SpeedMediumB);
        else if (speed == 'F') backward(SpeedFastA, SpeedFastB);
        break;

    case 'D':
        if (speed == 'S') right(SpeedSlowA, SpeedSlowB);
        else if (speed == 'M') right(SpeedMediumA, SpeedMediumB);
        else if (speed == 'F') right(SpeedFastA, SpeedFastB);
        break;
  }
}

static void forward(int speed1, int speed2){
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    analogWrite(enA, speed1);
    analogWrite(enB, speed2);
}

static void left(int speed1, int speed2){
    digitalWrite(in1, HIGH);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    analogWrite(enA, speed1);
    analogWrite(enB, speed2);
}
static void right(int speed1, int speed2){
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, HIGH);
    analogWrite(enA, speed1);
    analogWrite(enB, speed2);
}
static void backward(int speed1, int speed2){
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    analogWrite(enA, speed1);
    analogWrite(enB, speed2);
}
