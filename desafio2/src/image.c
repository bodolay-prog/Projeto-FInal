#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "image.h"

void filePath(const char *name, char *input, char *output){

    snprintf(input, 255, "src/datas/inputs/%s", name);                                                              //input archive path building

    const char *final = strrchr(name, '.');
    if (!final) final = name + strlen(name);
    snprintf(output, 255, "src/datas/outputs/%.*s-lbp.pgm", (int)(final - name), name);                             //output archive pah building
}

unsigned char* readPGM(const char *img, unsigned *N, unsigned *M){

    /*  PGM P5 file structure:
    P5
    <columns> <rows>
    <maximal range>
    <binaries>

    */

    FILE *f = fopen(img, "rb");
    if(!f) return NULL;
    
    //scanning "P5"
    char buff[3];
    fscanf(f, "%2s", buff);
    if(strcmp(buff, "P5") != 0){

        perror("\nreadPGM says:    Invalid format scan! Expected P5\n");
        fclose(f);
        return NULL;
    }

    //scanning "<rows> <columns>" & "<maximal range>"
    fscanf(f, "%d %d", M, N);
    int maxV;
    fscanf(f, "%d", &maxV);
    fgetc(f);

    //binaries scan
    int size = (*N) * (*M);
    unsigned char *data = malloc(size);

    fread(data, 1, size, f);                                                                                        //1 pixel = 1 byte
    fclose(f);

    return data;
}

void writeSave(const char *img, unsigned char *matrix, unsigned N, unsigned M){

    FILE *p = fopen(img, "wb");
    if(!p){

        perror("\nwriteSave says: Error in output archive opening!\n");
        return;
    }

    fprintf(p, "P5\n%u %u\n255\n", M, N);                                                                           //PGM header (already standardized)
    fwrite(matrix, sizeof(unsigned char), N * M, p);

    fclose(p);
}