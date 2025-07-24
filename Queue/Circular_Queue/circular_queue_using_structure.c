#include <stdio.h>
#include <stdbool.h>
#define MAX_SIZE 5

typedef struct cQueue {
    int elements[MAX_SIZE];
    int front;
    int rear;
} CQueue;

void initialize(CQueue *cq) {
    cq->front = cq->rear = -1;
}

bool isEmpty(CQueue *cq) {
    return cq->front == -1;
}

bool isFull(CQueue *cq) {
    return cq->front == (cq->rear +1) % MAX_SIZE;
}

void enqueue(CQueue *cq, int data) {
    if(isFull(cq)) {
        printf("Couldn't enqueue '%d' (Circular_Queue Overflow)\n",data);
        return;
    } else {
        if(isEmpty(cq)) { 
            cq->front = cq->rear = 0; // set front and rear to 0 if cQueue is empty(when front and rear == -1)
        } else {
            cq->rear = (cq->rear+1)%MAX_SIZE;
        }
        cq->elements[cq->rear] = data;
        printf("'%d' enqueued \n",data);
    }
}

void dequeue(CQueue *cq) {
    if(isEmpty(cq)) {
        printf("Couldn't dequeue (Circular_Queue Underflow)\n");
        return;
    } else {
        int dequeuedItem = cq->elements[cq->front];
        if(cq->front == cq->rear) {
            initialize(cq);
            // cq->front = cq->rear = -1;
        } else {
            cq->front = (cq->front+1)%MAX_SIZE;
        }
        printf("Dequeued '%d'\n",dequeuedItem);
    }
}

void display(CQueue *cq) {
    if(isEmpty(cq)) {
        printf("Couldn't display (Circular_Queue is empty)\n");
        return;
    } else {
        printf("Circular-Queue elements:\n");
        printf(">--[ ");
        // for(int i = cq->front; i <= cq->rear; i++) {
        //     printf(" %d_ ",cq->elements[i]);
        // }
        int counter = 0;
        int i = cq->front;
        while (1) {
            printf("  %d_ ",cq->elements[i]);
            counter++;
            if(i == cq->rear) break;
            i = (i +1) % MAX_SIZE;
        }
        printf(" ]-->");
        printf("\nFront: %d and Rear: %d\n",cq->front, cq->rear);
        // int availableSpace = (cq->front)%MAX_SIZE + (MAX_SIZE - (cq->rear)%MAX_SIZE) -1 ;// (front+1)%MAX_SIZE + (MAX_SIZE - (rear+1)%MAX_SIZE)
        int availableSpace = MAX_SIZE - counter;
        printf("Available space: %d units\n\n",availableSpace);
    }
}

int main() {
    CQueue q;
    initialize(&q);
    display(&q);
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    enqueue(&q, 5);
    display(&q);
    enqueue(&q, 1); // inserting while the queue is full
    // deleting for making some space
    dequeue(&q);
    display(&q);
    dequeue(&q);
    display(&q);
    // inserting after deleting and making some space
    enqueue(&q,6);
    display(&q);
    enqueue(&q,7);
    display(&q);
    enqueue(&q,6);
    display(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    display(&q);
    dequeue(&q);
    display(&q);
    return 0;
}