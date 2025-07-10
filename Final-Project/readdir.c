/*
 * C Program to List Files in Directory
	https://www.sanfoundry.com/c-program-list-files-directory/
 */
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include "./lib/ops.h"
#include "./lib/memory.h"
#include "./lib/file.h"

int main(void)
{
    pgm *lbp;
    DIR *d;
    char *name;
    char filepath[512];
    unsigned char *histogram = NULL;
    struct dirent *dir;
    d = opendir("./input-tests");
    if (d)
    {

        while ((dir = readdir(d)) != NULL)
        {
           if(dir->d_name[0] == '.') continue; //remove o . e .. da leitura

            allocMemStruct(&lbp,1); // aloca a memoria pra uma struct
            printf("%s\n", dir->d_name);// deixei pq tava la
            snprintf(filepath, sizeof(filepath), "./input-tests/%s", dir->d_name);// faz a rota onde ta o arquivo na pasta inputs-tests
            readPGMImage(lbp,filepath);// le a imagem
            allocMemVector(&histogram,(lbp->mv+2)); // + 2, por causa do que tem que ser 0 a 255 o que seria histogram[256] e no final ter o 0 ou 1, ou seja, historgram[257] que vai de 0 - 256 posições
             
            lbp->pData = doLBPImage(lbp);// faz o lbp e armazena no dados da strutc
            doHistogram(lbp,dir->d_name,histogram); // faz o histograma

            snprintf(filepath, sizeof(filepath), "./output-tests/%s", dir->d_name);// so pra teste
            writePGMImage(lbp,filepath);// so pra teste

            free(lbp->pData);           // Esse é alocado automatico quando le a imagem
            free(lbp);                  // Libera as Memorias pra não ter vazamento
            free(histogram);            //
            

						// Processar - Medir o tempo apenas nesta etapa.
						
						// Saída.
        }

        
        closedir(d);
    }
    return(0);
}		