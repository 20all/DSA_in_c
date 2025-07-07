#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node structure
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* head = NULL;
Node* tail = NULL;

// Create a new node
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Check if the list is empty
bool isEmpty() {
    return head == NULL;
}

// Insert at beginning
void insertAtBeginning(int value) {
    Node* newNode = createNode(value);
    if (isEmpty()) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    printf("Inserted %d at beginning\n", value);
}

// Insert at end
void insertAtEnd(int value) {
    Node* newNode = createNode(value);
    if (isEmpty()) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    printf("Inserted %d at end\n", value);
}

// Delete a node by value
void deleteNode(int value) {
    if (isEmpty()) {
        printf("List is empty, can't delete %d\n", value);
        return;
    }

    Node* temp = head;

    // Find the node to delete
    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("%d not found in the list\n", value);
        return;
    }

    // If node to delete is head
    if (temp == head) {
        head = head->next;
        if (head) head->prev = NULL;
        else tail = NULL; // List became empty
    }
    // If node to delete is tail
    else if (temp == tail) {
        tail = tail->prev;
        tail->next = NULL;
    }
    // Node is in the middle
    else {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }

    free(temp);
    printf("Deleted %d from the list\n", value);
}

// Display list forward
void displayForward() {
    if (isEmpty()) {
        printf("List is empty\n");
        return;
    }

    Node* temp = head;
    printf("Forward: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Display list backward
void displayBackward() {
    if (isEmpty()) {
        printf("List is empty\n");
        return;
    }

    Node* temp = tail;
    printf("Backward: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

// Main function to test
int main() {
    insertAtBeginning(10);
    insertAtEnd(20);
    insertAtEnd(30);
    insertAtBeginning(5);
    insertAtEnd(40);

    displayForward();
    displayBackward();

    deleteNode(5);    // delete head
    deleteNode(40);   // delete tail
    deleteNode(20);   // delete middle
    deleteNode(100);  // non-existent

    displayForward();
    displayBackward();

    if (isEmpty()) {
        printf("List is empty\n");
    } else {
        printf("List is not empty\n");
    }

    return 0;
}
// -> OUTPUT
// Inserted 10 at beginning
// Inserted 20 at end
// Inserted 30 at end
// Inserted 5 at beginning
// Inserted 40 at end
// Forward: 5 <-> 10 <-> 20 <-> 30 <-> 40 <-> NULL
// Backward: 40 <-> 30 <-> 20 <-> 10 <-> 5 <-> NULL
// Deleted 5 from the list
// Deleted 40 from the list
// Deleted 20 from the list
// 100 not found in the list
// Forward: 10 <-> 30 <-> NULL
// Backward: 30 <-> 10 <-> NULL
// List is not empty