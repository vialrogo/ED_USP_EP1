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

typedef struct _QueueCity QueueCity;

/* Function definition */
QueueCity* createQueueCity();
void  enqueueCity(struct _QueueCity*, City*);
City* dequeueCity(struct _QueueCity*);
City* firstCity  (struct _QueueCity*);
int   getSizeCity(struct _QueueCity*);

#endif
