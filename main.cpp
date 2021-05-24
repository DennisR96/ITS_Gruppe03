#include <Arduino.h>
#include <display.h>
#include <shield.h>
#include <encoding.h>


void setup() {
    Serial.begin(115200);

    // Display
    Display.start();                                    // Display Start
    Display.clear();                                    // Display Clear
    Display.rect();                                     // Disp_rect
    Display.fx_reverb();
    
    // Fx
    AudioMemory(20);
    audio_shield.enable();
    audio_shield.volume(0.8);

    input1.amplitude(0.5);
    input1.frequency(500);
    freeverb1.roomsize(20);
    freeverb1.damping(200);


    }

int mod_alt = 0;
int mod_neu = 0;

void loop() {
  // put your main code here, to run repeatedly:
  mod_neu = scan_Encode(mod_neu);
  mod_alt = Display.update(mod_neu, mod_alt);
}
