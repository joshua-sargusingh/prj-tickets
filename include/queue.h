#ifndef QUEUE_H
#define QUEUE_H

#include "new_ticket.h"

#define SIZE 10

struct Queue {
    struct Ticket* line[SIZE];
    int front, back;
    int count;
};

void enqueue(struct Queue* queue, struct Ticket* ticket);

void dequeue_all(struct Queue* queue);

#endif