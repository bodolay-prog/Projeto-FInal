#include <stdio.h>
#include <time.h>
#include "doLBPHistogram.h"

#define QTDIMG 1

int main(){
	
	clock_t begin, end;
	double time_per_img, time_total=0;
	long long int a = 999999999;

		begin = clock();
		
		doLBPHistogram();// Processar - Sera a computacao do LBP.
		while(a){
			a--;
		}

		end = clock();

		time_per_img = (double)(end - begin) / CLOCKS_PER_SEC;

		time_total += time_per_img;

	

	printf("Tempo médio: %lf\n",time_total/QTDIMG);
	printf("Tempo Total: %lf\n",time_total);

	return 0;
}