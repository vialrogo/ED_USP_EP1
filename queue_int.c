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

typedef struct QueueInt
{
    int size;
    NodeInt* head;
    NodeInt* tail;

    void (*enqueue) (struct QueueInt*, int);   /* Add a element to the end */
    int  (*dequeue) (struct QueueInt*);        /* Remove and return the first element */
    int  (*first)   (struct QueueInt*);        /* Get the first element, but not remove */

}QueueInt;

void enqueue(struct QueueInt* queue, int element)
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

int  dequeue(struct QueueInt* queue)
{
    if(queue->size == 0) 
        printf("Try to dequeu a empty queue, you must garant that this will not happen again\n");

    /* Get Data*/
    NodeInt* oldHead = queue->head;
    int data = oldHead->data;
    
    /* Update a Queue*/
    queue->head = oldHead->next;
    queue->size--;
    
    /* Free memory and return */
    free(oldHead);
    return data;
}

int  first  (struct QueueInt* queue)
{
    if(queue->size == 0) 
        printf("Try to get the first of a empty queue, you must garant that this will not happen again\n");
    
    return queue->head->data;
}

QueueInt* createQueueInt()
{
    QueueInt* queue = (QueueInt*) malloc(sizeof(QueueInt));
    queue->size = 0;
    queue->head = NULL;
    queue->tail = NULL;
    queue->enqueue = &enqueue;
    queue->dequeue = &dequeue;
    queue->first = &first;
    return queue;
}