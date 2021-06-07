#include <Arduino.h>
#include "encoding.h"
#include "display.h"

int8_t mod;

void setup(){
    Serial.begin(96000);
    encoder_start();
    encoder_init(store[0], prevNextCode[0], CLK[0], DATA[0]);
    encoder_init(store[1], prevNextCode[1], CLK[1], DATA[1]);
    encoder_init(store[2], prevNextCode[2], CLK[2], DATA[2]);
    encoder_init(store[3], prevNextCode[3], CLK[3], DATA[3]);
}

void loop(){
    encoder_update();
   
}