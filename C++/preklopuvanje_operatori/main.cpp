#include <iostream>
#include "dropka.h"
using namespace std;

int main()
{
    Dropka prva(2,3), vtora(1,8),treta(4,6),cetvrta(2,9);
    (prva + treta).printDropka();
    (vtora + 3).printRealen();
    (prva - cetvrta).printRealen();
    (treta - 2).printDropka();
    (vtora*treta).printDropka();
    (prva*2).printRealen();
    (cetvrta/vtora).printRealen();
    (cetvrta/1).printDropka();

    return 0;
}
