#include <stdio.h>
#include <time.h>
#include <../src/image.h>
#include "../src/doHistogram.h"

int main(){
	
	clock_t begin, end;
	double time_per_img, time_total = 0;

	int qtdIm = countImages("input");
	puts("\n----------------- Iniciando processamento ---------------------------\n");
	
	begin = clock();
		
		doLBPHistogram();													//Computação principal

	end = clock();

	time_per_img = (double)(end - begin) / CLOCKS_PER_SEC;
	time_total += time_per_img;

	puts("\n---------------------------- Finalizado ----------------------------\n");
	printf("Tempo Total: %lf\n", time_total);
	printf("Tempo médio de processamento (%d imagens): %lf\n\n", qtdIm, time_total / qtdIm);

	puts("Histograma salvo! Confira em: output/out.csv");

	return 0;
}