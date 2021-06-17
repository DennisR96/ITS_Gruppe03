float p1[4] = {16, 20, 20, 50};
float p2[4] = {0, 0, 0, 0};
float p3[4] = {44100, 2, 1, 50};
unsigned int i = 0;

void update_menu(int val)
{
    i = i + val;
    i = i % 4;
    switch (i)
    {
    case 0:
        Display.fx_bitcrush();
        break;
    case 1:
        Display.fx_chrous();
        break;
    case 2:
        Display.fx_delay();
        break;
    case 3:
        Display.fx_reverb(); 
        break;
    }
    Serial.print(i);
    Display.update_p(p1[i], p2[i], p3[i]);
}

void update_p1(float val)
{
    switch (i)
    {
    case 0:
        p1[0] = p1[0] + val;

        p1[0] = (p1[0] < 1.0) ? 1.0 : p1[0];   // Min: 0
        p1[0] = (p1[0] > 16.0) ? 16.0 : p1[0]; // Max: 16

        Serial.println("Bits (Bitcrush): ");
        Serial.println(p1[0]);
        
        bitcrusher1.bits(p1[0]);
        break;
    case 1:
        p1[1] = p1[1] + val;
        
        Serial.println("Chorus: ");
        Serial.println(p1[1]);
        break;
    case 2:
        p1[2] = p1[2] + val;
        
        Serial.println("Delay: ");
    case 3:
        p1[3] = p1[3] + val;

        p1[3] = (p1[3] < 0) ? 0 : p1[3];   
        p1[3] = (p1[3] > 100) ? 100 : p1[3]; 

        freeverb1.damping(p1[3] /100);
        
        Serial.println("Roomsize (Reverb):");
        Serial.println(p1[3]);
        break;    
    }
    Display.update_p(p1[i], p2[i], p3[i]);
    
}

void update_p2(float val)
{
    Serial.print(i);
    switch (i)
    {
    case 0:
        p2[0] = p2[0] + val;
        Serial.println("Wet Bitcrush");
        Serial.println(p2[0]);
        mixer1.gain(1,p2[0]/100);
        break;
    case 1:
        p2[1] = p2[1] + val;
        Serial.println("Wet Chorus: ");
        Serial.println(p2[1]);
        // mixer1.gain(0,p2[1]/100);
        break;
    case 2:
        p2[2] = p2[2] + val;
        Serial.println("Wet Delay: ");
        Serial.println(p2[2]);
        // mixer1.gain(0,p2[2]/100);
        break;
    case 3:
        p2[3] = p2[3] + val;
        Serial.println("Wet Reverb: ");
        Serial.println(p2[3]);
        mixer1.gain(2,p2[3]/100);
        break;
    }
    for (int idx = 0; idx < 4; idx++)
    {
        p2[idx] = (p2[idx] >= 100) ? 100 : p2[idx];
        p2[idx] = (p2[idx] <= 0) ? 0 : p2[idx];
    }
    Display.update_p(p1[i], p2[i], p3[i]);
}

void update_p3(float val)
{
    switch (i)
    {

    case 0:
        if (val < 0){
            p3[0] = p3[0] * 0.5;
        }
        if (val > 0){
            p3[0] = p3[0] * 2;
        }
        p3[0] = (p3[0] < 6300) ? 6300 : p3[0];   
        p3[0] = (p3[0] > 44100) ? 44100 : p3[0]; 
        bitcrusher1.sampleRate(p3[0]);

        Serial.println("Fs (Bitcrusher):");
        Serial.println(p3[0]);

        break;
    case 1:
        p3[1] = p3[1] + val;
        Serial.println("Chrous");
        Serial.print(p3[1]);
        break;
    case 2:
        p3[2] = p3[2] + val;
        Serial.println("Delay");
        Serial.print(p3[2]);
        break;
    case 3:
        p3[3] = p3[3] + val;

        p3[3] = (p3[3] < 0) ? 0 : p3[3];   
        p3[3] = (p3[3] > 100) ? 100 : p3[3]; 
        freeverb1.roomsize(p3[3] / 100);
        Serial.println("Roomsize (Reverb): ");
        Serial.println(p3[3]);
        break;
    }
    Display.update_p(p1[i], p2[i], p3[i]);
}