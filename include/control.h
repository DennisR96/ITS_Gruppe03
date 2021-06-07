int menu(){
            if (c[0] == d[0]){
                return 0;
            }

            switch (c[0]){
                case 0:
                    Display.fx_chrous();
                    Serial.print(e[0]);
                    Serial.println(" Chorus");
                    break;
                case 1:
                    Display.fx_delay();
                    Serial.print(e[0]);
                    Serial.println(" Delay");
                    break;
                case 2:
                    Display.fx_distortion();
                    Serial.print(e[0]);
                    Serial.println(" Distortion");
                    break;
                case 3:
                    Display.fx_reverb();
                    Serial.print(e[0]);
                    Serial.println(" Reverb");
                    break;
            }
                return 0;
}

int p0(){
        if (c[1] == d[1]){
                return 0;
            }

        switch (c[1]){
                case 0:
                    Display.fx_chrous();
                    Serial.print(c[1]);
                    Serial.println(" Chorus");
                    break;
                case 1:
                    Display.fx_delay();
                    Serial.print(c[1]);
                    Serial.println(" Delay");
                    break;
                case 2:
                    Display.fx_distortion();
                    Serial.print(c[1]);
                    Serial.println(" Distortion");
                    break;
                case 3:
                    Display.fx_reverb();
                    Serial.print(c[1]);
                    Serial.println(" Reverb");
                    break;
            }
                return 0;
}


int p1(){
    return 0;

}

int p2(){
    return 0;

}


void control_update(){
    menu();
    p1();
    p2();
}