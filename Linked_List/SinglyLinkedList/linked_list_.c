#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;
Node *head = NULL;
Node *tail = NULL;

// creation of a node with data and pointing to null
Node *createNode(int item) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = item;
    newNode->next = NULL;
    return newNode;
}

// check if head is null
bool isEmpty() {
    return head == NULL;
}

// insert at first  
void insertAtFirst(int data) {
    Node *temp = createNode(data);
    if(isEmpty()) {
        head = temp;
        tail = temp;
        printf("Inserted %d at First\n",data);
    } else {
        temp->next = head;
        head = temp;
        printf("Inserted %d at First\n",data);
    }
}

// insert at end
void insertAtEnd(int data) {
    Node *temp = createNode(data);
    if(isEmpty()) {
        head = temp;
        tail = temp;
        printf("Inserted %d at End\n",data);
    } else {
        tail->next = temp;
        tail = temp;
        printf("Inserted %d at End\n",data);
    }
}

// insert at position
void insertAtPosition(int position, int data) {
    if(position < 0) {
        printf("!Invalid position!\n");
        return;
    } 
    if(position == 0) {
        insertAtFirst(data);
        printf("Inserted '%d' at position %d\n",data, position);
        return;
    }
    Node *temp = head;
    // for(int i = 0; i <= position-1; i++) {
    //     temp = temp->next;
    //     if(temp == NULL) {
    //         printf("Invalid position!\n");
    //         return;
    //     }
    // }
    int i = 0;
    while (i < position - 1 && temp != NULL) {
        temp = temp->next;
        i++;
    }
    if (temp == NULL) {
        printf("Invalid position!\n");
        return;
    }
    Node *newNode = createNode(data);
    newNode->next = temp->next;
    temp->next = newNode;
    if(temp==tail) { // condition if inserted at end
        tail = newNode;
    }
    printf("Inserted '%d' at position %d\n",data, position);
}

// deletion at first
void deleteAtFirst() {
    if(isEmpty()) {
        printf("Can't delete, Linked-List is empty!\n");
        return;
    } else {
        Node *temp = head;
        head = head->next;
        printf("Deleted at first, '%d'\n",temp->data);
        free(temp);

    }
}

// delete at end 
void deleteAtEnd() {
    if(isEmpty()) {
        printf("Can't delete. Linked-list if empty\n");
        return;
    }
    if(head == tail) {
        printf("Deleted at end, '%d'\n",tail->data);
        free(tail);
        head = NULL;
        tail = NULL;
    } else {
        Node *temp = head;
        while(temp->next!= tail) {
            temp = temp->next;
        }
        printf("Deleted at end, '%d'\n",tail->data);
        free(tail);
        tail = temp;
        temp->next = NULL;
    }
}

// delete at position
void deleteAtPosition(int position) {
    
}

// display the elements of the linkedlist
void display() {
    if(isEmpty()) {
        printf("LinkedList is empty!\n");
        return;
    } else {   
        Node *temp = head;
        printf("\nLiked-List elements:\n");
        printf("Head:>");
        while (temp!=NULL)
        {
            printf("%d-->",temp->data);
            temp = temp->next;
        }
        printf("-NULL\n");
        printf("Head : %d  Tail : %d\n\n",head->data, tail->data);
    }
}
int main() {
    display();
    insertAtFirst(10);
    display();
    insertAtFirst(20);
    display();
    insertAtFirst(30);
    display();
    insertAtEnd(11);
    display();
    insertAtFirst(15);
    display();
    deleteAtFirst();
    display();
    insertAtEnd(22);
    display();
    deleteAtEnd();
    display();
    insertAtPosition(1,35);
    display();
    insertAtPosition(4,45);
    display();
    insertAtPosition(0,5);
    display();
    return 0;
}