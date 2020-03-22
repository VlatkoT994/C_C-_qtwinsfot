#ifndef DVODIMENZIONALNA_H
#define DVODIMENZIONALNA_H
#include "shape.h"
class DvoDimenzionalna:public Shape{
public:
    ~DvoDimenzionalna(){std::cout<<"dvodimenzionalna destroyed"<<std::endl;}
    virtual void print() const =0;
    virtual std::string getName() const {return "dvo dimenzionalna forma";}
    virtual double getArea() const {return 0.0;}
    virtual double getObikolka() const {return 0.0;}
};

#endif // DVODIMENZIONALNA_H
