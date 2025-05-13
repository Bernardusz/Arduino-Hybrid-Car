#include <Arduino.h>
#include "land_mode.h"
#include "drone_mode.h"

char input;
int mode = 0; //0 = Land 1 = Aerial

void setup() {
  Serial.begin(9600);
}

void loop() {
  // your main loop
  if (Serial.available()){
    input = Serial.read();

    if (input == 'L') mode = 0;
    else if (input == 'A') mode = 1;
  }
  if (mode == 0){
    LandMode(input);}

  else if (mode == 1)
  {
    DroneMode(input);}
  

}  
