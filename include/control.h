// Menu Variable
float p_reverb[2] = {0, 0};                          // Damping, Room
float p_filter[2] = {0, 0};                          // Low Cut, N/A, High Cut
float wet = 0;
int i = 0;

void update_menu(int val)
{
    i = i + val;
    i = i % 3;
    switch (i)
    {
    case 0:
        Display.reverb();
        Serial.println("Reverb");
        Display.update_p(p_reverb[0], wet, p_reverb[1]);
        break;
    case -2:
    case 1:
        Display.filter();
        Serial.println("Filter");
        Display.update_p(p_filter[0], wet, p_filter[1]);
        break;
    case -1:
    case 2:
        Display.fft();
        Serial.println("FFT");
        break;
    }
    Serial.println(i);
}

void update_p1(float val)
{
    switch (i)
    {
    case 0:
        p_reverb[0] = p_reverb[0] + val;

        p_reverb[0] = (p_reverb[0] < 0) ? 0 : p_reverb[0];   
        p_reverb[0] = (p_reverb[0] > 100) ? 100 : p_reverb[0];
        
        Serial.println("Damping (Reverb): ");
        Serial.println(p_reverb[0]);

        freeverb1.damping(p_reverb[0]);
        freeverb2.damping(p_reverb[0]);
        Display.update_p(p_reverb[0], wet, p_reverb[1]);
        break;
    case -2:
    case 1:
        p_filter[0] = p_filter[0] + val;
        
        biquad1.setLowpass(0, p_filter[0], 0);
        Display.update_p(p_filter[0], wet, p_filter[1]);

        Serial.println("Low Cut");
        break;
    case -1:
    case 2: 
        Serial.print("Case 2");
        break;
    }
}

void update_p2(float val)
{
    switch (i)
    {
    case 0:
        wet = wet + val;

        wet = (wet < 0) ? 0 : wet;   
        wet = (wet > 100) ? 100 : wet;    
        
        Serial.println("Dry/Wet (Reverb): ");
        Serial.println(wet);
        Display.update_p(p_reverb[0], wet, p_reverb[1]);
        break;
    case -2:
    case 1:
        wet = wet + val;
        wet = (wet < 0) ? 0 : wet;   
        wet = (wet > 100) ? 100 : wet;
        Display.update_p(p_filter[0], wet, p_filter[1]);
        break;
    case -1:
    case 2:
        break;
    }
}

void update_p3(float val)
{
    switch (i)
    {
    case 0:
        p_reverb[1] = p_reverb[1] + val;

        p_reverb[1] = (p_reverb[1] < 0) ? 0 : p_reverb[1];   
        p_reverb[1] = (p_reverb[1] > 100) ? 100 : p_reverb[1];

        Serial.println("Room (Reverb):");
        Serial.println(p_reverb[1]);

        freeverb1.roomsize(p_reverb[1]);
        freeverb2.roomsize(p_reverb[1]);

        Display.update_p(p_reverb[0], wet, p_reverb[1]);
        break;
    case -2:
    case 1:
        Serial.println("Low Cut");
        p_filter[1] = p_filter[1] + val;

        p_filter[1] = (p_filter[1] < 0) ? 0 : p_filter[1];   
        p_filter[1] = (p_filter[1] > 100) ? 100 : p_filter[1];

        biquad1.setHighpass(1, p_filter[1], 0);

        Display.update_p(p_filter[0],wet,p_filter[1]);        
        break;
    case -1: 
    case 2:
        break;
    }
}