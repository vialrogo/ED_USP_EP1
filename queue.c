/*
 * queue.c          File with all functions of Queue
 * Create by:       Victor Alberto Romero Gonzalez
 *
 * Struct Queue:    Queue of integers. Has the basics methods of a queue. Its
 *                  implements with pointers
 *
 * Struct Node:     It's a auxiliar structure for Queue. Contain a data
 *                  (integer) and the pointer to the next Node.
 */

#include "queue.h"

typedef struct Node
{
    TYPE data;
    struct Node* next;
}Node;

typedef struct Queue
{
    int size;
    Node* head;
    Node* tail;

    void (*enqueue) (struct Queue*, TYPE);   /* Add a element to the end */
    TYPE  (*dequeue) (struct Queue*);        /* Remove and return the first element */
    TYPE  (*first)   (struct Queue*);        /* Get the first element, but not remove */

}Queue;

void enqueue(struct Queue* queue, TYPE element)
{
    /* Creating a new node*/
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = element;
    newNode->next = NULL;
    
    /* Putting the new node in the queue */
    if(queue->head == NULL) queue->head = newNode;
    else queue->tail->next = newNode;

    /* Updating the queue with the new node and size*/
    queue->tail = newNode;
    queue->size++;
}

TYPE  dequeue(struct Queue* queue)
{
    if(queue->size == 0) 
        printf("Try to dequeu a empty queue, you must garant that this will not happen again\n");

    /* Get Data*/
    Node* oldHead = queue->head;
    TYPE data = oldHead->data;
    
    /* Update a Queue*/
    queue->head = oldHead->next;
    queue->size--;
    
    /* Free memory and return */
    free(oldHead);
    return data;
}

TYPE  first  (struct Queue* queue)
{
    if(queue->size == 0) 
        printf("Try to get the first of a empty queue, you must garant that this will not happen again\n");
    
    return queue->head->data;
}

Queue* createQueue()
{
    Queue* queue = (Queue*) malloc(sizeof(Queue));
    queue->size = 0;
    queue->head = NULL;
    queue->tail = NULL;
    queue->enqueue = &enqueue;
    queue->dequeue = &dequeue;
    queue->first = &first;
    return queue;
}
