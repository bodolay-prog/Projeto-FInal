/*
 * C Program to List Files in Directory
	https://www.sanfoundry.com/c-program-list-files-directory/
 */
#include <dirent.h>
#include <stdio.h>
 
int main(void)
{
    DIR *d;
    struct dirent *dir;
    d = opendir("./input-tests");
    if (d)
    {
        while ((dir = readdir(d)) != NULL)
        {
            if(dir->d_name[0] == '.') continue;
            printf("%s\n", dir->d_name);

						// Leitura da Imagem -PGM

						// Processar - Medir o tempo apenas nesta etapa.
						
						// Saída.
        }
        closedir(d);
    }
    return(0);
}		