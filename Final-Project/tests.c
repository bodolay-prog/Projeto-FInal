#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

typedef struct  {
	int tipo;
	int c;
	int r;
	int mv;
	unsigned char *pData;
} pgm;

void readPGMImage(pgm*,char*);
unsigned char * doLBPImage(pgm);
void writePGMImage(pgm *, char *);

int main(int argc, char *argv[]){

	 pgm lbp;
	 
	if (argc!=3){
		printf("Formato: \n\t %s <imagemEntrada.pgm> <imagemSaida.pgm>\n",argv[0]);
		exit(1);
	}

	//(*( h + *(lbp.pdata + i))) ++;
	// escolpo histograma
	readPGMImage(&lbp,argv[1]); // pegar nome automatico
	lbp.pData = doLBPImage(lbp);
	writePGMImage(&lbp,argv[2]); // escrava nome automitico, não temque gerar saída, mas aqui so vai ta pra testes
	//testar fazer com um diretorio intiero (ler.c)
	//fazer funcao histograma 
	//funcao que pega o primeiro nome do arquivo identifica se e 0 ou 1 e coloca no final do texto no arquivo csv
	//testar fazer com um diretorio intiero (ler.c)

	return 0;

}

void readPGMImage(pgm *pio,char *filename){

	FILE *fp;
	char ch;

	if (!(fp = fopen(filename,"r"))){
		perror("Erro.");
		exit(1);
	}

	if ( (ch = getc(fp))!='P'){
		puts("A imagem fornecida não está no formato pgm");
		exit(2);
	}
	
	pio->tipo = getc(fp)-48;
	
	fseek(fp,1, SEEK_CUR);

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
			fread(pio->pData,sizeof(unsigned char),pio->r * pio->c, fp);
		break;
		default:
			puts("Não está implementado");
	}
	
	fclose(fp);

}

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

void writePGMImage(pgm *pio, char *filename){
	FILE *fp;
	char ch;


	if (!(fp = fopen(filename,"wb"))){
		perror("Erro.");
		exit(1);
	}


	fprintf(fp, "%s\n","P5");
	fprintf(fp, "%d %d\n",pio->c, pio->r);
	fprintf(fp, "%d\n", 255);


	fwrite(pio->pData, sizeof(unsigned char),pio->c * pio->r, fp);


	fclose(fp);


}


