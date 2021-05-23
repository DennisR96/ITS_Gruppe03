#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>
#include <Bounce.h>

class Audio_Shield {
    public:
        void init(){
            AudioControlSGTL5000  audio_shield;      // Class Arduino Shield
            audio_shield.enable();                      // Enable Arduino Shield
            audio_shield.volume(0.5);                    // Standard Volume
            Serial.println("Audio Shield Enabled @ Amplitude 0.5");
        }     
        void sound_test(){
            AudioSynthWaveformSine   sine1;       
            
        }      

};

Audio_Shield Teensy41;
