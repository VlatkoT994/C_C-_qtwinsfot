#include "triagolnik.h"
#include<cmath>
Triagolnik::Triagolnik(double first,double second,double third)
{
    a = first;
    b = second;
    c = third;
}
Triagolnik::Triagolnik(const Triagolnik &dodeluva){
    a = dodeluva.getA();
    b = dodeluva.getB();
    c = dodeluva.getC();
}
double Triagolnik::getA() const{return a;}
double Triagolnik::getB() const{return b;}
double Triagolnik::getC() const{return c;}
double Triagolnik::getArea() const{
    double p = getObikolka()/2;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}
double Triagolnik::getObikolka() const{return a+b+c;}
void Triagolnik::print() const{
    cout<<"Triagolnik: "<<endl;
    cout<<"a "<<a<<"b "<<b<<"c "<<c<<endl;
    cout<<"obikolka "<<getObikolka()<<"plostina "<<getArea()<<endl;
}
string Triagolnik::getName() const{return "triagolnik";}
void Triagolnik::setA(double nova){a = nova;}
void Triagolnik::setB(double nova){b = nova;}
void Triagolnik::setC(double nova){c = nova;}
