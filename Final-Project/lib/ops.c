#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

typedef struct  {
	int tipo;
	int c;
	int r;
	int mv;
	unsigned char *pData;
} pgm;


unsigned char * doLBPImage(pgm p){

    unsigned char *LBP = (unsigned char *)malloc(p.r * p.c * sizeof(unsigned char));
    if(!LBP) return NULL;

    for(int i = 0; i < p.r * p.c; i++){

		unsigned r = i / p.r;
        unsigned c = i % p.c;

        #define RAN(r, c) (((r) >= 0 && (r) < p.r && (c) >= 0 && (c) < p.c)    ?    *(p.pData + (r) * p.c + (c))    :    0)                 //avoiding out of bounds write
        unsigned char binary = 0;

        //filling LBP[i]
        binary |= (RAN(r - 1, c - 1)     >= *(p.pData + i)) << 7;
        binary |= (RAN(r - 1, c)         >= *(p.pData + i)) << 6;
        binary |= (RAN(r - 1, c + 1)     >= *(p.pData + i)) << 5;
        binary |= (RAN(r,     c + 1)     >= *(p.pData + i)) << 4;
        binary |= (RAN(r + 1, c + 1)     >= *(p.pData + i)) << 3;
        binary |= (RAN(r + 1, c)         >= *(p.pData + i)) << 2;
        binary |= (RAN(r + 1, c - 1)     >= *(p.pData + i)) << 1;
        binary |= (RAN(r,     c - 1)     >= *(p.pData + i)) << 0;

        *(LBP + i) = binary;
    }

    return LBP;
}

void doNewFilename(char *filename,char *newfilename){

    int i;
    char finalname[] = "-lbp.pgm";

    for(i = 0; *(filename+i) = '.'; i++) *(newfilename + i) = *(filename + i);
    for(int k = i; k<strlen(finalname); k++) *(newfilename + k) = *(finalname + (k-i));


}