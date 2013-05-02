/*
 * queue.h          File with definition of Queue
 * Create by:       Victor Alberto Romero Gonzalez
 *
 * Struct Queue:    Queue of integers. Has the basics methods of a queue. Its
 *                  implements with pointers
 */

#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>
#include <stdio.h>

#define TYPE int

typedef struct Queue Queue;

/* Function definition */
Queue* createQueue();
void enqueue(struct Queue*, TYPE);
TYPE  dequeue(struct Queue*);
TYPE  first  (struct Queue*);

#endif
