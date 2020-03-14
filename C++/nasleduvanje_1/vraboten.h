#ifndef VRABOTEN_H
#define VRABOTEN_H


class Vraboten
{
    char *ime;
    char *prezime;
    int godinaNaVrabotuvanje;
public:
    Vraboten(char *,char *,int);
    void postavi(char *,char *,int);
    void prikazi_podatoci();
};

#endif // VRABOTEN_H
