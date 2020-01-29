
#include <stdio.h>


void printIntInfo(int *p) {
    printf("the address is: %x\n", p);
    printf("the contents are: %d\n", *p);
    printf("-------------------------\n");
}

int main() {
    int x = 7;
    printIntInfo(&x);

    x = 12;
    printIntInfo(&x);

    int *aptr = &x;
    printIntInfo(aptr);

    aptr += 2; 
    printIntInfo(aptr);
}