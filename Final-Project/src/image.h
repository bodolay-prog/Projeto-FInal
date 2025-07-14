#ifndef IMAGE_H
#define IMAGE_H

typedef struct{
	
	int tipo;
	int c;
	int r;
	int mv;
	unsigned char *pData;
} pgm;

//readPGMImage(lbp, filepath);
int countImages(const char *);
void readPGMImage(pgm *,char *);

#endif