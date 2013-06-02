/*
 * city.h           File with definition of City
 * Create by:       Victor Alberto Romero Gonzalez
 *
 * Struct City:     A City.
 */

#ifndef CITY_H
#define CITY_H

#include "queue_int.h"

typedef struct _City City;

/* Functions definition*/
City* createCity(int idCityIn);
int getIDCity(struct _City*);
QueueInt* getPathCity(struct _City*);

#endif
