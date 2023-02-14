/** 
 * ================================================================
 * Name: Benjamin Tat
 * Section: T6
 * Project: Queue ADT implemented with C array
 * =================================================================
 *
 * Complete the tasks below after completing the tasks in the queueAsArray.c
 * file
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "queueAsArray.h"

// local function prototypes
void printMenu();

int main() {
    /** TASK 0 - Add functionality to this file to enable the DMV
     * application to run.
     * 0) ensure that you have completed implementation of
     * the functions in queueAsArray.c prior to starting this task.
     * 1) Call appropriate functions in the switch statement below
     * 2) use printQueue to test your functionality
     * Note: you MUST use the queue library in completing
     * this task.
     */

    QueueAsArray queue;
    queueInit(&queue);

    // Inits the Random Number Queue
    srand(2023);

    int choice = 0;
    do {
        printMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1: {  // generate a random number between 1 and 50 then enqueue
                int randomValue = (rand() % 50) + 1;
                int result = enqueue(&queue, randomValue);
                printf("Enqueing Value %d.  enqueue() returned %d\n", randomValue, result);
                break;
            }
            case 2: {  // dequeue the number at the front of the line and print it
                int value = dequeue(&queue);
                printf("Dequeued %d\n", value);
                break;
            }
            case 3: {  // get the size of the queue
                int size = queueSize(&queue);
                printf("Queue Size = %d\n", size);
                break;
            }
            case 4: {  // print the queue
                queuePrint(&queue);
                break;
            }
            case 5: {  // exit the application
                printf("Bye!\n");
                exit(1);
                break;
            }
            default: {  // invalid choice
                printf("Invalid Choice\n");
            }
        }
    } while (choice != 5);

    return 0;
}

/** printMenu() - prints a menu for our DMV app
 */
void printMenu() {
    printf("\nMAIN MENU\n");
    printf("Enqueue a random number-----1\n");
    printf("Dequeue a number------------2\n");
    printf("Get queue size--------------3\n");
    printf("Print queue contents--------4\n");
    printf("Exit------------------------5\n\n");
    printf("Enter option: ");
}