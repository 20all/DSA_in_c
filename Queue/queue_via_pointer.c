#include<stdio.h>
int main() {
    int value = 5;
    int *pV = &value;
    int y = *pV;

    printf("%d\n",value);
    printf("%d\n",y);
    return 0;
}