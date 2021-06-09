int con_var[4] = {0, 0, 0, 0};

void update_menu(){
    switch(con_var[0]){
        case 0:
            Serial.print(con_var[0]);
            Serial.println("Chorus");
            break;
        case 1:
            Serial.print(con_var[0]);
            Serial.println("Hall");
            break;
        case 2:
            Serial.print(con_var[0]);
            Serial.println("Reverb");
            break;
        case 3:
            Serial.print(con_var[0]);
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
            Serial.println("P2 (Delay)");
            Serial.println(con_var[1]);
            break;
    }
    
}

void update_p2(){
    Serial.println(con_var[2]);
}

void update_p3(){
    Serial.println(con_var[3]);
}