#include<stdio.h>
#include<stdbool.h>
#define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;

bool isEmpty() {
    return front == -1;
}

bool isFull() {
    return rear == SIZE -1;
}

void enqueue(int item) {
    if(isFull()) {
        printf("Queue is Full, couldn't enqueue\n");
    } else {
        if(isEmpty())
            front = 0;
        queue[++rear] = item;
        printf("enqueued %d \n",item);
    }
}

int dequeue() {
    if(isEmpty()) {
        printf("Queue is empty, couldn't dequeue!\n");
        return -1;
    } else {
        int dequeuedItem = queue[front++];
        if(front > rear)
            front = rear = -1; // reseting the front and rear to -1
        return dequeuedItem;
    }
}

void display() {
    if(isEmpty()) {
        printf("Coundn't display, Queue is empty\n");
    } else {
        for(int i = front; i <= rear; i++) {
            printf(" | %d |\n",queue[i]);
        }
        printf("\nFront: %d and Rear: %d\n",front,rear);
    }
}


int main() {
    display();
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    enqueue(6);
    display();
    printf("Dequeued %d\n",dequeue());
    printf("Dequeued %d\n",dequeue());
    printf("Dequeued %d\n",dequeue());
    display();
    printf("Dequeued %d\n",dequeue());
    printf("Dequeued %d\n",dequeue());
    display();
    return 0;
}

// -> OUTPUT
// Coundn't display, Queue is empty
// enqueued 1 
// enqueued 2 
// enqueued 3 
// enqueued 4 
// enqueued 5 
// Stack is Full, couldn't enqueue
//  | 1 |
//  | 2 |
//  | 3 |
//  | 4 |
//  | 5 |

// Front: 0 and Rear: 4
// Dequeued 1
// Dequeued 2
// Dequeued 3
//  | 4 |
//  | 5 |

// Front: 3 and Rear: 4
// Dequeued 4
// Dequeued 5
// Coundn't display, Queue is empty