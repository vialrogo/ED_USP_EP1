#include <stdio.h>
#include "queue_int.h"
#include "queue_city.h"

void testFileIO(char* inputFileName, char* outputFileName)
{
    FILE* fileIn;
    FILE* fileOut;

    /* File reader */
    int i = 0;
    
    fileIn = fopen (inputFileName, "r");
    fscanf (fileIn, "%d", &i);

    while(!feof (fileIn))
    {
        printf("%d\n", i);
        fscanf (fileIn, "%d", &i);
    }

    fclose(fileIn);

    /* File writer */
    fileOut = fopen(outputFileName, "w");

    if(fileOut==NULL)
    {
        printf("Cannot open the output file!\n");
    }

    fputs("Hello World\n", fileOut);
    fclose(fileOut);
}

void testQueueInt()
{
    QueueInt* queue = createQueueInt();    
    enqueueInt(queue,5);
    printf("%d \n",firstInt(queue));
    enqueueInt(queue,4);
    printf("%d \n",dequeueInt(queue));
    enqueueInt(queue,1);
    enqueueInt(queue,2);
    enqueueInt(queue,9);
    printf("Size: %d \n",getSizeInt(queue));
    printf("%d \n",dequeueInt(queue));
    printf("%d \n",dequeueInt(queue));
    printf("%d \n",dequeueInt(queue));
    printf("%d \n",dequeueInt(queue));
}

void testQueueCity()
{
    QueueCity* queue = createQueueCity();
    
    City* newCity = createCity();
    enqueueInt(getPathCity(newCity),1);
    enqueueInt(getPathCity(newCity),3);
    enqueueInt(getPathCity(newCity),2);
    enqueueCity(queue,newCity);

    newCity = createCity();
    enqueueInt(getPathCity(newCity),4);
    enqueueInt(getPathCity(newCity),5);
    enqueueCity(queue,newCity);

    dequeueCity(queue);

    newCity = createCity();
    enqueueInt(getPathCity(newCity),6);
    enqueueInt(getPathCity(newCity),7);
    enqueueInt(getPathCity(newCity),8);
    enqueueInt(getPathCity(newCity),9);
    enqueueCity(queue,newCity);

    dequeueCity(queue);

    int i;
    int size = getSizeInt(getPathCity(firstCity(queue))); 
    for(i=0; i<size; i++)
        printf("%d\n",dequeueInt(getPathCity(firstCity(queue))));
}

int main(int argc, char *argv[])
{
    /*char* inputFileName  = argv[1];
    char* outputFileName = argv[2];
    testFileIO(inputFileName,outputFileName);*/

    /*testQueueInt();*/

    /*testQueueCity();*/

    return 0;
}
