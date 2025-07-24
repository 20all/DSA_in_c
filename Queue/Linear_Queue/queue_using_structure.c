#include<stdio.h>
#include<stdbool.h>

#define MAX_SIZE 5

typedef struct queue {
    int elements[MAX_SIZE];
    int rear;
    int front;
}Queue;

void createQueue(Queue *q) {
    q->rear = -1;
    q->front = -1;
}

// method to check the Underflow
bool isEmpty(Queue *q) {
    return q->front == -1 || q->front>q->rear;
}

// method to check the Overflow
bool isFull(Queue *q) {
    return q->rear == MAX_SIZE - 1;
}

// method to enqueue an element
void enqueue(Queue *q, int data) {
    if(isFull(q)) {
        printf("Couldn't enqueue '%d' (Queue Overflow)\n",data);
        return;
    } else {
        if(isEmpty(q))
            q->front = 0;
        q->elements[++q->rear] = data;
        printf("'%d' enqueued \n",data);
    }
}

// method to dequeue an element
void dequeue(Queue *q) {
    if(isEmpty(q)) {
        printf("Couldn't dequeue (Queue Underflow)\n");
        return;
    } else {
        int dequeuedItem = q->elements[q->front++];
        // if(q.front > q.rear)
        //     createQueue(q);
        printf("Dequeued '%d'\n",dequeuedItem);
    }
}

// method to traverse and display all the elements of the queue
void display(Queue *q) {
    if(isEmpty(q)) {
        printf("Couldn't display (Queue is empty)\n");
        return;
    } else {
        printf("Queue Elements:\n");
        printf("[ ");
        for(int i = q->front; i <= q->rear; i++) {
            printf(" %d ",q->elements[i]);
        }
        printf(" ]");
        printf("\n Front : %d Rear : %d\n",q->front,q->rear);
        printf("\n");
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