#include <iostream>
#include <vector>
#include "kvadar.h"
#include "cilindar.h"
#include "konus.h"
#include "triagolnik.h"
using namespace std;

int main()
{
    Krug *krug = new Krug(2,4,10);
    Krug *krug2 = new Krug(*krug);
    krug2->print();
    krug->print();
    Cilindar cil(*krug2,20);
    cil.print();
    cil.setX(10);
    cil.print();
    Konus *kon = new Konus(2,2,5,1);
    kon->print();
    kon->setVisina(12);
    kon->print();
    Triagolnik tri(2,3,4);
    tri.print();
    delete kon;
}
