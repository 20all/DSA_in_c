#include <stdio.h>
#include <stdbool.h>
#define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;

bool isEmpty() {
    return front == -1;
}

bool isFull() {
    return (rear + 1)%SIZE == front; 
}

void enqueue(int item) {
    if(isFull()) {
        printf("Queue is Full, couldn't enqueue %d\n",item);
    } else {
        if(isEmpty()){
            front = rear = 0;
        } else {
            rear = (rear + 1) % SIZE;
        }
        queue[rear] = item;
        printf("enqueued %d \n",item);
    }
}

int dequeue() {
    if(isEmpty()) {
        printf("Queue is empty, couldn't dequeue!\n");
        return -1;
    } else {
        int dequeuedItem = queue[front];
        if(front == rear){
            // only one element is present
            front = rear = -1; 
        } else {
            front = (front + 1) % SIZE;
        }
        return dequeuedItem;
    }
}

void display() {
    if(isEmpty()) {
        printf("Coundn't display, Queue is empty\n");
        return;
    }
    int i = front;
    while (1) {
        printf(" | %d |\n",queue[i]);
        if(i == rear) break;
        i = (i +1) % SIZE;
    }
    printf("\nFront: %d and Rear: %d\n",front,rear);
}


int main() {
    display();
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    display();

    // Attempt to enqueue when full
    enqueue(60);

    printf("Dequeued %d\n", dequeue());
    printf("Dequeued %d\n", dequeue());
    display();

    // attempt to enqueue when there is some space left after dequeue
    enqueue(60);
    enqueue(70);
    display();

    printf("Dequeued %d\n", dequeue());
    printf("Dequeued %d\n", dequeue());
    printf("Dequeued %d\n", dequeue());
    printf("Dequeued %d\n", dequeue());
    printf("Dequeued %d\n", dequeue());
    display();

    return 0;
}