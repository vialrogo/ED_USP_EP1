#include <stdio.h>
#include "queue_int.h"
#include "queue_city.h"
#include "city.h"

/* Global variables*/
const int maxNumberOfCities=1000; /* Giving by the problem*/
QueueInt** cityRoutes;
short* visitedCities;

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
    fileIn=0;
}

void calculateMinimalRoutes()
{
    QueueCity* queueOfCities = createQueueCity();
    enqueueCity(queueOfCities,createCity(0));

    int i,j,tmp;
    int numberOfNeighbors;
    int currentNeighbor;
    int sizeOfCurrentPath;
    int idCurrentCity;
    City* currentCity;
    QueueInt* neighbors;

    while(getSizeCity(queueOfCities)>0)
    {
        currentCity = dequeueCity(queueOfCities);
        idCurrentCity = getIDCity(currentCity);

        if(visitedCities[idCurrentCity]==0)
        {
            neighbors = cityRoutes[idCurrentCity];
            numberOfNeighbors = getSizeInt(neighbors);
            
            /* For all neighbors create a city with the updating path*/
            for(i=0; i<numberOfNeighbors; i++)
            {
                /* Create a new city*/
                currentNeighbor = dequeueInt(neighbors);
                City* newCity = createCity(currentNeighbor);
               
                /* Update the path of the new city*/
                sizeOfCurrentPath = getSizeInt(getPathCity(currentCity));
                for(j=0; j<sizeOfCurrentPath; j++)
                {
                    tmp = dequeueInt(getPathCity(currentCity));
                    enqueueInt(getPathCity(currentCity),tmp);
                    enqueueInt(getPathCity(newCity),tmp);
                }
                enqueueInt(getPathCity(newCity),idCurrentCity);
                
                /* Enqueue the new City*/
                enqueueCity(queueOfCities,newCity);
            }
           
            /* Free the neighbors queue and then assing this pointer to the
             * minimal path. Last, mark the city like visited*/
            free(cityRoutes[idCurrentCity]);
            cityRoutes[idCurrentCity] = getPathCity(currentCity);
            visitedCities[idCurrentCity] = 1;
        }
        else
        {
            /* Free currentPath because isnt the minimal path */
            free(getPathCity(currentCity));
        }

        /* Free the currentCity after process it */
        free(currentCity);
    }
}

int main(int argc, char *argv[])
{
    /* Correct number of parameters? */
    if(argc<2)
    {
        printf("Incorrect number of parameters!\n");
        return 1;
    }
    char* inputFileName  = argv[1];
    char* outputFileName = argv[2];

    /* Initialization of cityRoutes and visitedCities*/
    cityRoutes =    (QueueInt**)malloc(sizeof(QueueInt*)*maxNumberOfCities);
    visitedCities = (short*)malloc(sizeof(short)*maxNumberOfCities);
    int i;
    for(i=0; i<maxNumberOfCities; i++)
    {
        cityRoutes[i] = createQueueInt();
        visitedCities[i] = 0;
    }

    /* Read input file */
    readInputFile(inputFileName);

    calculateMinimalRoutes();

    
    int j,tmp;      
    for(i=0; i<10; i++)
    {
        tmp = getSizeInt(cityRoutes[i]);
        for(j=0; j<tmp; j++)
            printf("%d ",dequeueInt(cityRoutes[i]));
        printf("\n");
    }

    /* Memory free */

    return 0;
}
