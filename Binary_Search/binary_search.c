#include<stdio.h>
int main() {
    int array[] = {1,2,3,4,5,6,7};
    int lowerIndex = 0;
    int upperIndex = 6;
    int mid;
    int searchItem;
    int flag = 0;
    printf("Enter the number to search: ");
    scanf("%d",&searchItem);

    while(lowerIndex <= upperIndex) {
        mid = (lowerIndex + upperIndex)/ 2;
        if(searchItem == array[mid]) {
            flag = 1;
            break;
        }
        if(array[mid] < searchItem) {
            lowerIndex = mid++;
        } else {
            upperIndex = mid--;
        }
    }
    if(flag == 1) {
        printf("Item found at index %d\n",mid);
    } else {
        printf("Item not found!\n");
    }
    return 0;
}