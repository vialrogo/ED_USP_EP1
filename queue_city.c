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

typedef struct _QueueCity
{
    int size;
    NodeCity* head;
    NodeCity* tail;

    void  (*enqueueCity) (struct _QueueCity*, City*);/* Add a element to the end */
    City* (*dequeueCity) (struct _QueueCity*);       /* Remove and return the first element */
    City* (*firstCity)   (struct _QueueCity*);       /* Get the first element, but not remove */
    int   (*getSizeCity) (struct _QueueCity*);       /* Get the current size of the queue */

}_QueueCity;

void enqueueCity(struct _QueueCity* queue, City* element)
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

City* dequeueCity(struct _QueueCity* queue)
{
    NodeCity* oldHead;
    City* data; 

    if(queue->size == 0) 
        printf("Try to dequeu a empty queue, you must garant that this will not happen again\n");

    /* Get Data*/
    oldHead = queue->head;
    data = oldHead->data;
    
    /* Update a Queue*/
    queue->head = oldHead->next;
    queue->size--;
    
    /* Free memory and return */
    free(oldHead);
    return data;
}

City* firstCity(struct _QueueCity* queue)
{
    if(queue->size == 0) 
        printf("Try to get the first of a empty queue, you must garant that this will not happen again\n");
    
    return queue->head->data;
}

int getSizeCity(struct _QueueCity* queue)
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
