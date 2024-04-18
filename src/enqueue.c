#include <stdio.h>
#include <stdlib.h>

#include "enqueue.h"

#define SIZE 10

void enqueue(struct Queue* queue, struct Ticket* ticket) {
    if (queue->count > SIZE-1) {
        printf("overflow");
        exit(1);
    }

    if (queue->count == 0) {
        //first
        queue->front = 0;  
    }
    
    //other
    queue->back++;
    queue->line[queue->back] = ticket;
    queue->count++;
}