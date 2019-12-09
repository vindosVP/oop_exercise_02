#include <iostream>

#include "modulo.hpp"

int main() {
    Modulo a;
    Modulo b;
    Modulo c;

    std::cin >> a;
    std::cin >> b;

    std::cout << "Addition:" << std::endl;
    std::cout << a+b;

    std::cout << "Subtraction:" << std::endl;
    std::cout << a-b;


    std::cout << "Multiplication:" << std::endl;
    std::cout << a*b;


    if(a==b) {
        std::cout << "Numbers are equal" << std::endl;
    }

    if(a>b) {
        std::cout << "First number is greater" << std::endl;
    }
    
    if(a<b) {
        std::cout << "First number is less" << std::endl;
    }


    std::cout << "Division:" << std::endl;
    c = a/b;
    if(c.GetMod()) {
        std::cout << c;
;        
    }

 
 return 0;
}
