#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

#include "../src/image.h"
#include "../src/ops.h"
#include "../src/memory.h"
#include "../src/csv.h"


void mainProcess(){

    pgm *lbp;
    char filepath[512];
    struct dirent *dir;


    //Ponteiro de alocação do vetor do histograma
    unsigned char *histogram = NULL;
    allocMemVector(&histogram, 257);                        //lbp->(mv + 2), valor máximo + classe + segurança

    //Ponteiro de abertura do arquivo .csv (generateCSV)
    FILE *csvPointer = fopen("output/out.csv", "w");
    if (!csvPointer){

        perror("Erro ao abrir output/out.csv");
        exit(1);
    }

    DIR *d;
    d = opendir("imageset-exs");
    if(d){
        while ((dir = readdir(d)) != NULL){
            if (dir->d_name[0] == '.') continue;                                                                    //Ignora . e ..
            
            allocMemStruct(&lbp, 1);                                                                                //Aloca a memória para a imagem

            //Cria o caminho completo para o arquivo de imagem e a abstrai
            snprintf(filepath, sizeof(filepath), "imageset-exs/%s", dir->d_name);
            readPGMImage(lbp, filepath);                                                                            //Lê e abstrai imagem

            //Processa LBP
            printf("Computando: %s\n",dir->d_name);
            lbp->pData = doLBPImage(lbp);

            //Processa o histograma
            doHistogram(lbp, dir->d_name, histogram);

            //Salva o histograma atual em um .csv
            generateCSV(lbp, filepath, histogram, csvPointer);

            printf("Classe desse arquivo: %d\n\n", *(histogram + lbp->mv + 1));

            free(lbp->pData);
            free(lbp);
        }

        closedir(d);  // Fecha o diretório

    } else perror("Erro ao abrir o diretório");

    //Liberação de memória
    fclose(csvPointer);
    free(histogram);
}


/*

struct dirent {
    ino_t d_ino;                // Número do inode do arquivo (geralmente não utilizado diretamente)
    off_t d_off;                // Offset da próxima entrada (geralmente não utilizado)
    unsigned short d_reclen;    // Tamanho da estrutura de dirent
    unsigned char d_type;       // Tipo de arquivo (diretório, arquivo regular, etc.)
    char d_name[256];           // Nome do arquivo ou diretório
};


*/