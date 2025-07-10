#include<stdio.h>
#include<stdbool.h>

#define MAX_SIZE 5

typedef struct {
    int elements[MAX_SIZE];
    int top;
}stack;


// struct Stack {
//     int elements[MAX_SIZE];
//     int top;
// };
// typedef struct Stack stack;

// method for creating a empty stack
void createStack(stack s) {
    s.top = -1;
}

// method for checking the Underflow
bool isEmpty(stack s) {
    return s.top == -1;
}

// method of checking the Overflow
bool isFull(stack s) {
    return s.top == MAX_SIZE-1;
}

// method of pushing an element
void push(stack s, int data) {
    if(isFull(s)) {
        printf("Couldn't push '%d' (Stack Overflow).\n",data);
        return;
    } else {
        s.elements[++s.top] = data;
        printf("'%d' pushed into the stack.\n",data);
    }
}

// method of popping an element
void pop(stack s) {
    if(isEmpty(s)) {
        printf("Couldn't pop (Stack Underflow)\n");
        return;
    } else {
        int poppedElement = s.elements[s.top--];
        printf("Popped '%d' from the stack\n",poppedElement);
    }
}

// method for peeking 
void peek(stack s) {
    if(isEmpty(s)) {
        printf("Couldn't peek (Stack is Empty)\n");
        return;
    } else {
        printf("Top element : %d\n",s.top);
    }
}

// method to display all the elements of the stack
void display(stack s) {
    if(isEmpty(s)) {
        printf("Couldn't display (Stack is Empty)\n");
        return;
    } else {
        for(int i = s.top; i >= 0; i++) {
            printf(" | %d |\n",s.elements[i]);
        }
        printf("\n");
        // // using while loop
        // int i = s.top;
        // while(i >= 0) {
        //     printf(" | %d |\n",s.elements[i]);
        //     i--;
        // }
        // printf("\n");
    }
}

int main() {
    stack S;
    createStack(S);
    display(S);
    push(S, 1);
    push(S, 2);
    push(S, 3);
    push(S, 4);
    push(S, 5);
    display(S);
    push(S, 1);
    pop(S);
    pop(S);
    display(S);
    peek(S);
    pop(S);
    pop(S);
    pop(S);
    return 0;
}