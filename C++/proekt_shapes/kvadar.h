#ifndef KVADAR_H
#define KVADAR_H
#include "troDimenzionalna.h"
#include "pravoagolnik.h"

class Kvadar:TroDimenzionalna
{
    Pravoagolnik osnova;
public:
    Kvadar(double,double,double);
    Kvadar(const Pravoagolnik&,double);
    Kvadar(const Kvadar&);
    ~Kvadar(){cout<<"kvadar unisten"<<endl;}
    double getSirina() const;
    double getDolzina() const;
    double getVisina() const;
    double getVolumen() const;
    double getArea() const;
    string getName() const;
    void print() const;
    void setSirina(double);
    void setDolzina(double);
    void setVisina(double);
};

#endif // KVADAR_H
