#include <stdio.h>
#include <stdbool.h>

#define SIZE 100

int list[SIZE];
int count = 0;  // current number of elements

// Check if the list is empty
bool isEmpty() {
    return count == 0;
}

// Check if the list is full
bool isFull() {
    return count == SIZE;
}

// Search for a value
int search(int value) {
    for (int i = 0; i < count; i++) {
        if (list[i] == value) {
            return i;  // return index if found
        }
    }
    return -1;  // not found
}

// Insert at the end
void insert(int value) {
    if (isFull()) {
        printf("List is full. Cannot insert %d\n", value);
        return;
    }
    list[count++] = value;
    printf("Inserted %d into the list\n", value);
}

// Delete a value
void delete(int value) {
    if (isEmpty()) {
        printf("List is empty. Cannot delete %d\n", value);
        return;
    }

    int found = search(value);
    if (found == -1) {
        printf("Value %d not found in the list\n", value);
        return;
    }

    // Shift elements left to fill the gap
    for (int i = found; i < count - 1; i++) {
        list[i] = list[i + 1];
    }
    count--;
    printf("Deleted %d from the list\n", value);
}

// Display the list
void display() {
    if (isEmpty()) {
        printf("List is empty\n");
        return;
    }

    printf("List contents: ");
    for (int i = 0; i < count; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");
}

// Main function to test
int main() {
    insert(10);
    insert(20);
    insert(30);
    display();

    int index = search(20);
    if (index != -1)
        printf("Value 20 found at index %d\n", index);
    else
        printf("Value 20 not found\n");

    index = search(100);
    if (index != -1)
        printf("Value 100 found at index %d\n", index);
    else
        printf("Value 100 not found\n");

    delete(20);
    display();

    return 0;
}
// -> OUTPUT
// Inserted 10 into the list
// Inserted 20 into the list
// Inserted 30 into the list
// List contents: 10 20 30 
// Value 20 found at index 1
// Value 100 not found
// Deleted 20 from the list
// List contents: 10 30 