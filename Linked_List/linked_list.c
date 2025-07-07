#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* head = NULL;

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    // if (newNode == NULL) {
    //     printf("Memory allocation failed!\n");
    //     exit(1); // Exit the program if malloc fails
    // }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Check if list is empty
bool isEmpty() {
    return head == NULL;
}

// Insert at the end
void insertAtEnd(int value) {
    Node* newNode = createNode(value);

    if (isEmpty()) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Insert at the beginning
void insertAtBeginning(int value) {
    Node* newNode = createNode(value);
    newNode->next = head;
    head = newNode;
}

// Delete a node by value
void deleteNode(int value) {
    if (isEmpty()) {
        printf("List is empty, can't delete %d\n", value);
        return;
    }

    if (head->data == value) {
        Node* toDelete = head;
        head = head->next;
        free(toDelete);
        printf("Deleted %d from the list\n", value);
        return;
    }

    Node* current = head;
    while (current->next != NULL && current->next->data != value) {
        current = current->next;
    }

    if (current->next == NULL) {
        printf("%d not found in the list\n", value);
    } else {
        Node* toDelete = current->next;
        current->next = current->next->next;
        free(toDelete);
        printf("Deleted %d from the list\n", value);
    }
}

// Display the list
void display() {
    if (isEmpty()) {
        printf("List is empty\n");
        return;
    }

    Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function to test
int main() {
    if (isEmpty()) {
        printf("List is currently empty.\n");
    }

    insertAtEnd(10);
    insertAtEnd(20);
    insertAtBeginning(5);
    insertAtEnd(30);
    display();

    deleteNode(20);
    display();

    deleteNode(5);
    deleteNode(100);  // not in list
    display();

    if (isEmpty()) {
        printf("List is empty now.\n");
    } else {
        printf("List is not empty.\n");
    }

    return 0;
}
// ->OUTPUT
// List is currently empty.
// Linked List: 5 -> 10 -> 20 -> 30 -> NULL
// Deleted 20 from the list
// Linked List: 5 -> 10 -> 30 -> NULL
// Deleted 5 from the list
// 100 not found in the list
// Linked List: 10 -> 30 -> NULL
// List is not empty.