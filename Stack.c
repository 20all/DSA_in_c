#include <stdio.h>
#include <stdbool.h>  // For using 'bool' type
#define MAXSIZE 5

int stack[MAXSIZE];  // Array to represent the stack
int top = -1;        // Stack top pointer

// Function to return the top element of the stack without removing it
int peek() {
    if (top != -1) {
        return stack[top];
    }
    printf("Stack is empty!\n");
    return -1;  // Return -1 if stack is empty
}

// Function to check if the stack is full
bool isFull() {
    return top == MAXSIZE - 1;
}

// Function to check if the stack is empty
bool isEmpty() {
    return top == -1;
}

// Function to push data onto the stack
void push(int data) {
    if (isFull()) {
        printf("Couldn't insert data, Stack is full!\n");
    } else {
        stack[++top] = data;
        printf("Pushed %d onto the stack\n", data);
    }
}

// Function to pop data from the stack
int pop() {
    if (isEmpty()) {
        printf("Couldn't retrieve(remove) data, Stack is empty!\n");
        return -1;  // Return -1 if stack is empty
    } else {
        int data = stack[top--];
        printf("Popped %d from the stack\n", data);
        return data;
    }
}

// Function to display the current stack elements
void display() {
    if (isEmpty()) {
        printf("Stack is empty!\n");
    } else {
        printf("Stack elements: ");
        for (int i = 0; i <= top; i++) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    // Perform stack operations
    display();
    push(10);  // Push 10
    push(20);  // Push 20
    push(30);  // Push 30
    display(); // Display stack

    // Peek the top element
    printf("Top element is: %d\n", peek());

    pop();     // Pop an element
    display(); // Display stack after pop

    push(40);  // Push 40
    push(50);  // Push 50
    push(60);  // Push 60 (Stack is full now)
    display(); // Display stack

    // Try pushing to a full stack
    push(70);  // Try pushing 70, stack is full

    return 0;
}
