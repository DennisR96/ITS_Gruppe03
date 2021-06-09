int con_var[4] = {0, 0, 0, 0};
int p1[4] = {0, 0, 0, 0};
int i = 0;


void update_menu(int val){
    i = i + val;
    i = i % 4;
    Serial.println(i);
    switch(i){
        case 0:
            Serial.print(i);
            Serial.println("Chorus");
            break;
        case -1:
        case 1:
            Serial.print(i);
            Serial.println("Distortion");
            break;
        case -2:
        case 2:
            Serial.print(i);
            Serial.println("Reverb");
            break;
        case -3:
        case 3:
            Serial.print(i);
            Serial.println("Delay");
            break;
    }
}

void update_p1(){
    switch(con_var[0]){
        case 0:
            Serial.println("P1 (Chorus:)");
            Serial.println(con_var[1]);
            break;
        case 1:
            Serial.println("P1 (Distortion): ");
            Serial.println(con_var[1]);
            break;
        case 2:
            Serial.println("P1 (Reverb)");
            Serial.println(con_var[1]);
            break;
        case 3:
            Serial.println("P1 (Delay)");
            Serial.println(con_var[1]);
            break;
    }
}

void update_p2(){
    Serial.print("Hallo Welt");
}

void update_p3(){
    Serial.println(con_var[3]);
}