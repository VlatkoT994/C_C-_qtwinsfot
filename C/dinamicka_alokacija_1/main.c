#include <stdio.h>
#include<stdlib.h>
//1
struct pole{
    int broj;
    char karakter;
    struct pole *nextElement;
};
typedef struct pole Pole;
typedef Pole *polePtr;
void pecatiListaNanazad(polePtr *start,polePtr *end);
void novElement(polePtr *start,int broj,char karakter);
void printajLista(polePtr *start);
//2
struct vtora{
    int broj;
    struct vtora *nextElement;
};
typedef struct vtora Vtora;
typedef Vtora *vtoraPok;
void vnesi(vtoraPok *start, int broj);
void sortOpagjacki(vtoraPok *start);
void sortRastecki(vtoraPok *start);
void pecati(vtoraPok *start);
void brisi(vtoraPok *start, int br);

int main()
{
    //1
    polePtr kraj = NULL;
    polePtr lista = NULL;
    //printf("%p %p",test,lista);
//    novElement(&lista,1,'A');
//    novElement(&lista,2,'A');
//    novElement(&lista,3,'A');
//    novElement(&lista,4,'A');
//    pecatiListaNanazad(&lista,&kraj);
    //2
    vtoraPok vtoraLista = NULL;
    vnesi(&vtoraLista,1);
    vnesi(&vtoraLista,2);
    vnesi(&vtoraLista,1);
    vnesi(&vtoraLista,3);
    vnesi(&vtoraLista,4);
    vnesi(&vtoraLista,5);
    vnesi(&vtoraLista,6);
    vnesi(&vtoraLista,7);
    pecati(&vtoraLista);
    sortOpagjacki(&vtoraLista);
    pecati(&vtoraLista);
    sortRastecki(&vtoraLista);
    pecati(&vtoraLista);
    brisi(&vtoraLista,1);
    pecati(&vtoraLista);

    return 0;
}
//1
void novElement(polePtr *start,int broj,char karakter){
    polePtr prevPointer = NULL;
    polePtr curPointer = *start;
    polePtr newElement = malloc(sizeof (Pole));
    newElement->broj = broj;
    newElement->karakter = karakter;
    newElement->nextElement = NULL;
    while(curPointer!=NULL){
        prevPointer = curPointer;
        curPointer = curPointer->nextElement;
    }
    if (prevPointer == NULL){
        *start = newElement;
    }
    else
        prevPointer->nextElement = newElement;
}
void pecatiListaNanazad(polePtr *start,polePtr *end){
    polePtr prevPointer = NULL;
    polePtr curPointer = *start;
    while((curPointer!=*end)){
        prevPointer = curPointer;
        curPointer = curPointer->nextElement;
    }
    if (prevPointer != NULL){
        printf("%d, %c\n",prevPointer->broj,prevPointer->karakter);
        pecatiListaNanazad(start,&prevPointer);
    }
}
void printajLista(polePtr *start){
    polePtr curPointer = *start;
    while(curPointer!=NULL){
        printf("%d, %c\n",curPointer->broj,curPointer->karakter);
        curPointer = curPointer->nextElement;
    }
}
// 2
void vnesi(vtoraPok *start, int broj){
    vtoraPok prevPointer = NULL;
    vtoraPok curPointer = *start;
    vtoraPok newElement = malloc(sizeof (Pole));
    newElement->broj = broj;
    newElement->nextElement = NULL;
    while(curPointer!=NULL){
        prevPointer = curPointer;
        curPointer = curPointer->nextElement;
    }
    if (prevPointer == NULL){
        *start = newElement;
    }
    else
        prevPointer->nextElement = newElement;
}
void sortOpagjacki(vtoraPok *start){
    int temp;
    int brojac = -1;
    vtoraPok prevPointer = *start;
    vtoraPok curPointer = prevPointer->nextElement;
    while(curPointer!=NULL){
        if (prevPointer->broj < curPointer->broj){
            temp = prevPointer->broj;
            prevPointer->broj = curPointer->broj;
            curPointer->broj = temp;
        }
        brojac++;
        prevPointer = curPointer;
        curPointer = curPointer->nextElement;

    }
    for (int i =0; i<brojac;i++)
    {
        prevPointer = *start;
        curPointer = prevPointer->nextElement;
        for (int j = 0; j<brojac-i;j++){
            if (prevPointer->broj < curPointer->broj){
                temp = prevPointer->broj;
                prevPointer->broj = curPointer->broj;
                curPointer->broj = temp;
            }
            prevPointer = curPointer;
            curPointer = curPointer->nextElement;
        }
    }
}
void sortRastecki(vtoraPok *start){
        int temp;
        int brojac = -1;
        vtoraPok prevPointer = *start;
        vtoraPok curPointer = prevPointer->nextElement;
        while(curPointer!=NULL){
            if (prevPointer->broj > curPointer->broj){
                temp = prevPointer->broj;
                prevPointer->broj = curPointer->broj;
                curPointer->broj = temp;
            }
            brojac++;
            prevPointer = curPointer;
            curPointer = curPointer->nextElement;

        }
        for (int i =0; i<brojac;i++)
        {
            prevPointer = *start;
            curPointer = prevPointer->nextElement;
            for (int j = 0; j<brojac-i;j++){
                if (prevPointer->broj > curPointer->broj){
                    temp = prevPointer->broj;
                    prevPointer->broj = curPointer->broj;
                    curPointer->broj = temp;
                }
                prevPointer = curPointer;
                curPointer = curPointer->nextElement;
            }
        }
}
void pecati(vtoraPok *start){
    vtoraPok curPointer = *start;
    while(curPointer!=NULL){
        printf("%d, ",curPointer->broj);
        curPointer = curPointer->nextElement;
    }
    printf("\n");
}
void brisi(vtoraPok *start,int br){
    vtoraPok temp;
    if((*start)->broj == br){
        temp = *start;
        *start = temp->nextElement;
        free(temp);
        brisi(start,br);
    }
    vtoraPok curPointer = *start;
    vtoraPok prevPointer = NULL;
    while(curPointer!=NULL){
        if (curPointer->broj == br){
            temp = curPointer;
            prevPointer->nextElement = curPointer->nextElement;
            curPointer = prevPointer->nextElement;
            free(temp);
        }
        else{
            prevPointer = curPointer;
            curPointer = curPointer->nextElement;
        }
    }
}
