#ifndef PROFESOR_H
#define PROFESOR_H
#include "vraboten.h"

class Profesor:Vraboten
{
    char *zvanje;
    char *oblast;
    int brPredmeti;
public:
    Profesor(char *,char *,int,char *, char *,int);
    void postavi(char *,char *,int,char *, char *,int);
    void prikazi_podatoci();
};

#endif // PROFESOR_H
