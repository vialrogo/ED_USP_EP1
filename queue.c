/*
 * queue.c          file with definition and all functions of Queue
 * Create by:       Victor Alberto Romero Gonzalez
 *
 * Struct Queue:    Queue of integers. Has the basics methods of a queue. Its
 *                  implements with pointers
 *
 * Struct Node:     It's a auxiliar structure for Queue. Contain a data
 *                  (integer) and the pointer to the next Node.
 */

typedef struct Node
{
    int data;
    struct Node* next;
}Node;

typedef struct Queue
{
    int size;
    Node* head;
    Node* tail;

    void (*enqueue) (struct Queue*, int);   /* Add a element to the end */
    int  (*dequeue) (struct Queue*);        /* Remove and return the first element */
    int  (*first)   (struct Queue*);        /* Get the first element, but not remove */

}Queue;

/* Function definition */
void enqueue(struct Queue*, int);
int  dequeue(struct Queue*);
int  first  (struct Queue*);
Queue createQueue();

void enqueue(struct Queue* queue, int element)
{
}

int  dequeue(struct Queue* queue)
{
    return 0;
}

int  first  (struct Queue* queue)
{
    return 0;
}

Queue createQueue()
{
    Queue queue;
    return queue;
}
