#include <iostream>

int a = 0;

void button(int &a){
    if (a == 0){
        std::cout << "Eingang" << std::endl;
    }
    else if (a == 1){
        std::cout << "100% Wet" << std::endl;
    }
    else if (a == 2){
    std::cout << "100% Dry" << std::endl;
    }
    a += 1;
    a = a % 3;
}


int main(){
    button(a);                          // Eingang
    button(a);                          // Wet
    button(a);                          // Dry
    button(a);                          // Eingang
    button(a);                          // Wet
    button(a);                          // Dry
    button(a);                          // Eingang

}