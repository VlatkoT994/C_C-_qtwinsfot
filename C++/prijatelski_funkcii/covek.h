#ifndef COVEK_H
#define COVEK_H

class Covek
{
    char ime[20];
    char prezime[20];
    char adresa[50];
    char telefon[15];
public:
    Covek(char *,char *, char *, char *);
    void print();
};

#endif // COVEK_H
