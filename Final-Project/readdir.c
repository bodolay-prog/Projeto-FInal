/*
 * C Program to List Files in Directory
	https://www.sanfoundry.com/c-program-list-files-directory/
 */
#include <dirent.h>
#include <stdio.h>
#include "./lib/ops.h"
#include <stdlib.h>

 
int main(void)
{
    pgm lbp;
    DIR *d;
    char *name;
    char filepath[512];
    struct dirent *dir;
    d = opendir("./input-tests");
    if (d)
    {
        
        while ((dir = readdir(d)) != NULL)
        {
            if(dir->d_name[0] == '.') continue;
            printf("%s\n", dir->d_name);
            snprintf(filepath, sizeof(filepath), "./input-tests/%s", dir->d_name);
			readPGMImage(&lbp,filepath);             
            lbp.pData = doLBPImage(lbp);
            snprintf(filepath, sizeof(filepath), "./output-tests/%s", dir->d_name);
            writePGMImage(&lbp,filepath);
            free(lbp.pData);

						// Processar - Medir o tempo apenas nesta etapa.
						
						// Saída.
        }
        closedir(d);
    }
    return(0);
}		