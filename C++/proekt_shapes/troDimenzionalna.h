#ifndef TRODIMENZIONALNA_H
#define TRODIMENZIONALNA_H
#include "shape.h"
#include "dvoDimenzionalna.h"
class TroDimenzionalna:public Shape{
protected:
    double visina;
public:
    ~TroDimenzionalna(){std::cout<<"trdimenzionalna destroyed"<<std::endl;}
    virtual void print() const =0;
    virtual std::string getName() const {return "trodimenzionalna forma";}
    virtual double getArea() const {return 0.0;}
    virtual double getVolumen() const {return 0.0;}
};

#endif // TRODIMENZIONALNA_H
