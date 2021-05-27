#include <iostream>

class Encoder{
    public: 
    int EncoderMod;

    void mod(int x){
        EncoderMod = x;
    }
    

};



int main(){
    Encoder Test;
    Test.EncoderMod = 1;
    std::cout << Test.EncoderMod << std::endl;
    Test.mod(3);
    std::cout << Test.EncoderMod << std::endl;
    return 0;
}