#include "konus.h"
#include<cmath>
Konus::Konus(double x, double y,double rad,double vis):osnova(x,y,rad){
    visina = vis;
}
Konus::Konus(const Krug& os,double vis):osnova(os){
    visina = vis;
}
Konus::Konus(const Konus& dodeluva):osnova(dodeluva.getX(),dodeluva.getY(),dodeluva.getRadius()){
    visina = dodeluva.getVisina();
}
double Konus::getX() const{return osnova.getX();}
double Konus::getY() const{return osnova.getY();}
double Konus::getRadius() const{return osnova.getRadius();}
double Konus::getVisina() const{return visina;}
double Konus::getVolumen() const{return (osnova.getArea()*visina)/3;}
double Konus::getArea() const
{
    double s = sqrt(osnova.getRadius()*osnova.getRadius()+visina*visina);
    return osnova.getArea()+3.14159265*osnova.getRadius()*s;
}
string Konus::getName() const{return "konus";}
void Konus::print() const{
    cout<<"Konus: "<<endl;
    cout<<"Osnova: "<<endl;
    osnova.print();
    cout<<"visina "<<visina<<endl;
    cout<<"plostina "<<getArea()<<" volumen "<<getVolumen()<<endl;
}
void Konus::setX(double x){osnova.setX(x);}
void Konus::setY(double y){osnova.setY(y);}
void Konus::setRadius(double rad){osnova.setRadius(rad);}
void Konus::setVisina(double vis){visina = vis;}
