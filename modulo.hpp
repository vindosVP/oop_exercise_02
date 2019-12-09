#ifndef _MODULO_H_
#define _MODULO_H_


#include <iostream>
#include <sstream>

class Modulo {
    public:
        Modulo() : number(0), mod(0) {}
        Modulo(int number, int mod) : number(number < 0 ? mod + (number % mod) : number % mod), mod(mod) {}
        Modulo operator+(const Modulo& addend) const;
        Modulo operator*(const Modulo& multiplier) const;
        Modulo operator-(const Modulo& subtracthend) const;
        Modulo operator/(const Modulo& divisor) const;
        void Read(std::istream& is);
        void Print(std::ostream& os) const;
        void SetNumber(int number,int h);
        void SetMod(int mod, int f);
        int GetNumber() const;
        int GetMod() const;
        bool operator==(const Modulo& to_compare);
        bool operator>(const Modulo& to_compare);
        bool operator<(const Modulo& to_compare);
    private:
        int number;
        int mod;
        int h;
        int f;

};
            Modulo operator""_mod(const char* str, size_t size);
#endif
