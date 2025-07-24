#include<stdio.h>
#include<stdbool.h>
#define SIZE 5

typedef struct {
    int elements[SIZE];
    int front;
    int rear;
} Queue;

// create an empty queue
void createQueue(Queue *q) {
    q->front = 0;
    q->rear = -1;
}

// check for underflow
bool isEmpty(Queue *q) {
    return q->rear < q->front;
}

// check for Overflow
bool isFull(Queue *q) {
    return q->rear == SIZE-1;
}

// enqueue method
void enqueue(Queue *q, int data) {
    if(isFull(q)) {
        printf("Can't enqueue %d (Queue Overflow!)\n",data);
        return;
    } else {
        q->elements[++q->rear] = data;
        printf("Enqueued '%d'\n",data);
    }
}

// dequeue method
void dequeue(Queue *q) {
    if(isEmpty(q)) {
        printf("Can't dequeue (Queue Underflow!)\n");
        return;
    } else {
        int dequeuedItem = q->elements[q->front++];
        printf("%d dequeued\n",dequeuedItem);
    } 
}

void display(Queue *q) {
    if(isEmpty(q)) {
        printf("Can't display, Queue is empty\n");
        return;
    } else {
        printf("Queue elements:\n");
        printf("[ ");
        for(int i = q->front; i <= q->rear; i++) {
            printf(" %d ",q->elements[i]);
        }
        printf(" ]");
        printf("\nFront: %d  Rear: %d\n\n",q->front, q->rear);
    }
}
int main() {
    Queue Q;
    createQueue(&Q);
    display(&Q);
    enqueue(&Q, 10);
    enqueue(&Q, 20);
    enqueue(&Q, 30);
    enqueue(&Q, 40);
    enqueue(&Q, 50);
    display(&Q);
    enqueue(&Q, 1);
    dequeue(&Q);
    dequeue(&Q);
    dequeue(&Q);
    display(&Q);
    dequeue(&Q);
    dequeue(&Q);
    display(&Q);
    return 0;
}