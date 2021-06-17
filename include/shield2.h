#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioInputI2S            i2s1;           //xy=141,182
AudioEffectDelay         delay1;         //xy=433,315
AudioEffectWaveshaper    waveshape2;     //xy=434,158
AudioEffectFreeverb      freeverb1;      //xy=435,195
AudioEffectWaveshaper    waveshape1;     //xy=436,121
AudioEffectDelay         delay2;         //xy=435,441
AudioEffectFreeverb      freeverb2;      //xy=436,231
AudioEffectChorus        chorus1;        //xy=437,27
AudioFilterStateVariable filter1;        //xy=435,529
AudioEffectChorus        chorus2;        //xy=437.25,58.75
AudioMixer4              mixer1;         //xy=699,59
AudioMixer4              mixer2;         //xy=700,124
AudioMixer4              mixer3;         //xy=705,282
AudioMixer4              mixer4;         //xy=706,345
AudioMixer4              mixer5;         //xy=918,166
AudioMixer4              mixer6;         //xy=918,232
AudioOutputI2S           i2s2;           //xy=1162,198
AudioConnection          patchCord1(i2s1, 0, chorus1, 0);
AudioConnection          patchCord2(i2s1, 0, waveshape1, 0);
AudioConnection          patchCord3(i2s1, 0, freeverb1, 0);
AudioConnection          patchCord4(i2s1, 0, delay1, 0);
AudioConnection          patchCord5(i2s1, 0, filter1, 0);
AudioConnection          patchCord6(i2s1, 1, chorus2, 0);
AudioConnection          patchCord7(i2s1, 1, waveshape2, 0);
AudioConnection          patchCord8(i2s1, 1, freeverb2, 0);
AudioConnection          patchCord9(i2s1, 1, delay2, 0);
AudioConnection          patchCord10(i2s1, 1, filter1, 1);
AudioConnection          patchCord11(delay1, 0, mixer3, 0);
AudioConnection          patchCord12(waveshape2, 0, mixer2, 1);
AudioConnection          patchCord13(freeverb1, 0, mixer1, 2);
AudioConnection          patchCord14(waveshape1, 0, mixer1, 1);
AudioConnection          patchCord15(delay2, 0, mixer4, 0);
AudioConnection          patchCord16(freeverb2, 0, mixer2, 2);
AudioConnection          patchCord17(chorus1, 0, mixer1, 0);
AudioConnection          patchCord18(filter1, 0, mixer3, 1);
AudioConnection          patchCord19(filter1, 1, mixer4, 1);
AudioConnection          patchCord20(chorus2, 0, mixer2, 0);
AudioConnection          patchCord21(mixer1, 0, mixer5, 0);
AudioConnection          patchCord22(mixer2, 0, mixer6, 0);
AudioConnection          patchCord23(mixer3, 0, mixer5, 1);
AudioConnection          patchCord24(mixer4, 0, mixer6, 1);
AudioConnection          patchCord25(mixer5, 0, i2s2, 0);
AudioConnection          patchCord26(mixer6, 0, i2s2, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=80,36

