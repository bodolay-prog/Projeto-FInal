/*

                                                ESSE É O CÓDIGO PRINCIPAL MAS TA LÁ PRA BAIXO

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

           if(dir->d_name[0] == '.') continue;                                                              //remove o . e .. da leitura

            allocMemStruct(&lbp, 1);                                                                        //aloca a memoria da struct da imagem atual
            printf("Alocado\n");

            printf("Current archive: %s\n", dir->d_name);// deixei pq tava la
            snprintf(filepath, sizeof(filepath), "../input/%s", dir->d_name);                               // faz a rota de onde está o arquivo na pasta 'inputs'
            readPGMImage(lbp,filepath);                                                                     // abstraindo a imagem


            allocMemVector(&histogram,(lbp->mv+2));
            // + 2, por causa do que tem que ser 0 a 255 o que seria histogram[256] e no final ter o 0 ou 1, ou seja, historgram[257] que vai de 0 - 256 posições


            lbp->pData = doLBPImage(lbp);                                                                   // faz o lbp e armazena no dados da strutc
            doHistogram(lbp,dir->d_name,histogram);                                                         // faz o histograma

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

*/

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include "../src/image.h"
#include "../src/ops.h"
#include "../src/memory.h"
#include "../src/file.h"
#include "../time/dotime.h"

/*


struct dirent {
    ino_t d_ino;                // Número do inode do arquivo (geralmente não utilizado diretamente)
    off_t d_off;                // Offset da próxima entrada (geralmente não utilizado)
    unsigned short d_reclen;    // Tamanho da estrutura de dirent
    unsigned char d_type;       // Tipo de arquivo (diretório, arquivo regular, etc.)
    char d_name[256];           // Nome do arquivo ou diretório
};


*/

int main(){
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
                allocMemVector(&histogram, (lbp->mv + 2));                                   //essa parte ta zuada
                doHistogram(lbp, dir->d_name, histogram);

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
                dotime();
        }
        closedir(d);  // Fecha o diretório

    } else perror("Erro ao abrir o diretório");

    return 0;
}
