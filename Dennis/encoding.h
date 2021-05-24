#include <Encoder.h>

// Encoder A
const int CLK_A = 30;
const int DT_A = 31; 
const int SW_A = 32;

// Encoder B
const int CLK_B = 32;
const int DT_B = 31; 
const int SW_B = 32;

// Encoder C
const int CLK_C = 32;
const int DT_C = 31; 
const int SW_C = 32;

// Encoder Class
Encoder EncoderA(DT_A,CLK_A);
//Encoder EncoderB(DT_B,CLK_B);
//Encoder EncoderC(DT_C,CLK_C);

// Var
long oldPosition  = -999;
int mod = 0;

int scan_Encode(){
    // Encode Scanner Funktion (Bitte Loopen)
    long newPosition = EncoderA.read();
  if (newPosition != oldPosition) {
    oldPosition = newPosition;
    mod = newPosition % 7;
    Serial.println(mod);
  }
  return mod;
}
