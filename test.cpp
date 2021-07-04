#include <iostream>

int val = 0;

int test(int a){
    return 0;
}


int main(){
    if ((val = test(0))){
        std::cout << "Hallo Welt";
    }
}


