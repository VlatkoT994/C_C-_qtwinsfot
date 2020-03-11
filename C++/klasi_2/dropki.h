#ifndef DROPKI_H
#define DROPKI_H

class Dropka{
    int delenik;
    int delitel;
public:
    Dropka(int = 1,int = 1);
    int nzs(int,int);
    int nzd(int,int);
    int getDelitel();
    int getDelenik();
    void reduciraj();
    void zbir(Dropka,Dropka);
    void razlika(Dropka,Dropka);
    void proizvod(Dropka,Dropka);
    void kolicnik(Dropka,Dropka);
    void printDropka();
    void printRealen();

};

#endif // DROPKI_H
