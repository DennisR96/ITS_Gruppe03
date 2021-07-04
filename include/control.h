// Variables: FX Parameters
float p_reverb[2] = {0, 0};                                     // Damping, Room
float p_filter[2] = {400, 12000};                               // Low Cut, N/A, High Cut

// Variables: Dry/Wet
float wet = 0;
float wet_old = 0;

// Variables: Menu & FFT
int i = 0;
float level[15];


void update_menu(int val){
    //Function: Change Menu Points with Encoder A
    i = i + val;
    i = i % 3;
    switch (i)
    {
    case 0:
        Display.reverb();
        Serial.println("Reverb: ");
        Display.update_p(p_reverb[0], wet, p_reverb[1]);
        break;
    case -2:
    case 1:
        Display.filter();
        Serial.println("Filter: ");
        Display.update_p(p_filter[0], wet, p_filter[1]);
        break;
    case -1:
    case 2:
        Display.fft();
        Serial.println("FFT: ");
        break;
    }
    Serial.println(i);
}

void update_p1(float val){
    // Function: Change Parameter 1 with Encoder B
    Serial.print(i);
    switch (i)
    {
    case 0:
        p_reverb[0] = p_reverb[0] + val;
        p_reverb[0] = (p_reverb[0] < 0) ? 0 : p_reverb[0];   
        p_reverb[0] = (p_reverb[0] > 100) ? 100 : p_reverb[0];
        Serial.println("Damping: ");
        Serial.println(p_reverb[0]);
        freeverb1.damping(p_reverb[0]);
        freeverb2.damping(p_reverb[0]);
        Display.update_p(p_reverb[0], wet, p_reverb[1]);
        break;
    case -2:
    case 1:
        p_filter[0] = p_filter[0] + val*100;
        p_filter[0] = (p_filter[0] < 400) ? 400 : p_filter[0];   
        p_filter[0] = (p_filter[0] > 12000) ? 12000 : p_filter[0];
        Serial.println("L-Cut:");
        Serial.println(p_filter[0]);
        biquad1.setHighpass(0, p_filter[0], 0.707);
        biquad2.setHighpass(0, p_filter[0], 0.707);
        Display.update_p(p_filter[0], wet, p_filter[1]);
        break;
    case -1:
    case 2: 
        p_filter[0] = p_filter[0] + val*100;
        p_filter[0] = (p_filter[0] < 400) ? 400 : p_filter[0];   
        p_filter[0] = (p_filter[0] > 12000) ? 12000 : p_filter[0];
        Serial.println("L-Cut:");
        Serial.println(p_filter[0]);
        biquad1.setHighpass(0, p_filter[0], 0.707);
        biquad2.setHighpass(0, p_filter[0], 0.707);
        break;
    }
}

void reset_p1(){
    switch(i)
    {
        case 0:
            p_reverb[0] = 0;
            freeverb1.damping(p_reverb[0]);
            freeverb2.damping(p_reverb[0]);
            Serial.println("Damping: ");
            Serial.println(p_reverb[0]);
            Display.update_p(p_reverb[0], wet, p_reverb[1]);
            break;
        case -2:
        case 1:
            p_filter[0] = 400;
            Serial.println("L-Cut:");
            Serial.println(p_filter[0]);
            biquad1.setHighpass(0, p_filter[0], 0.707);
            biquad2.setHighpass(0, p_filter[0], 0.707);
            Display.update_p(p_filter[0], wet, p_filter[1]);
            break;
    }
}

void update_p2(float val){
    // Function: Change Parameter 2 with Encoder C
    wet = wet + val;
    wet = (wet < 0) ? 0 : wet;   
    wet = (wet > 100) ? 100 : wet;    
    Serial.println("Dry/Wet");
    Serial.println(wet/100);
    Serial.println(1-(wet/100));
    mixer1.gain(0,wet/100);
    mixer1.gain(1,wet/100);
    mixer1.gain(2,1-(wet/100));
    mixer1.gain(3,1-(wet/100));
    switch (i)
    {
    case 0:
        Display.update_p(p_reverb[0], wet, p_reverb[1]);        
        break;
    case -2:
    case 1:
        Display.update_p(p_filter[0], wet, p_filter[1]);
        break;
    case -1:
    case 2:
        break;
    }
}

void reset_p2(){
    if (wet_old == 0){
        wet_old = wet;
        wet = 0;
    }
    else if (wet_old != 0){
        wet = wet_old;
        wet_old = 0;
    }
    Serial.println("Dry/Wet");
    Serial.println(wet/100);
    Serial.println(1-(wet/100));
    mixer1.gain(0,wet/100);
    mixer1.gain(1,wet/100);
    mixer1.gain(2,1-(wet/100));
    mixer1.gain(3,1-(wet/100));
    switch(i){
        case 0:
            Display.update_p(p_reverb[0], wet, p_reverb[1]);
            break;  
        case -2:
        case 1:
            Display.update_p(p_filter[0], wet, p_filter[1]);
            break;
    }
}


void update_p3(float val){
    // Function: Change Parameter 3 with Encoder D
    Serial.print(i);
    switch (i)
    {
    case 0:
        p_reverb[1] = p_reverb[1] + val;
        p_reverb[1] = (p_reverb[1] < 0) ? 0 : p_reverb[1];   
        p_reverb[1] = (p_reverb[1] > 100) ? 100 : p_reverb[1];
        Serial.println("Room: ");
        Serial.println(p_reverb[1]);
        freeverb1.roomsize(p_reverb[1]);
        freeverb2.roomsize(p_reverb[1]);
        Display.update_p(p_reverb[0], wet, p_reverb[1]);
        break;
    case -2:
    case 1:
        p_filter[1] = p_filter[1] - val*100;
        p_filter[1] = (p_filter[1] < 1200) ? 1200 : p_filter[1];   
        p_filter[1] = (p_filter[1] > 12000) ? 12000 : p_filter[1];
        Serial.println("High Cut: ");
        Serial.println(p_filter[1]);
        biquad1.setLowpass(1, p_filter[1], 0.707);
        biquad2.setLowpass(1, p_filter[1], 0.707);
        Display.update_p(p_filter[0], wet, p_filter[1]);        
        break;
    case -1: 
    case 2:
        p_filter[1] = p_filter[1] - val*100;
        p_filter[1] = (p_filter[1] < 1200) ? 1200 : p_filter[1];   
        p_filter[1] = (p_filter[1] > 12000) ? 12000 : p_filter[1];
        Serial.println("High Cut: ");
        Serial.println(p_filter[1]);
        biquad1.setLowpass(1, p_filter[1], 0.707);
        biquad2.setLowpass(1, p_filter[1], 0.707);
        break;
    }
}

void reset_p3(){
    switch(i)
    {
        case 0:
            p_reverb[1] = 0;
            Serial.println("Room: ");
            Serial.println(p_reverb[1]);
            freeverb1.roomsize(p_reverb[1]);
            freeverb2.roomsize(p_reverb[1]);
            Display.update_p(p_reverb[0], wet, p_reverb[1]);
            break;
        case -2:
        case 1:
            p_filter[1] = 1200;
            Serial.println("High Cut: ");
            Serial.println(p_filter[1]);
            biquad1.setLowpass(1, p_filter[1], 0.707);
            biquad2.setLowpass(1, p_filter[1], 0.707);
            break;
    }
}