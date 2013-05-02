/*
 * queue_city.h         File with definition of Queue of city pointers
 * Create by:           Victor Alberto Romero Gonzalez
 *
 * Struct QueueCity:    Queue of cities. Has the basics methods of a queue. Its
 *                      implements with pointers
 */

#ifndef QUEUE_CITY_H
#define QUEUE_CITY_H

#include <stdlib.h>
#include <stdio.h>
#include "city.h"

typedef struct QueueCity QueueCity;

/* Function definition */
QueueCity* createQueueCity();
void  enqueueCity(struct QueueCity*, City*);
City* dequeueCity(struct QueueCity*);
City* firstCity  (struct QueueCity*);
int   getSizeCity(struct QueueCity*);

#endif
