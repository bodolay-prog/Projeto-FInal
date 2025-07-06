#include <stdio.h>
#include <stdlib.h>
#include "ops.h"

unsigned char* getLBP(unsigned char *img, unsigned N, unsigned M){

    /* mapping the center elements

    [i - M - 1]      [i - M]        [i - M + 1]
      [i - 1]          [i]            [i + 1]
    [i + M - 1]      [i + M]        [i + M + 1]
    
    */

    unsigned char *LBP = (unsigned char *)malloc(N * M * sizeof(unsigned char));
    if(!LBP) return NULL;

    for(int i = 0; i < N * M; i++){

        unsigned r = i / M;
        unsigned c = i % M;

        #define RAN(r, c) (((r) >= 0 && (r) < N && (c) >= 0 && (c) < M)    ?    *(img + (r) * M + (c))    :    0)                 //avoiding out of bounds write
        unsigned char binary = 0;

        //filling LBP[i]
        binary |= (RAN(r - 1, c - 1)     >= *(img + i)) << 7;
        binary |= (RAN(r - 1, c)         >= *(img + i)) << 6;
        binary |= (RAN(r - 1, c + 1)     >= *(img + i)) << 5;
        binary |= (RAN(r,     c + 1)     >= *(img + i)) << 4;
        binary |= (RAN(r + 1, c + 1)     >= *(img + i)) << 3;
        binary |= (RAN(r + 1, c)         >= *(img + i)) << 2;
        binary |= (RAN(r + 1, c - 1)     >= *(img + i)) << 1;
        binary |= (RAN(r,     c - 1)     >= *(img + i)) << 0;

        *(LBP + i) = binary;
    }

    return LBP;
}