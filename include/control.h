float p1[4] = {0, 0, 0, 0};
float p2[4] = {0, 0, 0, 0};
float p3[4] = {0, 0, 0, 0};
int i = 0;

void update_menu(int val)
{
    i = i + val;
    i = i % 4;
    switch (i)
    {
    case 0:
        Serial.print(i);
        Serial.println(" Bitcrush");
        break;
    case -1:
    case 1:
        Serial.print(i);
        Serial.println(" Chorus");
        break;
    case -2:
    case 2:
        Serial.print(i);
        Serial.println(" Delay");
        break;
    case -3:
    case 3:
        Serial.print(i);
        Serial.println(" Reverb");
        break;
    }
}

void update_p1(float val)
{
    switch (i)
    {
    case 0:
        p1[0] = p1[0] + val;

        p1[0] = (p1[0] < 0.0) ? 0.0 : p1[0];   // Min: 0.0
        p1[0] = (p1[0] > 16.0) ? 16.0 : p1[0]; // Max: 1.0

        Serial.println("Bits (Bitcrush): ");
        Serial.println(p1[0]);
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
        val = val / 100;
        p1[3] = p1[3] + val;

        p1[3] = (p1[3] < 0.0) ? 0.0 : p1[3]; // Min: 0.0
        p1[3] = (p1[3] > 1.0) ? 1.0 : p1[3]; // Max: 1.0

        Serial.println("Roomsize (Reverb):");
        Serial.println(p1[3]);
        break;

        break;
    }
}

void update_p2(int val)
{
    switch (i)
    {
    case 0:
        p2[0] = p2[0] + val;

        p2[0] = (p2[0] < 0.0) ? 0.0 : p2[0];   // Min: 0.0
        p2[0] = (p2[0] > 44100.0) ? 44100.0 : p2[0]; // Max: 1.0

        Serial.println("Bits (Bitcrush): ");
        Serial.println(p2[0]);
        break;
    case 1:
        p2[1] = p2[1] + val;
        Serial.println("Chorus ");
        Serial.println(p2[1]);
        break;
    case 2:
        val = val / 100;
        p2[2] = p2[2] + val;

        p2[2] = (p2[2] < 0.0) ? 0.0 : p2[2]; // Min: 0.0
        p2[2] = (p2[2] > 1.0) ? 1.0 : p2[2]; // Max: 1.0

        Serial.println("Damping (Reverb):");
        Serial.println(p2[2]);
        break;
    case 3:
        p2[2] = p2[2] + val;
        Serial.println("P1 (Delay)");
        Serial.println(p2[2]);
        break;
    }
    for (int idx = 0; idx < 4; idx++)
    {
        p2[idx] = (p2[idx] > 100) ? 100 : p2[idx];
        p2[idx] = (p2[idx] < 0) ? 0 : p2[idx];
    }
}

void update_p3(int val)
{
    switch (i)
    {
    case 0:
        p2[0] = p2[0] + val;
        Serial.println("P1 (Chorus:)");
        Serial.println(p2[0]);
        break;
    case 1:
        p2[1] = p2[1] + val;
        Serial.println("P1 (Distortion): ");
        Serial.print(p2[1]);
        break;
    case 2:
        p2[2] = p2[2] + val;
        Serial.println("P1 (Reverb)");
        Serial.print(p2[2]);
        break;
    case 3:
        p2[2] = p2[2] + val;
        Serial.println("P1 (Delay)");
        Serial.print(p2[2]);
        break;
    }
    for (int idx = 0; idx < 4; idx++)
    {
        p2[idx] = (p2[idx] > 100) ? 100 : p2[idx];
        p2[idx] = (p2[idx] < 0) ? 0 : p2[idx];
    }
}