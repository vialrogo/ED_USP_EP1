/*
 * queue_int.h      File with definition of Queue of int
 * Create by:       Victor Alberto Romero Gonzalez
 *
 * Struct Queue:    Queue of integers. Has the basics methods of a queue. Its
 *                  implements with pointers
 */

#ifndef QUEUE_INT_H
#define QUEUE_INT_H

#include <stdlib.h>
#include <stdio.h>

typedef struct _QueueInt QueueInt;

/* Function definition */
QueueInt* createQueueInt();
void enqueueInt(struct _QueueInt*, int);
int  dequeueInt(struct _QueueInt*);
int  firstInt  (struct _QueueInt*);
int  getSizeInt(struct _QueueInt*);

#endif
