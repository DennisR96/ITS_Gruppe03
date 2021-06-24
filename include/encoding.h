int CLK[4] = {31,24, 27, 35};
int DATA[4] = {30,25, 28, 34};
int SW[4] = {32,26, 29, 33};

uint8_t prevNextCode[4] = {0, 0, 0, 0};
uint16_t store[4] = {0, 0, 0, 0};

Bounce button0 = Bounce(SW[0], 15);
Bounce button1 = Bounce(SW[1], 15);
Bounce button2 = Bounce(SW[2], 15);
Bounce button3 = Bounce(SW[3], 15);

static int8_t val[4] = {0, 0, 0, 0};


void fft_update(){
    if (i == 2 || i == -1){
        
        level[0] =  fft1024.read(1);
        level[1] =  fft1024.read(2);
        level[2] =  fft1024.read(3);
        level[3] =  fft1024.read(4);
        level[4] =  fft1024.read(5, 7);
        level[5] =  fft1024.read(7, 9);
        level[6] =  fft1024.read(9, 13);
        level[7] =  fft1024.read(13, 17);
        level[8] =  fft1024.read(17, 23);
        level[9] =  fft1024.read(23, 46);
        level[10] = fft1024.read(46, 69);
        level[11] = fft1024.read(69, 92);
        level[12] = fft1024.read(92, 138);
        level[13] = fft1024.read(138, 207);
        level[14] = fft1024.read(207, 414);
        level[15] = fft1024.read(414, 511);
    }
   
    
}


void encoder_start(){
    pinMode(CLK[0],INPUT_PULLUP);
    pinMode(CLK[1],INPUT_PULLUP);
    pinMode(CLK[2],INPUT_PULLUP);
    pinMode(CLK[3],INPUT_PULLUP);

    pinMode(DATA[0],INPUT_PULLUP);
    pinMode(DATA[1],INPUT_PULLUP);
    pinMode(DATA[2],INPUT_PULLUP);
    pinMode(DATA[3],INPUT_PULLUP);

    pinMode(SW[0],INPUT_PULLUP);
    pinMode(SW[1],INPUT_PULLUP);
    pinMode(SW[2],INPUT_PULLUP);
    pinMode(SW[3],INPUT_PULLUP);
}

int8_t encoder_init(uint16_t &store, uint8_t &prevNextCode,int CLK, int DATA){
    static int8_t rot_enc_table[] = {0,1,1,0,1,0,0,1,1,0,0,1,0,1,1,0};
    prevNextCode <<= 2;
    if (digitalRead(DATA)) prevNextCode |= 0x02;
    if (digitalRead(CLK)) prevNextCode |= 0x01;
    prevNextCode &= 0x0f;

    if  (rot_enc_table[prevNextCode] ) {
    store <<= 4;
    store |= prevNextCode;
    
    if ((store&0xff)==0x2b) return -1;
    if ((store&0xff)==0x17) return 1;
    }
   
   return 0;
   }

int8_t encoder_update(){
    fft_update();
    if (val[0]=encoder_init(store[0], prevNextCode[0], CLK[0], DATA[0]) ) {
        update_menu(val[0]);
        }

    if(val[1]=encoder_init(store[1], prevNextCode[1], CLK[1], DATA[1])) {
        update_p1(val[1]);
    }

    if(val[2]=encoder_init(store[2], prevNextCode[2], CLK[2], DATA[2])) {
         update_p2(val[2]);
    }

    if(val[3]=encoder_init(store[3], prevNextCode[3], CLK[3], DATA[3])) {
         update_p3(val[3]);
    }

    button0.update();
    button1.update();
    button2.update();
    button3.update();

    if (button0.fallingEdge()) {
        Serial.println("SW0: Gedrückt");
    } 
    if (button1.fallingEdge()) {
        Serial.println("SW1: Gedrückt");
    } 
    if (button2.fallingEdge()) {
        Serial.println("SW2: Gedrückt");
    } 
    if (button3.fallingEdge()) {
        Serial.println("SW3: Gedrückt");
    } 
    return 0;
   }


 