#include <Arduino.h>
// Robust Rotary encoder reading
//
// Copyright John Main - best-microcontroller-projects.com
//
// Git Sync Test
#define CLK 30
#define DATA 31

void setup() {
  pinMode(CLK, INPUT);
  pinMode(CLK, INPUT_PULLUP);
  pinMode(DATA, INPUT);
  pinMode(DATA, INPUT_PULLUP);
  Serial.begin (115200);
  Serial.println("KY-040 Start:");
}

static uint8_t prevNextCode = 0;
static uint16_t store=0;

// A vald CW or  CCW move returns 1, invalid returns 0.
int8_t read_rotary() {
  static int8_t rot_enc_table[] = {0,1,1,0,1,0,0,1,1,0,0,1,0,1,1,0};

  prevNextCode <<= 2;
  if (digitalRead(DATA)) prevNextCode |= 0x02;
  if (digitalRead(CLK)) prevNextCode |= 0x01;
  prevNextCode &= 0x0f;

   // If valid then store as 16 bit data.
   if  (rot_enc_table[prevNextCode] ) {
      store <<= 4;
      store |= prevNextCode;
      //if (store==0xd42b) return 1;
      //if (store==0xe817) return -1;
      if ((store&0xff)==0x2b) return -1;
      if ((store&0xff)==0x17) return 1;
   }
   return 0;
}

void loop() {
static int8_t c,val;

   if( val=read_rotary() ) {
      c +=val;
      Serial.print(c);Serial.print(" ");
   }
}

