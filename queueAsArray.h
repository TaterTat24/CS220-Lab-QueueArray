/** queueAsArray.h
 * ===========================================================
 * Name: Benjamin Tat
 * Section: T6
 * Project: Lab11 - Queue ADT implemented with C array
 * ===========================================================
 */
#ifndef QASARRAY_H
#define QASARRAY_H
#include <stdbool.h>

#define QUEUE_MAX_SIZE 11

typedef struct {
    int number[QUEUE_MAX_SIZE];  // the array storing the contents of the queue
    int front;                   // the current index of the front of the queue
    int back;                    // the current index of the front of the queue
    int size;                    // the current number of elements stored in the queue
} QueueAsArray;

/** enqueue() - adds an element to the back of the queue
 * @param queue - a ptr to the queue structure
 * @param element - the item to add to the queue
 * @return 1 on success, -1 on failure
 */
int enqueue(QueueAsArray* queue, int element);

/** dequeue() - removes an element from the front of the queue
 * @param queue - a ptr to the queue structure
 * @return - the front of the queue on success, -1 on failure
 */
int dequeue(QueueAsArray* queue);

/** queueIsEmpty() - determines if the queue is empty
 * @param queue - a ptr to the queue structure
 * @return - true if the queue is empty or false
 */
bool queueIsEmpty(QueueAsArray* queue);

/** queueIsFull() - determines if the queue is full
 * @param queue - a ptr to the queue structure
 * @return - true if the queue is full or false
 */
bool queueIsFull(QueueAsArray* queue);

/** queueInit() - initializes the queue structure
 * @param queue - a ptr to the queue structure
 */
void queueInit(QueueAsArray* queue);

/** queuePeek() - returns the item on the front of the
 * queue but doesn't remove it
 * @param queue - a ptr to the queue structure
 * @return - the item at the front of the queue or -1 on failure
 */
int queuePeek(QueueAsArray* queue);

/** queueSize() - determines the size of the queue
 * @param queue - a ptr to the queue structure
 * @return - number of items in the queue
 */
int queueSize(QueueAsArray* queue);

/** queuePrint() - outputs the queue to the console
 * @param queue - ptr to the queue structure
 */
void queuePrint(QueueAsArray* queue);

#endif  // QASARRAY_H
