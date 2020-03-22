#ifndef TRIAGOLNIK_H
#define TRIAGOLNIK_H
#include "dvoDimenzionalna.h"

class Triagolnik: public DvoDimenzionalna
{
    double a;
    double b;
    double c;
public:
    Triagolnik(double,double,double);
    Triagolnik(const Triagolnik &);
    ~Triagolnik(){cout<<"triagolnik destroyed"<<endl;}
    double getA() const;
    double getB() const;
    double getC() const;
    double getArea() const;
    double getObikolka() const;
    void print() const;
    string getName() const;
    void setA(double);
    void setB(double);
    void setC(double);

};

#endif // TRIAGOLNIK_H
