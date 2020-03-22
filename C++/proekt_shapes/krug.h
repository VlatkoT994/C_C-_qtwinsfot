#ifndef KRUG_H
#define KRUG_H
#include "dvoDimenzionalna.h"

class Krug:public DvoDimenzionalna
{
    double PI = 3.14159265;
    double radius;
    double X;
    double Y;
public:
     Krug(double,double,double);
     Krug(const Krug&);
    ~Krug(){std::cout<<"krug destroyed"<<std::endl;}
    double getRadius() const;
    double getX() const;
    double getY() const;
    void setX(double);
    void setY(double);
    void setRadius(double);
    double getDiam() const;
    void print() const;
    std::string getName() const;
    double getArea() const;
    double getObikolka() const;

};

#endif // KRUG_H
