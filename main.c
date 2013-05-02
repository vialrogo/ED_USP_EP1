#include <stdio.h>

FILE* file;

int main(int argc, char *argv[])
{
    char* NomeArquivoEntrada;
    char* NomeArquivoSaida;

    NomeArquivoEntrada = argv[1];
    NomeArquivoSaida = argv[2];

    /* Leitura do arquivo*/
    
    int i = 0;
    
    file = fopen (NomeArquivoEntrada,"r");
    fscanf (file, "%d", &i);

    while(!feof (file))
    {
        printf("%d\n", i);
        fscanf (file, "%d", &i);
    }


    fclose(file);
    return 0;
}
