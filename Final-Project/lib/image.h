#include <stdio.h>
#include <stdlib.h>

#ifndef IMAGE_H
#define IMAGE_H

typedef struct  {
	int tipo;
	int c;
	int r;
	int mv;
	unsigned char *pData;
} pgm;

void readPGMImage(pgm*,char*);
void writePGMImage(pgm *, char *);

#endif