// Audio Shield Cheat Sheet
#include <Audio.h>

//Control
AudioControlSGTL5000 audioShield;
audioShield.enable();                       // Audio-Shield - Enable
audioShield.volume(0.5);                    // Audio-Shield - Volume

// Connection
AudioConnection myConnection(source, sourcePort, destination, destinationPort); 
AudioConnection myConnection(source, destination);

// Connection Mix 2 Sounds
AudioConnection c1(sound0, 0, mix1, 0);
AudioConnection c2(sound1, 0, mix1, 1);

// Effect
AudioEffectBitcrusher                    // Bitcrusher
AudioEffectChorus                        // Chorus
AudioEffectEnvelope      envelope1;      // Enevlope Effect

// Input
AudioInputUSB            usb1;           //xy=200,69  (must set Tools > USB Type to Audio)

// Mixer
AudioMixer1              mixer1;         //xy=486,163

//Output
AudioOutputI2S      audioOutput;        // Class: Headphone & Lineout
AudioOutputAnalog

// Synthesizer
AudioSynthNoisePink      pink1;          // Synth: Noise Pink
AudioSynthWaveformSine   sine1;          // Synth: Sine Wav


// Various
AudoMemory(NumberOfBlocks);
AudioMemoryUsage();
AudioMemoryUsageMax();
AudioMemoryUsageMaxReset();