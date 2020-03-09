#include <stdio.h>
#include<stdlib.h>
//1
struct stackItem{
    char bukva;
    struct stackitem *ptr;
};
typedef struct stackItem StackItem;
typedef StackItem *StackPtr;
void addToStack(StackPtr *top,char bukva);
void printStack(StackPtr *top);
//2
struct treeItem{
    int broj;
    struct treeItem *ptrLeft;
    struct treeItem *ptrRight;
};
typedef struct treeItem TreeItem;
typedef TreeItem *TreePtr;
void addToTree(TreePtr *ptr,int broj);
void postOrder(TreePtr ptr);
void deleteFromTree(TreePtr *ptr,int broj);

int main()
{
//    StackPtr stPtr = NULL;
//    char zbor[20];
//    printf("vnesi zbor: ");
//    scanf("%s",zbor);
//    char *bukva = zbor;
//    while(*bukva != '\0'){
//        addToStack(&stPtr,*bukva);
//        *bukva++;
//    }
//    printStack(&stPtr);
    TreePtr treePtr = NULL;
    addToTree(&treePtr,10);
    addToTree(&treePtr,17);
    addToTree(&treePtr,5);
    addToTree(&treePtr,8);
    addToTree(&treePtr,9);
    addToTree(&treePtr,2);
    addToTree(&treePtr,14);
    addToTree(&treePtr,5);
    addToTree(&treePtr,19);
    addToTree(&treePtr,1);
    addToTree(&treePtr,6);
    addToTree(&treePtr,7);
    postOrder(treePtr);
    printf("\n");
    deleteFromTree(&treePtr,5);
    postOrder(treePtr);
    return 0;
}
//1
void addToStack(StackPtr *top,char bukva){
    StackPtr newPtr = malloc(sizeof (StackItem));
    newPtr->bukva = bukva;
        newPtr->ptr = NULL;
        newPtr->ptr=*top;
        *top = newPtr;
}
void printStack(StackPtr *top){
   StackPtr nextPtr = (*top)->ptr;
   if(*top != NULL){
       printf("%c",(*top)->bukva);
       printStack(&nextPtr);
   }
}
//2
void addToTree(TreePtr *ptr,int broj){
    if (*ptr == NULL){
    TreePtr newPtr = malloc(sizeof (TreeItem));
    newPtr->broj = broj;
    newPtr->ptrLeft = NULL;
    newPtr->ptrRight = NULL;
    *ptr = newPtr;
    }
    else{
        if ((*ptr)->broj>broj){
            addToTree(&((*ptr)->ptrLeft),broj);
        }
        else if ((*ptr)->broj<broj){
            addToTree(&((*ptr)->ptrRight),broj);
        }
        else{
            TreePtr newPtr = malloc(sizeof (TreeItem));
            newPtr->broj = broj;
            newPtr->ptrRight = NULL;
            newPtr->ptrLeft = (*ptr)->ptrLeft;
            (*ptr)->ptrLeft=newPtr;
        }
    }
}
void postOrder(TreePtr ptr){
    if (ptr != NULL){
        postOrder(ptr->ptrLeft);
        postOrder(ptr->ptrRight);
        printf("%d ",ptr->broj);
    }
}
void deleteFromTree(TreePtr *ptr,int broj){
    //printf("%d  %d --",(*ptr)->broj,(*ptr)->ptrLeft->broj);
    if((*ptr)->broj == broj){
        TreePtr temp =(*ptr)->ptrLeft;
        //if(temp->broj == broj){
          //  deleteFromTree(&temp,broj);
        //}

        *ptr = (*ptr)->ptrRight;
        TreePtr nextNode = (*ptr)->ptrLeft;
        while (nextNode->ptrLeft!=NULL){
            nextNode = nextNode->ptrLeft;
        }
        nextNode->ptrLeft = temp;
    }
    else if ((*ptr)->broj>broj)
        deleteFromTree(&((*ptr)->ptrLeft),broj);
    else
        deleteFromTree(&((*ptr)->ptrRight),broj);
}
