#ifndef SHAPE_H
#define SHAPE_H
#include<string>
#include<iostream>
using namespace std;
class Shape{
public:
    virtual ~Shape(){std::cout<<"shape destroyed"<<std::endl;}
    virtual double getArea() const {return 0;}
    virtual double getVolumen() const {return 0;}
    void virtual print() const =0;
    virtual std::string getName() const  = 0;
};

#endif // SHAPE_H
