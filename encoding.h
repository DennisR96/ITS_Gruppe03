class KY_040{
   public: 
   int CLK;
   int DATA;

   uint8_t prevNextCode = 0;
   uint16_t store=0;

   

   void encoder_start(){
      pinMode(CLK, INPUT);
      pinMode(CLK, INPUT);
      pinMode(CLK, INPUT_PULLUP);
      pinMode(DATA, INPUT);
      pinMode(DATA, INPUT_PULLUP);
   }

   int8_t read_rotary() {
   static int8_t rot_enc_table[] = {0,1,1,0,1,0,0,1,1,0,0,1,0,1,1,0};

   prevNextCode <<= 2;
   if (digitalRead(DATA)) prevNextCode |= 0x02;
   if (digitalRead(CLK)) prevNextCode |= 0x01;
   prevNextCode &= 0x0f;

      // If valid then store as 16 bit data.
      if  (rot_enc_table[prevNextCode] ) {
         store <<= 4;
         store |= prevNextCode;
         //if (store==0xd42b) return 1;
         //if (store==0xe817) return -1;
         if ((store&0xff)==0x2b) return -1;
         if ((store&0xff)==0x17) return 1;
      }
      return 0;
   }

   int encoder_update(int mod_neu) {
   static int8_t c,val;
      if( val=read_rotary()) {
         c +=val;
         mod_neu = abs(c) % 4;
         Serial.print(mod_neu);
         Serial.print(" ");
      }
      return mod_neu;
   }
};

KY_040 EncoderA;
KY_040 EncoderB;
KY_040 EncoderC;
KY_040 EncoderD;

void encoder_init(){
   // EncoderA
   EncoderA.CLK = 30;
   EncoderA.DATA = 31;
   EncoderA.encoder_start();
   EncoderA.read_rotary();

   // EncoderB
   EncoderB.CLK = 23;
   EncoderB.DATA = 24;
   EncoderB.encoder_start();
   EncoderB.read_rotary();

   // EncoderC
   EncoderC.CLK = 12;
   EncoderC.DATA = 13;
   EncoderC.encoder_start();
   EncoderC.read_rotary();

   //EncoderD
   EncoderD.CLK = 12;
   EncoderD.DATA = 13;
   EncoderD.encoder_start();
   EncoderD.read_rotary();
}

int EncoderA_mod_old = 0;
int EncoderA_mod_new = 0;

int EncoderB_mod_old = 0;
int EncoderB_mod_new = 0;

int EncoderC_mod_old = 0;
int EncoderC_mod_new = 0;

int EncoderD_mod_old = 0;
int EncoderD_mod_new = 0;

void encoder_update(){
   // Encoder A
   EncoderA_mod_new = EncoderA.encoder_update(EncoderA_mod_new);
   EncoderA_mod_old = Display.update(EncoderA_mod_new,EncoderA_mod_old);
}
