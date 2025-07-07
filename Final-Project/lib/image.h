#include <stdio.h>
#include <stdlib.h>

typedef struct  {
	int tipo;
	int c;
	int r;
	int mv;
	unsigned char *pData;
} pgm;

void readPGMImage(pgm*,char*);
void writePGMImage(pgm *, char *);
