#ifndef STEDAC_H
#define STEDAC_H
#include "covek.h"

class Stedac
{
    Covek lice;
    int bilans;
    int kredit;
public:
    Stedac(char *,char *,char *,char *,int,int);
    static double kamatnaStapka;
    static int brojStedaci;
};

#endif // STEDAC_H
