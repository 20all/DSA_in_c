#include <stdio.h>
#include <stdbool.h>
#define SIZE 5

typedef struct {
    int data;
    int priority;
} Queue;

Queue pQueue[SIZE];
int count = 0;

bool isEmpty() {
    return count == 0;
}
 
bool isFull() {
    return count == SIZE;
}

void enqueue(int data, int priority) {
    if(isFull()) {
        printf("Priority queue is Full, couldn't enqueue %d\n",data);
        return;
    } 
    int i = count -1;
    // Shift elements to make space for the new element
    while(i >= 0 && pQueue[i].priority < priority) {
        pQueue[i+1] = pQueue[i];
        i--;
    }
    // Insert new element at correct position
    pQueue[i+1].data = data;
    pQueue[i+1].priority = priority;
    count++;
    printf("Enqueued %d with priority %d\n",data, priority);
}

// Dequeue highest-priority element
int dequeue() {
    if (isEmpty()) {
        printf("Priority Queue is empty, couldn't dequeue\n");
        return -1;
    }

    int item = pQueue[0].data;
    for (int i = 0; i < count - 1; i++) {
        pQueue[i] = pQueue[i + 1];
    }
    count--;

    return item;
}

void display() {
    if (isEmpty()) {
        printf("Priority Queue is empty\n");
        return;
    }

    printf("Priority Queue contents:\n");
    for (int i = 0; i < count; i++) {
        printf("| Data: %d, Priority: %d |\n", pQueue[i].data, pQueue[i].priority);
    }
}


int main() {
    enqueue(10, 2);
    enqueue(20, 4);
    enqueue(30, 3);
    enqueue(40, 4);
    enqueue(50, 1);

    display();

    printf("Dequeued: %d\n", dequeue());
    printf("Dequeued: %d\n", dequeue());

    display();

    return 0;
}

// -> OUTPUT
// Enqueued 10 with priority 2
// Enqueued 20 with priority 4
// Enqueued 30 with priority 3
// Enqueued 40 with priority 4
// Enqueued 50 with priority 1
// Priority Queue contents:
// | Data: 20, Priority: 4 |
// | Data: 40, Priority: 4 |
// | Data: 30, Priority: 3 |
// | Data: 10, Priority: 2 |
// | Data: 50, Priority: 1 |
// Dequeued: 20
// Dequeued: 40
// Priority Queue contents:
// | Data: 30, Priority: 3 |
// | Data: 10, Priority: 2 |
// | Data: 50, Priority: 1 |