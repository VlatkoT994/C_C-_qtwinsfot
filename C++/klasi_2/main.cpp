#include <iostream>

#include "dropki.h"
using namespace std;

int main()
{
    Dropka a(2,3);
    Dropka b(1,4);
    Dropka zb,raz,pr,kol;
    zb.zbir(a,b);
    zb.printDropka();
    zb.printRealen();
    raz.razlika(a,b);
    raz.printDropka();
    raz.printRealen();
    pr.proizvod(a,b);
    pr.printDropka();
    pr.printRealen();
    kol.kolicnik(a,b);
    kol.printDropka();
    kol.printRealen();
    return 0;
}
