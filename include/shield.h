#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioInputI2S            i2s1;           //xy=70,282
AudioEffectFreeverb      freeverb1;      //xy=233,101
AudioEffectFreeverb      freeverb2;      //xy=255,439
//AudioFilterBiquad        biquad2;        //xy=435,363
//AudioFilterBiquad        biquad1;        //xy=463,144
AudioMixer4              mixer1;         //xy=614,283
AudioAnalyzeFFT1024      fft1024;      //xy=747,62
AudioOutputI2S           i2s2;           //xy=862,300
AudioConnection          patchCord1(i2s1, 0, freeverb1, 0);
AudioConnection          patchCord2(i2s1, 0, mixer1, 2);
AudioConnection          patchCord3(i2s1, 1, freeverb2, 0);
AudioConnection          patchCord4(i2s1, 1, mixer1, 3);
//AudioConnection          patchCord5(freeverb1, biquad1);
//AudioConnection          patchCord6(freeverb2, biquad2);
AudioConnection          patchCord7(freeverb1, 0, mixer1, 1);
AudioConnection          patchCord8(freeverb1, 0, mixer1, 0);
AudioConnection          patchCord9(mixer1, fft1024);
AudioConnection          patchCord10(mixer1, 0, i2s2, 0);
AudioConnection          patchCord11(mixer1, 0, i2s2, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=174,639
// GUItool: end automatically generated code
