// Variables: PIN-Codes of Rotary Encoder
int CLK[4] = {31, 24, 27, 35};
int DATA[4] = {30, 25, 28, 34};
int SW[4] = {32, 26, 29, 33};

// Variables: Quadrature Phase Encoding
uint8_t prevNextCode[4] = {0, 0, 0, 0};
uint16_t store[4] = {0, 0, 0, 0};
static int8_t val[4] = {0, 0, 0, 0};

// Variables: FFT Update Timer 
unsigned long previousMillis = 0;
const long interval = 75; 

// Bouncing of Rotary Encoder Buttons
Bounce button0 = Bounce(SW[0], 15);
Bounce button1 = Bounce(SW[1], 15);
Bounce button2 = Bounce(SW[2], 15);
Bounce button3 = Bounce(SW[3], 15);

void fft_update(){ 
    // Function: Reading new FFT Parameters 
    if (i == 2 || i == -1){
        level[0] =  fft1024.read(1,4);
        level[1] =  fft1024.read(5,8);
        level[2] =  fft1024.read(9,12);
        level[3] =  fft1024.read(13,16);
        level[4] =  fft1024.read(17,20);
        level[5] =  fft1024.read(21.50);
        level[6] =  fft1024.read(51, 80);
        level[7] =  fft1024.read(81, 110);
        level[8] =  fft1024.read(111, 140);
        level[9] =  fft1024.read(141, 170);
        level[10] = fft1024.read(171, 200);
        level[11] = fft1024.read(201, 262);
        level[12] = fft1024.read(263, 324);
        level[13] = fft1024.read(325, 386);
        level[14] = fft1024.read(387, 511);
        Display.update_fft(level);
    }       
}

void encoder_start(){
    // Function: Initialsing Rotary Encoders with PIN-Variables
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
    // Function: Debouncing KY-040 with Quadrature Phase Encoding
    // Credit: John Main
    // Source: https://www.best-microcontroller-projects.com/rotary-encoder.html 
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
    // Function: Updating Rotary Encoder changes and FFT Values
      unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= interval) {
        previousMillis = currentMillis;
        fft_update();
        currentMillis = 0;
    }
    if ((val[0]=encoder_init(store[0], prevNextCode[0], CLK[0], DATA[0]))) {
        update_menu(val[0]);
        }

    if((val[1]=encoder_init(store[1], prevNextCode[1], CLK[1], DATA[1]))) {
        update_p1(val[1]);
    }

    if((val[2]=encoder_init(store[2], prevNextCode[2], CLK[2], DATA[2]))) {
         update_p2(val[2]);
    }

    if((val[3]=encoder_init(store[3], prevNextCode[3], CLK[3], DATA[3]))) {
         update_p3(val[3]);
    }

    button0.update();
    button1.update();
    button2.update();
    button3.update();

    if (button0.risingEdge()) {
        Serial.println("Reverb zurückgesetzt");
    } 
    if (button1.fallingEdge()) {
        Serial.println("Filter zurückgesetzt");
    } 
    if (button2.fallingEdge()) {
    } 
    return 0;
   }


 