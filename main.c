#include <stdio.h>
#include "queue_int.h"
#include "queue_city.h"


/* Global variables*/
const int maxNumberOfCities=1000; /* Giving by the problem*/
QueueInt** cityRoutes;

void testFileIO(char* outputFileName)
{
   /* File writer */
    FILE* fileOut;
    
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

void readInputFile(char* inputFileName)
{
    /* File reader */
    FILE* fileIn;
    int from = 0;
    int to = 0;
    
    fileIn = fopen (inputFileName, "r");
    fscanf (fileIn, "%d", &from);
    fscanf (fileIn, "%d", &to);

    while(!feof (fileIn))
    {
        enqueueInt(cityRoutes[from],to);
        fscanf (fileIn, "%d", &from);
        fscanf (fileIn, "%d", &to);
    }

    fclose(fileIn);
}

int main(int argc, char *argv[])
{
    /* Correcto number of parameters? */
    if(argc<2)
    {
        printf("Incorrect number of parameters!\n");
        return 1;
    }
    char* inputFileName  = argv[1];
    char* outputFileName = argv[2];

    /* Initialization of cityRoutes */
    cityRoutes = (QueueInt**)malloc(sizeof(QueueInt*)*maxNumberOfCities);
    int i;
    for(i=0; i<maxNumberOfCities; i++)
        cityRoutes[i] = createQueueInt();

    /* Read input file */
    readInputFile(inputFileName);

    
    int j;      
    for(i=0; i<20; i++)
    {
        for(j=0; j<getSizeInt(cityRoutes[i]); j++)
            printf("%d ",dequeueInt(cityRoutes[i]));
        printf("\n");
    }

    return 0;
}
