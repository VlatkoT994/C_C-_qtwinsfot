#ifndef KONUS_H
#define KONUS_H
#include "troDimenzionalna.h"
#include "krug.h"

class Konus:public TroDimenzionalna
{
    Krug osnova;
public:
    Konus(double, double,double,double);
    Konus(const Krug&,double);
    Konus(const Konus&);
    ~Konus(){cout<<"konus unisten"<<endl;}
    double getX() const;
    double getY() const;
    double getRadius() const;
    double getVisina() const;
    double getVolumen() const;
    double getArea() const;
    string getName() const;
    void print() const;
    void setX(double);
    void setY(double);
    void setRadius(double);
    void setVisina(double);
};

#endif // KONUS_H
