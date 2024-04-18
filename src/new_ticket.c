#include <stdio.h>
#include <stdlib.h>

#include "new_ticket.h"

struct Ticket* new_ticket(int seat, int serial) {
    struct Ticket* new_ticket = (struct Ticket*)malloc(sizeof(struct Ticket));
    
    if (new_ticket == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    new_ticket->seat_num = seat;
    new_ticket->serial_num = serial;

    return new_ticket;
}