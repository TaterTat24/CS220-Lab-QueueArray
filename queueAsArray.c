/** 
 * ===========================================================
 * Name: Benjamin Tat
 * Section: T6
 * Project: Queue ADT implemented with C array
 * ===========================================================
 */
#include "queueAsArray.h"

#include <stdio.h>
#include <stdlib.h>

/** enqueue() - adds an element to the back of the queue
 * @param queue - a ptr to the queue structure
 * @param element - the item to add to the queue
 * @return 1 on success, -1 on failure
 */
int enqueue(QueueAsArray* queue, int element) {
    if (queueIsEmpty(queue)){
        queue->front++;
        queue->back++;
        queue->number[queue->back] = element;
        queue->size++;
        return 1;
    }
    else if (!queueIsFull(queue)){
        queue->back = (queue->back+1) % QUEUE_MAX_SIZE;
        queue->number[queue->back] = element;
        queue->size++;
        return 1;
    }    
    return -1;
}

/** dequeue() - removes an element from the front of the queue
 * @param queue - a ptr to the queue structure
 * @return - the top of the queue on success, -1 on failure
 */
int dequeue(QueueAsArray* queue) {
    if (!queueIsEmpty(queue)){
        queue->front = queue->front+1;
        queue->size--;
    }
    return -1;
}

/** queueIsEmpty() - determines if the queue is empty
 * @param queue - a ptr to the queue structure
 * @return - true if the queue is empty or false
 */
bool queueIsEmpty(QueueAsArray* queue) {
    return queue->size == 0;
}

/** queueIsFull() - determines if the queue is full
 * @param queue - a ptr to the queue structure
 * @return - true if the queue is full or false
 */
bool queueIsFull(QueueAsArray* queue) {
    return queue->size == QUEUE_MAX_SIZE;
}

/** queueInit() - initializes the queue structure
 * @param queue - a ptr to the queue structure
 */
void queueInit(QueueAsArray* queue) {
    queue->size = 0;
    queue->front = -1;
    queue->back = -1;
}

/** queuePeek() - returns the item on the front of the
 * queue but doesn't remove it
 * @param queue - a ptr to the queue structure
 * @return - the item at the front of the queue or -1 on failure
 */
int queuePeek(QueueAsArray* queue) {
    if (queue->size > 0){
        return queue->number[queue->front];
    }
    return -1;
}

/** queueSize() - determines the size of the queue
 * @param queue - a ptr to the queue structure
 * @return - number of items in the queue
 */
int queueSize(QueueAsArray* queue) {
    return queue->size;
}

/** queuePrint() - outputs the queue to the console
 * @param queue - ptr to the queue structure
 */
void queuePrint(QueueAsArray* queue) {
    int index = queue->front;

    for (int i = 0; i < queue->size; i++){
        printf("%d ", queue->number[index]);
        index = (index + 1) % QUEUE_MAX_SIZE;
    }
}