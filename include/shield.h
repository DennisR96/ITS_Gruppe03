#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioSynthWaveformSine   sine1;          //xy=210,366
AudioEffectBitcrusher    bitcrusher1;    //xy=457,279
AudioOutputI2S           i2s1;           //xy=765,379
AudioConnection          patchCord1(sine1, bitcrusher1);
AudioConnection          patchCord2(bitcrusher1, 0, i2s1, 0);
AudioConnection          patchCord3(bitcrusher1, 0, i2s1, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=174,639
// GUItool: end automatically generated code

// GUItool: end automatically generated code


// //USB
// AudioInputI2S            usb1;           //xy=316,164

// //Effekte
// AudioEffectChorus        chorus2;        //xy=545.7142791748047,76.28569412231445
// AudioEffectChorus        chorus1;        //xy=546.7143020629883,23.571426391601562
// AudioEffectWaveshaper    waveshape2;     //xy=565.0000267028809,173.28571701049805
// AudioEffectReverb        reverb1;        //xy=566.0794067382812,235.6349277496338
// AudioEffectReverb        reverb2;        //xy=570.571418762207,277.57139778137207
// AudioEffectWaveshaper    waveshape1;     //xy=575.4285049438477,132.1428565979004
// AudioEffectDelay         delay1;         //xy=578.7143135070801,380.85711669921875
// AudioEffectDelay         delay2;         //xy=580.5714645385742,535.2857055664062
// AudioFilterStateVariable filter1;        //xy=583.3333396911621,683.3332786560059

// //Mixerstufe 1
// AudioMixer4              mixer3;         //xy=851.2697257995605,53.57143020629883
// AudioMixer4              mixer4;         //xy=854.1271324157715,140.7936553955078
// AudioMixer4              mixer6;         //xy=863.333309173584,333.015811920166
// AudioMixer4              mixer5;         //xy=866.5079574584961,265.7142906188965

// //Mixerstufe 2
// AudioMixer4              mixer2;         //xy=1006,191
// AudioMixer4              mixer1;         //xy=1007,126

// //Output
// AudioOutputI2S           i2s1;           //xy=1251,151

// //Patching
// AudioConnection          patchCord1(usb1, 0, chorus1, 0);
// AudioConnection          patchCord2(usb1, 0, reverb1, 0);
// AudioConnection          patchCord3(usb1, 0, delay1, 0);
// AudioConnection          patchCord4(usb1, 0, waveshape1, 0);
// AudioConnection          patchCord5(usb1, 0, filter1, 0);
// AudioConnection          patchCord6(usb1, 1, chorus2, 0);
// AudioConnection          patchCord7(usb1, 1, reverb2, 0);
// AudioConnection          patchCord8(usb1, 1, delay2, 0);
// AudioConnection          patchCord9(usb1, 1, waveshape2, 0);
// AudioConnection          patchCord10(usb1, 1, filter1, 1);
// AudioConnection          patchCord11(chorus2, 0, mixer4, 0);
// AudioConnection          patchCord12(chorus1, 0, mixer3, 0);
// AudioConnection          patchCord13(waveshape2, 0, mixer4, 1);
// AudioConnection          patchCord14(reverb1, 0, mixer3, 2);
// AudioConnection          patchCord15(reverb2, 0, mixer4, 2);
// AudioConnection          patchCord16(waveshape1, 0, mixer3, 1);
// AudioConnection          patchCord17(delay1, 0, mixer3, 3);
// AudioConnection          patchCord18(delay2, 0, mixer4, 3);
// AudioConnection          patchCord19(filter1, 0, mixer5, 0);
// AudioConnection          patchCord20(filter1, 1, mixer6, 0);
// AudioConnection          patchCord21(mixer3, 0, mixer1, 0);
// AudioConnection          patchCord22(mixer4, 0, mixer2, 0);
// AudioConnection          patchCord23(mixer6, 0, mixer2, 1);
// AudioConnection          patchCord24(mixer5, 0, mixer1, 1);
// AudioConnection          patchCord25(mixer2, 0, i2s1, 1);
// AudioConnection          patchCord26(mixer1, 0, i2s1, 0);

// //AudioControl
// AudioControlSGTL5000     sgtl5000_1;     //xy=162.7777557373047,246.11109924316406

