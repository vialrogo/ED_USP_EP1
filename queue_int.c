/*
 * queue_int.c      File with all functions of Queue of int
 * Create by:       Victor Alberto Romero Gonzalez
 *
 * Struct QueueInt: Queue of integers. Has the basics methods of a queue. Its
 *                  implements with pointers
 *
 * Struct NodeInt:  It's a auxiliar structure for Queue. Contain a data
 *                  (integer) and the pointer to the next Node.
 */

#include "queue_int.h"

typedef struct NodeInt
{
    int data;
    struct NodeInt* next;
}NodeInt;

typedef struct _QueueInt
{
    int size;
    NodeInt* head;
    NodeInt* tail;

    void (*enqueueInt) (struct _QueueInt*, int); /* Add a element to the end */
    int  (*dequeueInt) (struct _QueueInt*);      /* Remove and return the first element */
    int  (*firstInt)   (struct _QueueInt*);      /* Get the first element, but not remove */
    int  (*getSizeInt) (struct _QueueInt*);      /* Get a current size of a queue */
    
}_QueueInt;

void enqueueInt(struct _QueueInt* queue, int element)
{
    /* Creating a new node*/
    NodeInt* newNode = (NodeInt*) malloc(sizeof(NodeInt));
    newNode->data = element;
    newNode->next = NULL;
    
    /* Putting the new node in the queue */
    if(queue->head == NULL) queue->head = newNode;
    else queue->tail->next = newNode;

    /* Updating the queue with the new node and size*/
    queue->tail = newNode;
    queue->size++;
}

int dequeueInt(struct _QueueInt* queue)
{
    NodeInt* oldHead;
    int data;

    if(queue->size == 0) 
        printf("Tried to dequeu a empty queue, you must garant that this will not happen again\n");

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

int firstInt(struct _QueueInt* queue)
{
    if(queue->size == 0) 
        printf("Tried to get the first of a empty queue, you must garant that this will not happen again\n");
    
    return queue->head->data;
}

int getSizeInt(struct _QueueInt* queue)
{
    return queue->size;
}

QueueInt* createQueueInt()
{
    QueueInt* queue = (QueueInt*) malloc(sizeof(QueueInt));
    queue->size = 0;
    queue->head = NULL;
    queue->tail = NULL;
    queue->enqueueInt = &enqueueInt;
    queue->dequeueInt = &dequeueInt;
    queue->firstInt = &firstInt;
    return queue;
}
