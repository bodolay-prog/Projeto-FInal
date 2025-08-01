#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#include "image.h"

int countImages(const char *directory){

	//opening 'input/'
	DIR *d;

	d = opendir(directory);
	if(!d){

		perror("countImages() says: Cannot count the quantity of images in 'input'\n");
		exit(1);
	}


	//running the directory
	struct dirent *run;
	int counter = 0;

	while((run = readdir(d)) != NULL) if(strstr(run->d_name, ".pgm") != NULL) counter++;						//if(dir->d_name ==  '.') continue;


	closedir(d);
	return counter;
}

void readPGMImage(pgm *pio, char *filename){

	FILE *fp;
	char ch;

	if (!(fp = fopen(filename, "rb"))){
		perror("Erro.");
		exit(1);
	}

	if ((ch = getc(fp))!='P'){
		puts("A imagem fornecida não está no formato pgm");
		exit(2);
	}
	
	pio->tipo = getc(fp)-48;
	
	fseek(fp, 1, SEEK_CUR);

	while((ch=getc(fp))=='#'){
		while( (ch=getc(fp))!='\n');
	}

	fseek(fp,-1, SEEK_CUR);

	fscanf(fp, "%d %d",&pio->c,&pio->r);
	if (ferror(fp)){ 
		perror(NULL);
		exit(3);
	}	
	fscanf(fp, "%d",&pio->mv);
	fseek(fp,1, SEEK_CUR);

	pio->pData = (unsigned char*) malloc(pio->r * pio->c * sizeof(unsigned char));

	switch(pio->tipo){
		case 2:
			puts("Lendo imagem PGM (dados em texto)");
			for (int k=0; k < (pio->r * pio->c); k++){
				fscanf(fp, "%hhu", pio->pData+k);
			}
		break;
		
		case 5:
			puts("Lendo imagem PGM (dados em binário)");
			fread(pio->pData,sizeof(unsigned char), pio->r * pio->c, fp);
		break;
		default:
			puts("Não está implementado");
	}
	
	fclose(fp);
}