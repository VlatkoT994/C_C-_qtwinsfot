#ifndef DEMONSTRATOR_H
#define DEMONSTRATOR_H
#include "vraboten.h"

class Demonstrator:Vraboten
{
    char *startRabota;
    char *krajRabota;
public:
    Demonstrator(char *,char *,int,char *, char *);
    void postavi(char *,char *,int,char *, char *);
    void prikazi_podatoci();
};


#endif // DEMONSTRATOR_H
