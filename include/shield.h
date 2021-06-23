#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioPlayMemory          playMem1;       //xy=81,353
AudioEffectFreeverb      freeverb1;      //xy=373,430
AudioEffectBitcrusher    bitcrusher1;    //xy=387,333
AudioMixer4              mixer1;         //xy=558,236
AudioOutputI2S           i2s1;           //xy=765,379
AudioConnection          patchCord1(playMem1, 0, mixer1, 0);
AudioConnection          patchCord2(playMem1, bitcrusher1);
AudioConnection          patchCord3(playMem1, freeverb1);
AudioConnection          patchCord4(freeverb1, 0, mixer1, 2);
AudioConnection          patchCord5(bitcrusher1, 0, mixer1, 1);
AudioConnection          patchCord6(mixer1, 0, i2s1, 0);
AudioConnection          patchCord7(mixer1, 0, i2s1, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=174,639
// GUItool: end automatically generated code
