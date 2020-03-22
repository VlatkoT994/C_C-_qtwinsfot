#include "kvadar.h"

Kvadar::Kvadar(double dol,double sir,double vis):osnova(dol,sir){
    visina = vis;
}
Kvadar::Kvadar(const Pravoagolnik& os,double vis):osnova(os){
    visina = vis;
}
Kvadar::Kvadar(const Kvadar &dodeluva):osnova(dodeluva.getSirina(),dodeluva.getDolzina()){
    visina = dodeluva.getVisina();
}
double Kvadar::getSirina() const{return osnova.getSirina();}
double Kvadar::getDolzina() const{return osnova.getDolzina();}
double Kvadar::getVisina() const{return visina;}
double Kvadar::getVolumen() const{return osnova.getArea()*visina;}
double Kvadar::getArea() const{return osnova.getObikolka()*visina+osnova.getArea();}
string Kvadar::getName() const{return "kvadar";}
void Kvadar::print() const{
    cout<<"Kvadar: "<<endl;
    cout<<"Osnova: "<<endl;
    osnova.print();
    cout<<"visina "<<visina<<endl;
    cout<<"plostina "<<getArea()<<" volumen "<<getVolumen()<<endl;
}
void Kvadar::setSirina(double sir){osnova.setSirina(sir);}
void Kvadar::setDolzina(double dol){osnova.setDolzina(dol);}
void Kvadar::setVisina(double vis){visina = vis;}
