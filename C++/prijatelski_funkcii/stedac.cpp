#include"covek.h"
#include "stedac.h"

Stedac::Stedac(char *name,char *lastname,char *address,char *telephone,int bil,int kred)
    :lice(name,lastname,address,telephone){
    kredit = kred;
    bilans = bil;

}
