#ifndef COMPLEX_H
#define COMPLEX_H
#include<iostream>
using namespace std;
#include<iomanip>

class Complex
{
    friend ostream &operator<<(ostream&,const Complex &);
    friend istream &operator>>(istream&,Complex &);
    friend Complex operator*(Complex,Complex);
    friend Complex operator*(double,Complex);
    friend Complex operator*(Complex,double);
    friend bool operator==(Complex,Complex);
    friend bool operator!=(Complex,Complex);
private:
    double real;
    double imaginary;
public:
    Complex();
    Complex(double);
    Complex(double,double);
    Complex operator+(Complex);
    Complex operator-(Complex);
    Complex &operator+=(Complex &);
    Complex &operator-=(Complex &);
    Complex &operator*=(Complex &);
    Complex &operator=(const Complex &);


};

#endif // COMPLEX_H
