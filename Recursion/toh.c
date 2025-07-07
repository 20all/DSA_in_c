#include <stdio.h>

// Recursive function to solve Tower of Hanoi
void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod) {
    if (n == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", from_rod, to_rod);
        return;
    }

    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod); // Step 1: Move top n-1 disks to auxiliary
    printf("Move disk %d from rod %c to rod %c\n", n, from_rod, to_rod); // Step 2: Move nth disk to target
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod); // Step 3: Move n-1 disks from auxiliary to destination
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    printf("Sequence of moves:\n");
    towerOfHanoi(n, 'A', 'C', 'B');  // A = source, C = destination, B = auxiliary

    return 0;
}
// -> OUTPUT
// Enter the number of disks: 3
// Sequence of moves:
// Move disk 1 from rod A to rod C
// Move disk 2 from rod A to rod B
// Move disk 1 from rod C to rod B
// Move disk 3 from rod A to rod C
// Move disk 1 from rod B to rod A
// Move disk 2 from rod B to rod C
// Move disk 1 from rod A to rod C