#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "csv.h"

void generateCSV(pgm *pio, const char *filename, unsigned char *histogram){

    FILE *fp = fopen("output/out.csv", "a");

    if (!fp){
        perror("generateCSV() says: Erro ao abrir output/out.csv");
        exit(1);
    }

    // Extrai o nome do arquivo sem o caminho
    char *name, copy[256];
    unsigned class;

    name = strrchr(filename, '/');                                                              //procurando '/' no caminho do arquivo (ex: input/0_11053)
    name += 1;                                                                                  //passa para o nome do arquivo ("pula" a barra)

    strcpy(copy, name);                                                                         //copia 'name' para 'copy' (pois strtok modifica a string original)
    class = atoi(strtok(copy, "_"));                                                            //Extrai o número antes do "_", ou seja, sua classe

    // Escreve o histograma
    for(int i = 0; i < 256; i++) fprintf(fp, "%d,", *(histogram + i));

    // Escreve a classe
    fprintf(fp, "%d\n", class);

    fclose(fp);
}