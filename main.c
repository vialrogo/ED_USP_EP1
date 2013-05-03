#include <stdio.h>
#include "queue_int.h"
#include "queue_city.h"
#include "city.h"

/* Global variables*/
const int maxNumberOfCities=1000; /* Giving by the problem*/
QueueInt** cityRoutes;
short* visitedCities;

void writeOutputFile(char* outputFileName)
{
   /* File writer */
    FILE* fileOut;
    int i,j,routeSize;
    fileOut = fopen(outputFileName, "w");
    char str[3500]; /* Its more that the maximum poissible with 1000 cities*/ 

    if(fileOut==NULL)
    {
        printf("Cannot open the output file!\n");
    }
    else
    {
        for(i=0; i<maxNumberOfCities; i++)
        {
            routeSize = getSizeInt(cityRoutes[i]);
            if(routeSize>0 || i==0)
            {
                sprintf(str,"Cidade %d %d ",i,routeSize);
                fputs(str,fileOut);
                for(j=0; j<routeSize; j++)
                {
                    sprintf(str,"%d ",dequeueInt(cityRoutes[i]));
                    fputs(str,fileOut);
                }
                fputs("\n",fileOut);
            }
        }
    }
    
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

    /* Close file, and zering pointer*/
    fclose(fileIn);
    fileIn=0;
}

void calculateMinimalRoutes()
{
    /* Create a queue of cities*/
    QueueCity* queueOfCities = createQueueCity();
    enqueueCity(queueOfCities,createCity(0));

    /* Create a temporal variables*/
    int i,j,tmp;
    int numberOfNeighbors;
    int currentNeighbor;
    int sizeOfCurrentPath;
    int idCurrentCity;
    City* currentCity;
    QueueInt* neighbors;

    while(getSizeCity(queueOfCities)>0)
    {
        /* Dequeue the current city */
        currentCity = dequeueCity(queueOfCities);
        idCurrentCity = getIDCity(currentCity);

        if(visitedCities[idCurrentCity]==0)
        {
            /* Extract the neighbors */
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

    readInputFile(inputFileName);
    calculateMinimalRoutes();
    writeOutputFile(outputFileName); 
    

    /* Memory free */

    return 0;
}
