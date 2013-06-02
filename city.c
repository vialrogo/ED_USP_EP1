/*
 * city.c           File with all members of City
 * Create by:       Victor Alberto Romero Gonzalez
 *
 * Struct City:     A city qith path
 */

#include "city.h"

typedef struct _City
{
    int idCity;
    QueueInt* pathCity;

    int       (*getIDCity)  (struct _City*); /* Return the idCity */
    QueueInt* (*getPathCity)(struct _City*); /* Return the pathCity*/

}_City;

int getIDCity(struct _City* city)
{
    return city->idCity;
}

QueueInt* getPathCity(struct _City* city)
{
    return city->pathCity;
}

City* createCity(int idCityIn)
{
    City* city    = (City*) malloc(sizeof(City));
    city->idCity   = idCityIn;
    city->pathCity = createQueueInt();
    return city;
}
