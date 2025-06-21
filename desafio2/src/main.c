#include <stdio.h>
#include <stdlib.h>
#include "ops.h"
#include "image.h"


int main(int argc, char **argv) {

    if(argc != 2){

        printf("\n\tUse: %s <Your-Archive-Name.pgm>\n", *argv);
        return 1;
    }

    //  PROCESS
    char inFile[255], outFile[255];
    filePath(*(argv + 1), inFile, outFile);                                                         //building the file output path

    unsigned N, M;

    //Functions callings & error printings
    unsigned char *image = readPGM(inFile, &N, &M);                                                 //reading the image from input file
    if(!image){
        perror("Read pgm input error (readPGM)!\n");
        return 2;
    }

    unsigned char *LBP = getLBP(image, N, M);                                                       //applying LBP
    if(!LBP){
        perror("LBP algorithm error (getLBP)!\n");
        return 3;
    }

    writeSave(outFile, LBP, N, M);                                                   //saving LBP result in output file

    //memory releasing
    free(image);
    free(LBP);

    return 0;
}