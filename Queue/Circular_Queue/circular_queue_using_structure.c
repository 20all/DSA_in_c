#include <stdio.h>
#include <stdbool.h>
#define MAX_SIZE 5

typedef struct cQueue {
    int elements[MAX_SIZE];
    int front;
    int rear;
} CQueue;

void initialize(CQueue cq) {
    cq.front = cq.rear = MAX_SIZE -1;
}

bool isEmpty(CQueue cq) {
    return cq.rear == cq.front;
}

bool isFull(CQueue cq) {
    return cq.front == (cq.rear +1) % MAX_SIZE;
}

void enqueue(CQueue cq, int data) {
    if(isFull(cq)) {
        printf("Couldn't enqueue '%d' (Circular_Queue Overflow)\n",data);
        return;
    } else {
        cq.rear = (cq.rear +1) % MAX_SIZE;
        cq.elements[cq.rear] = data;
        printf("'%d' enqueued \n",data);
    }
}

void dequeue(CQueue cq) {
    if(isEmpty(cq)) {
        printf("Couldn't dequeue (Circular_Queue Underflow)\n");
        return;
    } else {
        cq.front = (cq.front+1)%MAX_SIZE;
        int dequeuedItem = cq.elements[cq.front];
        printf("'%d' dequeued\n",dequeuedItem);
    }
}

void display(CQueue cq) {
    if(isEmpty(cq)) {
        printf("Couldn't display (Circular_Queue is empty)\n");
        return;
    } else {
        for(int i = (cq.front+1)%MAX_SIZE; i != cq.rear; i = (i+1)%MAX_SIZE) {
            printf(" |%d| ",cq.elements[i]);
        }
        printf("Front: %d and Rear: %d\n",cq.front, cq.rear);
    }
}

int main() {
    CQueue q;
    initialize(q);
    display(q);
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    enqueue(q, 5);
    display(q);
    // inserting while the queue is full
    enqueue(q, 1);
    // deleting for making some space
    dequeue(q);
    dequeue(q);
    // inserting after deleting and making some space
    enqueue(q,6);
    enqueue(q,7);
    enqueue(q,6);
    display(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    return 0;
}