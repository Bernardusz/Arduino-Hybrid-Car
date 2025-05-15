#include "drone_mode.h"
#include <Arduino.h>

const int motorPins[6] = {3, 5, 6, 9, 10, 11}; // Sesuaikan dengan pin PWM (kyk e bener tbh idk)
int motorSpeed = 0;
const int maxSpeed = 200;
const int minSpeed = 60;

void initMotors() {
    for (int i = 0; i < 6; i++) {
        pinMode(motorPins[i], OUTPUT);
        analogWrite(motorPins[i], 0);
    }
}

void setAllMotors(int speed) {
    for (int i = 0; i < 6; i++) {
        analogWrite(motorPins[i], speed);
    }
}

void takeOff() {
    motorSpeed = minSpeed;
    setAllMotors(motorSpeed);
}

void land() {
    for (int i = motorSpeed; i >= 0; i -= 5) {
        setAllMotors(i);
        delay(100);
    }
    motorSpeed = 0;
    setAllMotors(0);
}

void increaseAltitude() {
    if (motorSpeed < maxSpeed) {
        motorSpeed += 10;
        setAllMotors(motorSpeed);
    }
}

void decreaseAltitude() {
    if (motorSpeed > minSpeed) {
        motorSpeed -= 10;
        setAllMotors(motorSpeed);
    }
}

void DroneMode(char command, char speed) {
    switch (command) {
        case 'T': initMotors(); takeOff(); break;
        case 'L': land(); break;
        case 'U': increaseAltitude(); break;
        case 'D': decreaseAltitude(); break;
        default: break;
    }
}
//kayaknya sih ya aku gatau lagi moga bener gais
