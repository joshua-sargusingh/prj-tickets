#include <stdio.h>
#include <stdlib.h>

#include "dequeue_all.h"

#define SIZE 10

void dequeue_all(struct Queue* queue) {
    if (queue->count == 0) {
        printf("no queue");
        exit(1);
    }

    while (queue->count != 0) {
        //current
        struct Ticket *current = queue->line[queue->front];
        printf("Seat: %d, SN: %d\n", current->seat_num, current->serial_num);
        free(current);
        queue->count--;
        queue->front++;
    }
}