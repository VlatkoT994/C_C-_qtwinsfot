#ifndef ASISTENT_H
#define ASISTENT_H
#include"vraboten.h"

class Asistent:Vraboten
{
    char *zvanje;
    char *mentor;
    int brPredmeti;
public:
    Asistent(char *,char *,int,char *, char *,int);
    void postavi(char *,char *,int,char *, char *,int);
    void prikazi_podatoci();
};

#endif // ASISTENT_H
