#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include "image.h"


void allocMemVector(unsigned char **v,int qtd){

    *v = (unsigned char*)calloc(qtd,sizeof(unsigned char));
    if(!(*v)){

        puts("Error at memory allocation");
        exit(4);

    }
}

void allocMemStruct(pgm **lbp,int qtd){

    (*lbp) = (pgm*) malloc(sizeof(pgm)*qtd);
    if(!(*lbp)){

        puts("Error at memory allocation");
        exit(2);

    }

}

void allocMemPdata(pgm **lbp){

        (*lbp)->pData = (unsigned char*)calloc(((*lbp)->r * (*lbp)->c ),sizeof(unsigned char));
        if(!((*lbp)->pData)){

            puts("Error at memory allocation");
            exit(2);

        }    

}