#ifndef DROPKA_H
#define DROPKA_H


class Dropka
{
    int delenik;
    int delitel;
public:
    Dropka();
    Dropka(int, int);
    Dropka(int);
    void printDropka();
    void printRealen();
    Dropka operator+(Dropka dropka);
    Dropka operator-(Dropka dropka);
    Dropka operator*(Dropka dropka);
    Dropka operator/(Dropka dropka);
    Dropka operator+(int);
    Dropka operator-(int);
    Dropka operator*(int);
    Dropka operator/(int);
    int getDelenik();
    int getDelitel();
    void reduciraj();
    int static getNzd(int,int);
    int static getNzs(int,int);
};

#endif // DROPKA_H
