#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

#include "image.h"


void allocMemStruct(pgm **lbp,int qtd){

    (*lbp) = (pgm *) malloc(qtd * sizeof(pgm));
    if(!(*lbp)){

        puts("\n allocMemStruct() says: Error at memory allocation\n");
        exit(2);

    }
}

void allocMemVector(unsigned char **v, int qtd){

    
    *v = (unsigned char*)calloc(qtd, sizeof(unsigned char));
    if(!(*v)){

        perror("\n allocMemVector() says: Error at memory allocation\n");
        exit(4);
    }
}

