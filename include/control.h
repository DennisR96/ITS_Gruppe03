// Menu Variable
float p_reverb[3] = {0, 0, 0};                          // Damping, Dry/Wet, Room
float p_filter[3] = {0, 0, 0};                          // Low Cut, N/A, High Cut
int i = 0;

void update_menu(int val)
{
    i = i + val;
    i = i % 3;
    switch (i)
    {
    case 0:
        Serial.println("Reverb");
        break;
    case -2:
    case 1:
        Serial.println("Filter");
        break;
    case -1:
    case 2:
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

        //freeverb1.damping(p_reverb[0]);
        //freeverb2.damping(p_reverb[0]);
        break;
    case -2:
    case 1:
        Serial.print("Low Cut");
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
        p_reverb[1] = p_reverb[1] + val;

        p_reverb[1] = (p_reverb[1] < 0) ? 0 : p_reverb[1];   
        p_reverb[1] = (p_reverb[1] > 100) ? 100 : p_reverb[1];    
        
        Serial.println("Dry/Wet (Reverb): ");
        Serial.println(p_reverb[1]);

       
        break;
    case -2:
    case 1:
        
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
        p_reverb[2] = p_reverb[2] + val;

        p_reverb[2] = (p_reverb[2] < 0) ? 0 : p_reverb[2];   
        p_reverb[2] = (p_reverb[2] > 100) ? 100 : p_reverb[2];

        Serial.println("Room (Reverb):");
        Serial.println(p_reverb[2]);

        //freeverb1.roomsize(p_reverb[2]);
        //freeverb2.roomsize(p_reverb[2]);
        break;
    case -2:
    case 1:
        Serial.println("Low Cut");
        break;
    case -1: 
    case 2:
        break;
    }
}