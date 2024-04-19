#include <stdio.h>

#include "queue.h"
#include "new_ticket.h"
#include "enqueue.h"
#include "dequeue_all.h"

int main() {
    //init
    struct Queue queue;

    queue.count = 0;
    queue.back = -1;
    queue.front = -1;

    int ticket_count = 0;

    printf("How many tickets (0-10) do you want?\n");

    if (scanf("%d", &ticket_count) != 1) {
        printf("Invalid entry.\n");
        return 1;  // Return 1 to indicate failure
    }

    if (ticket_count <= 0 || ticket_count > 10) {
        printf("Invalid amount of tickets.\n");
        return 1;  // Return 1 to indicate failure
    }

    for (int i = 0;i<ticket_count;++i)  {
        enqueue(&queue, new_ticket(i,i+100));
    }

    //dequeue
    printf("Tickets:\n");
    
    dequeue_all(&queue);

    return 0;
}