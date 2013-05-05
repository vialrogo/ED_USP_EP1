/*
 * city.h           File with definition of City
 * Create by:       Victor Alberto Romero Gonzalez
 *
 * Struct City:     A City.
 */

#ifndef CITY_H
#define CITY_H

#include "queue_int.h"

typedef struct City City;

/* Functions definition*/
City* createCity(int idCityIn);
int getIDCity(struct City*);
QueueInt* getPathCity(struct City*);

#endif
