#include "pravoagolnik.h"

Pravoagolnik::Pravoagolnik(double dol,double sir)
{
    dolzina = dol;
    sirina = sir;
}
Pravoagolnik::Pravoagolnik(const Pravoagolnik &dodeluva){
    dolzina = dodeluva.getDolzina();
    sirina = dodeluva.getSirina();
}
double Pravoagolnik::getArea() const{return sirina*dolzina;}
double Pravoagolnik::getObikolka() const{return 2*(sirina+dolzina);}
double Pravoagolnik::getSirina() const{return sirina;}
double Pravoagolnik::getDolzina() const{return dolzina;}
void Pravoagolnik::setDolzina(double dol){dolzina = dol;}
void Pravoagolnik::setSirina(double sir){sirina = sir;}
void Pravoagolnik::print() const{
    cout<<"Pravoagolnik :"<<endl;
    cout<<"dolzina "<<dolzina<<" sirina "<<sirina<<endl;
    cout<<"obikolka "<<getObikolka()<<"plostina "<<getArea()<<endl;
}
string Pravoagolnik::getName(){return "pravoagolnik";}
