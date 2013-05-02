#include <stdio.h>
#include "queue.h"

int main(int argc, char *argv[])
{
    FILE* fileIn;
    FILE* fileOut;
    char* NomeArquivoEntrada = argv[1];
    char* NomeArquivoSaida = argv[2];

    /* Leitura do arquivo*/
    int i = 0;
    
    fileIn = fopen (NomeArquivoEntrada,"r");
    fscanf (fileIn, "%d", &i);

    while(!feof (fileIn))
    {
        printf("%d\n", i);
        fscanf (fileIn, "%d", &i);
    }

    fclose(fileIn);

    /* Escritura do arquivo*/
    fileOut = fopen(NomeArquivoSaida, "w");

    if(fileOut==NULL)
    {
        printf("Não pode abrir o arquivo de saida!\n");
        return 1;
    }

    fputs("Hola mundo\n", fileOut);
    fclose(fileOut);

    Queue* queue = createQueue();
    int a = dequeue(queue);
    int b = first(queue);
    printf("%d %d\n",a,b);

    return 0;
}
