#ifndef PRAVOAGOLNIK_H
#define PRAVOAGOLNIK_H
#include "dvoDimenzionalna.h"

class Pravoagolnik:public DvoDimenzionalna
{
    double dolzina;
    double sirina;
public:
    Pravoagolnik(double, double);
    Pravoagolnik(const Pravoagolnik&);
    ~Pravoagolnik(){cout<<"pravoagolnik destroyed"<<endl;}
    double getDolzina() const;
    double getSirina() const;
    double getArea() const;
    double getObikolka() const;
    void setSirina(double);
    void setDolzina(double);
    string getName();
    void print() const;
};

#endif // PRAVOAGOLNIK_H
