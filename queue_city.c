/*
 * queue_city.c      File with all functions of Queue of cities
 * Create by:        Victor Alberto Romero Gonzalez
 *
 * Struct QueueCity: Queue of cities. Has the basics methods of a queue. Its
 *                   implements with pointers
 *
 * Struct NodeCity:  It's a auxiliar structure for Queue. Contain a data
 *                   (City) and the pointer to the next Node.
 */

#include "queue_city.h"

typedef struct NodeCity
{
    City* data;
    struct NodeCity* next;

}NodeCity;

typedef struct QueueCity
{
    int size;
    NodeCity* head;
    NodeCity* tail;

    void  (*enqueueCity) (struct QueueCity*, City*);/* Add a element to the end */
    City* (*dequeueCity) (struct QueueCity*);       /* Remove and return the first element */
    City* (*firstCity)   (struct QueueCity*);       /* Get the first element, but not remove */
    int   (*getSizeCity) (struct QueueCity*);       /* Get the current size of the queue */

}QueueCity;

void enqueueCity(struct QueueCity* queue, City* element)
{
    /* Creating a new node*/
    NodeCity* newNode = (NodeCity*) malloc(sizeof(NodeCity));
    newNode->data = element;
    newNode->next = NULL;
    
    /* Putting the new node in the queue */
    if(queue->head == NULL) queue->head = newNode;
    else queue->tail->next = newNode;

    /* Updating the queue with the new node and size*/
    queue->tail = newNode;
    queue->size++;
}

City* dequeueCity(struct QueueCity* queue)
{
    if(queue->size == 0) 
        printf("Try to dequeu a empty queue, you must garant that this will not happen again\n");

    /* Get Data*/
    NodeCity* oldHead = queue->head;
    City* data = oldHead->data;
    
    /* Update a Queue*/
    queue->head = oldHead->next;
    queue->size--;
    
    /* Free memory and return */
    free(oldHead);
    return data;
}

City* firstCity(struct QueueCity* queue)
{
    if(queue->size == 0) 
        printf("Try to get the first of a empty queue, you must garant that this will not happen again\n");
    
    return queue->head->data;
}

int getSizeCity(struct QueueCity* queue)
{
    return queue->size;
}

QueueCity* createQueueCity()
{
    QueueCity* queue = (QueueCity*) malloc(sizeof(QueueCity));
    queue->size = 0;
    queue->head = NULL;
    queue->tail = NULL;
    queue->enqueueCity = &enqueueCity;
    queue->dequeueCity = &dequeueCity;
    queue->firstCity = &firstCity;
    return queue;
}
