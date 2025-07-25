#include<stdio.h>
void toh(int n, char S, char D, char T) {
    if(n > 0) {
        toh(n-1,S,T,D);
        printf("Move disk %d from '%c' to '%c'\n",n,S,D);
        toh(n-1,T,D,S);
    }
}
int main() {
    int n;
    printf("Enter the numner of disk: ");
    scanf("%d",&n);
    if(n <= 0 ) {
        printf("Invalid no of disks.!!\n");
    } else {
        toh(n,'S','D','T');
    }
    return 0;
}