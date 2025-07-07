#include<stdio.h>
#include<stdbool.h>
#define SIZE 5

int stack[SIZE];
int top = -1;

bool isEmpty() {
    return top == -1;
}

bool isFull() {
    return top == SIZE -1;
}

void push(int element) {
    if(isFull()) {
        printf("Can't push, Stack is full!\n");
    } else {
        stack[++top] = element;
        printf("Pushed %d into stack\n",element);
    }
}

int pop(){
    if(isEmpty()) {
        return -1;
    } else {
        int poppedElement = stack[top--];
        return poppedElement;
    }
}

int peek() {
    if(isEmpty()) {
        return -1;
    }
    return stack[top];
}

void display() {
    if(isEmpty()) {
        printf("Stack is empty, couldn't display!");
    } else {
        printf("Stack elements are:\n");
        for(int i = 0; i <= top; i++) {
            printf(" | %d |\t",stack[i]);
        }
        printf("\n");
    }
}

int main() {
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    display();
    printf("Top element : %d\n",peek());
    printf("Popped %d\n",pop());
    printf("Popped %d\n",pop());
    display();
    printf("Popped %d\n",pop());
    printf("Popped %d\n",pop());
    printf("Popped %d\n",pop());
    return 0;
}


// -> OUTPUT
// Pushed 1 into stack
// Pushed 2 into stack
// Pushed 3 into stack
// Pushed 4 into stack
// Pushed 5 into stack
// Stack elements are:
//  | 1 |   | 2 |   | 3 |   | 4 |   | 5 |
// Top element : 5
// Popped 5
// Popped 4
// Stack elements are:
//  | 1 |   | 2 |   | 3 |
// Popped 3
// Popped 2
// Popped 1