#include <stdio.h>
#include <stdlib.h>
#include "ops.h"

int main(int argc, char **argv) {

    if (argc != 3) {
        printf("\n\tUse: %s <N> <M>\n", *argv);
        return 1;
    }

    unsigned N = atoi(argv[1]);
    unsigned M = atoi(argv[2]);

    //OPERATIONS
    int *Matrix = generation(N, M);                                   //generation of the matrix
    if(!Matrix){
        printf("\nMemory allocation error on the input matrix!\n");
        return 3;
    }

    saveMatrix("src/datas/matrix-in.txt", Matrix, N, M);                            //saving the generated matrix on /datas/*in

    int *loaded = (int*)malloc(N * M * sizeof(int));
    loadMatrix("src/datas/matrix-in.txt", loaded, &N, &M);            //scanning the generated matrix
    if(!loaded){
        printf("\nScan error on the input matrix!\n");
        return 4;
    }

    int *LBP = getLBP(loaded, N, M);                                            //LBP algorithm
    writeMatrix("src/datas/matrix-out.txt", LBP, N, M);                              //saving the LBP matrix in /dadas/*out
    if(!LBP){
        
        perror("Opening error in output archive\n");
        return 5;
    }

    printf("LBP runned! For more details, check the directory: /src/datas\n");

    //memory releasing
    free(Matrix);
    free(loaded);
    free(LBP);

    return 0;
}