#include <iostream>

#include "modulo.hpp"

int main() {
    Modulo a;
    Modulo b;
    Modulo c;
    
    a.Read(std::cin);
    b.Read(std::cin);

    std::cout << "Addition:" << std::endl;
    c = a+b;
    c.Print(std::cout);

    std::cout << "Subtraction:" << std::endl;
    c = a-b;
    c.Print(std::cout);

    std::cout << "Multiplication:" << std::endl;
    c = a*b;
    c.Print(std::cout);

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
        c.Print(std::cout);        
    }

 
 return 0;
}
