#include "cilindar.h"

Cilindar::Cilindar(double x, double y,double rad,double vis):osnova(x,y,rad){
    visina = vis;
}
Cilindar::Cilindar(const Krug& os,double vis):osnova(os){
    visina = vis;
}
Cilindar::Cilindar(const Cilindar& dodeluva):osnova(dodeluva.getX(),dodeluva.getY(),dodeluva.getRadius()){
    visina = dodeluva.getVisina();
}
double Cilindar::getX() const{return osnova.getX();}
double Cilindar::getY() const{return osnova.getY();}
double Cilindar::getRadius() const{return osnova.getRadius();}
double Cilindar::getVisina() const{return visina;}
double Cilindar::getVolumen() const{return osnova.getArea()*visina;}
double Cilindar::getArea() const
{
    return (2*osnova.getArea()+osnova.getObikolka()*visina);
}
string Cilindar::getName() const{return "cilindar";}
void Cilindar::print() const{
    cout<<"Cilindar: "<<endl;
    osnova.print();
    cout<<"visina "<<visina<<endl;
    cout<<"plostina "<<getArea()<<" volumen "<<getVolumen()<<endl;
}
void Cilindar::setX(double x){osnova.setX(x);}
void Cilindar::setY(double y){osnova.setY(y);}
void Cilindar::setRadius(double rad){osnova.setRadius(rad);}
void Cilindar::setVisina(double vis){visina = vis;}
