/*
 * C Program to List Files in Directory
	https://www.sanfoundry.com/c-program-list-files-directory/
 */

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

#include "../src/image.h"
#include "../src/ops.h"
#include "../src/memory.h"
#include "../src/file.h"
#include "../time/dotime.h"


int main(){

    pgm *lbp;
    DIR *d;
    //char *name;
    char filepath[512]; // 2 * 256 pois o nome do arquivo que pode ser maior que 256 (e o tamanho do caminho que é 256) então 512 o tamanho maximo é: caminho + nome do arquivo
    unsigned char *histogram = NULL;
    struct dirent *dir;

    d = opendir("input");
    if (d){

        
        while ((dir = readdir(d)) != NULL){

           if(dir->d_name[0] == '.') continue; //remove o . e .. da leitura

            allocMemStruct(&lbp, 1);                                                                        //aloca a memoria da struct da imagem atual

            printf("%s\n", dir->d_name);// deixei pq tava la
            snprintf(filepath, sizeof(filepath), "../input/%s", dir->d_name);                               // faz a rota de onde está o arquivo na pasta 'inputs'
            readPGMImage(lbp,filepath);                                                                     // abstraindo a imagem

            allocMemVector(&histogram,(lbp->mv+2)); // + 2, por causa do que tem que ser 0 a 255 o que seria histogram[256] e no final ter o 0 ou 1, ou seja, historgram[257] que vai de 0 - 256 posições
                                                    // o allocMemVector tem calloc então ele sempre zera por segurança
            lbp->pData = doLBPImage(lbp);                                                                   // faz o lbp e armazena no dados da strutc
            doHistogram(lbp,dir->d_name,histogram); // faz o histograma

            snprintf(filepath, sizeof(filepath), "output/%s", dir->d_name);                                 // so pra teste
            writePGMImage(lbp,filepath);                                                                    // so pra teste

            //liberação de memória
            free(lbp->pData);
            free(lbp);
            free(histogram);
            
			dotime();// Processar - Medir o tempo apenas nesta etapa.
						
			// Saída.
        }  
        closedir(d);
    }

    return(0);
}