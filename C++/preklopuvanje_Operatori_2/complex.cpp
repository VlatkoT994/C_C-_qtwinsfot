#include "complex.h"
#include<iostream>
using namespace std;
#include<iomanip>
#include <cstring>
Complex::Complex()
{
    real = 0;
    imaginary = 1;
}
Complex::Complex(double r)
{
    real = r;
    imaginary = 1;
}
Complex::Complex(double r,double i)
{
    real = r;
    imaginary = i;
}



ostream &operator<<(ostream &output,const Complex &broj){
    output<<broj.real<<" + i*"<< broj.imaginary<<endl;
    return output;
}
istream &operator>>(istream &input,Complex &broj){
    string userInput;
    string realen  {""};
    unsigned brojac = 0;
    char znak;
    input>>userInput;
    while(userInput.at(brojac)!=' '&& userInput.at(brojac)!='+'&&userInput.at(brojac)!='-'){
        realen+=userInput[brojac];
        brojac++;
    }
    broj.real = stod(realen);
    while(!isdigit(userInput[brojac])){
        if (userInput[brojac]=='+')
            znak = '+';
        else if (userInput[brojac]=='-')
            znak = '-';
        brojac++;
    }

    string imaginaren = userInput.substr(brojac,userInput.length()-brojac);
    if (znak == '-')
        broj.imaginary = 0-stod(imaginaren);
    else
        broj.imaginary = stod(imaginaren);
    return input;
}
Complex Complex::operator+(Complex vtor){
    return Complex(vtor.real+real,vtor.imaginary+imaginary);
}
Complex Complex::operator-(Complex vtor){
    return Complex(vtor.real-real,vtor.imaginary-imaginary);
}
Complex& Complex::operator=(const Complex &right){
    real = right.real;
    imaginary = right.imaginary;
    return *this;
}
Complex& Complex::operator+=(Complex &right){
    real = real + right.real;
    imaginary = imaginary + right.imaginary;
    return *this;
}
Complex& Complex::operator-=(Complex &right){
    real = real - right.real;
    imaginary = imaginary - right.imaginary;
    return *this;
}
Complex& Complex::operator*=(Complex &right){
    *this = *this * right;
    return *this;
}
Complex operator*(Complex prv,Complex vtor){
    Complex result;
    result.real = prv.real*vtor.real - prv.imaginary*vtor.imaginary;
    result.imaginary = prv.real*vtor.imaginary + prv.imaginary*vtor.real;
    return result;
}
Complex operator*(double dou,Complex comp){
    Complex result;
    result.real = dou*comp.real;
    result.imaginary = dou*comp.imaginary;
    return result;
}
Complex operator*(Complex comp,double dou){
    Complex result;
    result.real = dou*comp.real;
    result.imaginary = dou*comp.imaginary;
    return result;
}
bool operator==(Complex first,Complex second){
    return (first.real == second.real) && (first.imaginary) == (second.imaginary);
}
bool operator!=(Complex first, Complex second){
    return (first.real != second.real)||(first.imaginary != second.imaginary);
}
