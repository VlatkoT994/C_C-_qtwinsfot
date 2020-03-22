#ifndef CILINDAR_H
#define CILINDAR_H
#include "troDimenzionalna.h"
#include "krug.h"

class Cilindar: public TroDimenzionalna
{
    Krug osnova;
public:
    Cilindar(double, double,double,double);
    Cilindar(const Krug&,double);
    Cilindar(const Cilindar&);
    ~Cilindar(){cout<<"Cilindar unisten"<<endl;}
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

#endif // CILINDAR_H
