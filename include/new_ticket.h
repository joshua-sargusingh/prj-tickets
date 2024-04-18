#ifndef NEW_TICKET_H
#define NEW_TICKET_H

struct Ticket {
    int seat_num;
    int serial_num;
};

struct Ticket* new_ticket(int seat, int serial);

#endif