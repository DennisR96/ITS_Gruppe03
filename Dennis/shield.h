#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// 0: Control
AudioControlSGTL5000 audio_shield;

// 1: Input Signal
AudioSynthWaveformSine          input1;       // Input Signal

// 2: FX
AudioEffectFreeverb      freeverb1;             // FX: Reverb
AudioEffectChorus        chorus1;               // FX: Chorus
AudioEffectWaveshaper    waveshape1;            // FX: Waveshape
AudioEffectDelay         delay1;                // FX: Delay

// 3: Mixer
AudioMixer4              mixer1;                // Mixer 4x1

// 4: Filter
AudioFilterBiquad        biquad1;               // Filter (Biquad)

// 5: Output
AudioOutputI2S           i2s1;                  // Output Signal

// 6: Patching
AudioConnection          patchCord1(input1, delay1);
AudioConnection          patchCord2(input1, waveshape1);
AudioConnection          patchCord3(input1, chorus1);
AudioConnection          patchCord4(input1, freeverb1);
AudioConnection          patchCord5(freeverb1, 0, mixer1, 0);
AudioConnection          patchCord6(chorus1, 0, mixer1, 1);
AudioConnection          patchCord7(waveshape1, 0, mixer1, 2);
AudioConnection          patchCord8(delay1, 0, mixer1, 3);
AudioConnection          patchCord9(mixer1, i2s1);





