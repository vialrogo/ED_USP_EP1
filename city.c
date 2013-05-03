/*
 * city.c           File with all members of City
 * Create by:       Victor Alberto Romero Gonzalez
 *
 * Struct City:     A city qith path
 */

#include "city.h"

typedef struct City
{
    int idCity;
    QueueInt* pathCity;

    int       (*getIDCity)  (struct City*); /* Return the idCity */
    QueueInt* (*getPathCity)(struct City*); /* Return the pathCity*/

}City;

int getIDCity(struct City* city)
{
    return city->idCity;
}

QueueInt* getPathCity(struct City* city)
{
    return city->pathCity;
}

City* createCity(int idCityIn)
{
    City* city     = (City*) malloc(sizeof(City));
    city->idCity   = idCityIn;
    city->pathCity = createQueueInt();
    return city;
}
