#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "csv.h"

void generateCSV(pgm *pio, const char *filename, unsigned char *histogram, FILE *csvPointer){

    //Extraindo a classe
    const char *base = strrchr(filename, '/');                                              //posicionando ao achar a barra (ex: input/0_1078...)
    base += 1;                                                                              //posicionando na primeira posição do nome do arquivo (onde está a classe)
    int class = atoi(base);

    // Escreve histograma
    for (int i = 0; i < 256; i++) fprintf(csvPointer, "%d,", histogram[i]);

    fprintf(csvPointer, "%d\n", class);
}