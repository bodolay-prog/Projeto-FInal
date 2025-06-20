#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ops.h"

int* generation(unsigned L, unsigned C){

    srand(time(NULL));
    int *p = malloc(L * C * sizeof(int));
    if(!p) return NULL;
    
    for(unsigned i = 0; i < L * C; i++) *(p + i) = rand() % 256;
    return p;
}

void saveMatrix(const char *file, int *matrix, unsigned L, unsigned C){

    FILE *f = fopen(file, "w");
    if(!f){

        perror("File opening error! (saveMatrix)\n");
        return;
    }

    for(unsigned i = 0; i < L * C; i++) {
        
        if(!(i % C)) fprintf(f, "\n");
        fprintf(f, "%d\t", *(matrix + i));
    }

    fclose(f);
}

int* loadMatrix(const char *file, int *M, unsigned *L, unsigned *C){

    FILE *f = fopen(file, "r");
    if (!f) return NULL;

    for(int a = 0; a < (*L) * (*C); a++) fscanf(f, "%d", M + a);
    
    fclose(f);
    return M;
}

int* getLBP(int *M, unsigned L, unsigned C){

    /* mapping the center elements

    [i - C - 1]      [i - C]        [i - C + 1]
      [i - 1]          [i]            [i + 1]
    [i + C - 1]      [i + C]        [i + C + 1]
    
    */

    int *LBP = (int*)malloc(L * C * sizeof(int));
    if(!LBP) return NULL;

    for(int i = 0; i < L * C; i++){


        unsigned r = i / C;
        unsigned c = i % C;

        #define RAN(r, c) (((r) >= 0 && (r) < L && (c) >= 0 && (c) < C) ? *(M + (r) * C + (c)) : 0)                 //avoiding out of bounds write
        unsigned char binary = 0;

        //filling LBP[i]
        binary |= (RAN(r - 1, c - 1)     >= *(M + i)) << 7;
        binary |= (RAN(r - 1, c)         >= *(M + i)) << 6;
        binary |= (RAN(r - 1, c + 1)     >= *(M + i)) << 5;
        binary |= (RAN(r,     c + 1)     >= *(M + i)) << 4;
        binary |= (RAN(r + 1, c + 1)     >= *(M + i)) << 3;
        binary |= (RAN(r + 1, c)         >= *(M + i)) << 2;
        binary |= (RAN(r + 1, c - 1)     >= *(M + i)) << 1;
        binary |= (RAN(r,     c - 1)     >= *(M + i)) << 0;

        *(LBP + i) = binary;
    }

    return LBP;
}

void writeMatrix(const char *file, int *LBP, unsigned L, unsigned C){

    FILE *f = fopen(file, "w");
    

    for(int i = 0; i < L * C; i++){

        if(!(i % C)) fprintf(f, "\n");
        fprintf(f, "%d\t", *(LBP + i));
    }

    fclose(f);
}
