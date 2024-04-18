#include <stdio.h>
#include "gtest/gtest.h"
#include "queue.h"
#include "new_ticket.h"
#include "enqueue.h"
#include "dequeue_all.h"

// Test fixture for Queue related tests
class QueueTest : public ::testing::Test {
protected:
    struct Queue queue;

    void SetUp() override {
        queue.count = 0;
        queue.back = -1;
        queue.front = -1;
    }
};

// Test case for creating a new ticket
TEST_F(QueueTest, NewTicketTest) {
    struct Ticket *ticket = new_ticket(1, 101);
    EXPECT_NE(ticket, nullptr);  // Check if ticket is not null
    EXPECT_EQ(ticket->seat_num, 1);  // Check if seat number is correct
    EXPECT_EQ(ticket->serial_num, 101);  // Check if serial number is correct
    free(ticket);  // Free allocated memory
}

// Test case for enqueueing a ticket
TEST_F(QueueTest, EnqueueTest) {
    struct Ticket *ticket = new_ticket(2, 202);
    enqueue(&queue, ticket);
    EXPECT_EQ(queue.count, 1);  // Check if count is updated after enqueue
    EXPECT_EQ(queue.front, 0);  // Check if front is updated after enqueue
    EXPECT_EQ(queue.back, 0);  // Check if back is updated after enqueue
}

// Test case for dequeueing all tickets
TEST_F(QueueTest, DequeueAllTest) {
    struct Ticket *ticket1 = new_ticket(3, 303);
    struct Ticket *ticket2 = new_ticket(4, 404);
    enqueue(&queue, ticket1);
    enqueue(&queue, ticket2);
    
    // Call the function to be tested
    dequeue_all(&queue);

    // Perform assertions to verify the results
    EXPECT_EQ(queue.count, 0);  // Check if count is updated after dequeue_all
    EXPECT_EQ(queue.front, -1);  // Check if front is updated after dequeue_all
    EXPECT_EQ(queue.back, -1);  // Check if back is updated after dequeue_all
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}