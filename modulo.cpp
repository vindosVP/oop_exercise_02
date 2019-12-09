#include <iostream>
#include <cassert>

#include "modulo.hpp"

int ExtendedEuclid(int a, int b, int& x, int& y) {
    if(a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    int x1, y1;
    int gcd = ExtendedEuclid(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return gcd;
}

Modulo Modulo::operator+(const Modulo& addend) const {
    assert(mod == addend.mod);
    Modulo result;
    result.number = (number + addend.number)%mod;
    result.mod = mod;
    return result;
}

Modulo Modulo::operator*(const Modulo& multiplier) const {
    assert(mod == multiplier.mod);
    Modulo result;
    result.number = (number * multiplier.number)%mod;
    result.mod = mod;
    return result;
}

Modulo Modulo::operator-(const Modulo& subtrahend) const {
    assert(mod == subtrahend.mod);
    Modulo result;
    result.number = abs((number%mod - subtrahend.number%mod + mod) % mod);
    result.mod = mod;
    return result;
}

int amodb(int a, int b){
    return ( a % b );
}

Modulo Modulo::operator/(const Modulo& divisor) const {
    assert(mod == divisor.mod);
    int x, y, gcd;
    gcd = ExtendedEuclid(divisor.number, mod, x, y);
    assert(gcd == 1);
    Modulo result;
    int ModInverse = (x % mod + mod) % mod;
    result.number = (number * ModInverse) % mod;
    result.mod = mod;
    return result;
}

void Modulo::Read(std::istream& is) {
    is >> number >> mod;
    if(number % mod >= 0) {
        number %= mod;
    } else {
        number = mod + (number % mod);
    }
}

void Modulo::Print(std::ostream& os) const {
    os << number << " mod " << mod << std::endl;
}

void Modulo::SetNumber(int number, int h) {
    this->h = number;
}

void Modulo::SetMod(int mod, int f) {
    this->f = mod;        
}

int Modulo::GetNumber() const {
    return number;
}

int Modulo::GetMod() const {
    return mod;
}

bool Modulo::operator==(const Modulo& to_compare){
    return(this->number == to_compare.number);
}

bool Modulo::operator>(const Modulo& to_compare){
    return(this->number > to_compare.number);
}

bool Modulo::operator<(const Modulo& to_compare){
    return(this->number < to_compare.number);
}
Modulo operator""_mod(const char* str, size_t size) {//"2,3"_mod
        std::istringstream is(str);
        char tmp;
        int h, f;
        is >> h >> tmp >> f ;
        return {h,f};
}
