class KY_040{

   public: 
   int CLK;
   int DATA;
   int SW;
   int mod;
   int mod_temp;

   uint8_t prevNextCode = 0;
   uint16_t store=0;

   void encoder_start(){
      // Button
      pinMode(SW, INPUT_PULLUP);

      // Encoder
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
   mod_temp = mod;
   mod = mod_neu;
   return mod_neu;
   }
   };

   KY_040 Encoder_Menu;
   KY_040 Encoder_p1;
   KY_040 Encoder_p2;
   KY_040 Encoder_dry;

   void encoder_init(){
   // Encoder Menu
   Encoder_Menu.CLK = 30;
   Encoder_Menu.DATA = 31;
   Encoder_Menu.SW = 32;
   Encoder_Menu.encoder_start();
   Encoder_Menu.read_rotary();

   // EncoderB
   Encoder_p1.CLK = 23;
   Encoder_p1.DATA = 24;
   Encoder_p1.encoder_start();
   Encoder_p1.read_rotary();

   // EncoderC
   Encoder_p2.CLK = 12;
   Encoder_p2.DATA = 13;
   Encoder_p2.encoder_start();
   Encoder_p2.read_rotary();

   //EncoderD
   Encoder_dry.CLK = 12;
   Encoder_dry.DATA = 13;
   Encoder_dry.encoder_start();
   Encoder_dry.read_rotary();
   }

   int Encoder_Menu_mod_old = 0;
   int Encoder_Menu_mod_new = 0;

   int EncoderB_mod_old = 0;
   int EncoderB_mod_new = 0;

   int EncoderC_mod_old = 0;
   int EncoderC_mod_new = 0;

   int EncoderD_mod_old = 0;
   int EncoderD_mod_new = 0;

   void encoder_update(){
   // Encoder A
   Encoder_Menu_mod_new = Encoder_Menu.encoder_update(Encoder_Menu_mod_new);
   Encoder_Menu_mod_old = Display.update(Encoder_Menu_mod_new,Encoder_Menu_mod_old);
   }