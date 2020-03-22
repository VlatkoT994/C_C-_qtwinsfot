#include "krug.h"

Krug::Krug(double x,double y,double rad)
{
    X = x;
    Y = y;
    radius = rad;
}
Krug::Krug(const Krug &dodeluva){
    X = dodeluva.getX();
    Y = dodeluva.getY();
    radius = dodeluva.getRadius();
}
double Krug::getX() const {return X;}
double Krug::getY() const {return Y;}
double Krug::getRadius() const {return radius;}
double Krug::getDiam() const {return 2*radius;}
double Krug::getArea() const {return radius*radius*PI;}
double Krug::getObikolka() const {return getDiam()*PI;}
void Krug::setX(double x){X = x;}
void Krug::setY(double y){Y = y;}
void Krug::setRadius(double rad){radius = rad;}
std::string Krug::getName() const{return "Krug";}
void Krug::print() const {
    cout<<"Krug: "<<endl;
    cout<<"centar ["<<X<<','<<Y<<']'<<" radius "<<radius<<endl;
    cout<<"plostina "<<getArea()<<" obikolka "<<getObikolka()<<endl;
}
