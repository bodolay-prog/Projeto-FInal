#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include "../src/image.h"
#include "../src/ops.h"
#include "../src/memory.h"
#include "../src/file.h"

/*


struct dirent {
    ino_t d_ino;                // Número do inode do arquivo (geralmente não utilizado diretamente)
    off_t d_off;                // Offset da próxima entrada (geralmente não utilizado)
    unsigned short d_reclen;    // Tamanho da estrutura de dirent
    unsigned char d_type;       // Tipo de arquivo (diretório, arquivo regular, etc.)
    char d_name[256];           // Nome do arquivo ou diretório
};


*/

void doLBPHistogram(){
    pgm *lbp;
    DIR *d;
    char filepath[512];
    struct dirent *dir;

    d = opendir("input");
    if (d) {
        while ((dir = readdir(d)) != NULL) {
            if (dir->d_name[0] == '.') continue;                                                                        //Ignora . e ..
            
            
                allocMemStruct(&lbp, 1);                                                                                // Aloca a memória para a imagem
                printf("Alocado\n");

                //Cria o caminho completo para o arquivo de imagem e a abstrai
                snprintf(filepath, sizeof(filepath), "input/%s", dir->d_name);
                readPGMImage(lbp, filepath);  // Lê a imagem

                //Processa LBP e histograma
                lbp->pData = doLBPImage(lbp);

                unsigned char *histogram = NULL;
                allocMemVector(&histogram, (lbp->mv + 2));      
                printf("%s\n",dir->d_name);                             
                doHistogram(lbp, dir->d_name, histogram);
                printf("The type of the archive is %d\n",*(histogram + lbp->mv + 1));
                

                //Salva a imagem processada
                snprintf(filepath, sizeof(filepath), "output/%s", dir->d_name);
                writePGMImage(lbp, filepath);



                // Liberação de memória
                free(lbp->pData);
                free(lbp);
                free(histogram);

                /*
                
                Overview:
                - função de histograma ainda não feita (o mais mamão, já já eu faço pera)
                - função de gerar CSV declarada em file.c e file.h mas incompleta.
                

                */



                // Medição de tempo
        }
        closedir(d);  // Fecha o diretório

    } else perror("Erro ao abrir o diretório");

}
