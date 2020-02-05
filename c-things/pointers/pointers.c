
#include <stdio.h>
#include <stdlib.h>
#include "functions.h"


void printArray(int* A, int s) {
  for (int i = 0; i < s; i++) {
    printf("A[%d]: %d\n", i, A[i]);
  }
  return;
}

void showAddress(void) {
  int a;
  printf("Address of a: %p\n", &a);
  return;
}


int* createArray(int s) {
  int *A = (int*)malloc(s*sizeof(int));
  printArray(A, s);

  return A;
}


int* createArrayAndFill(int s) {
  int *A = (int*)malloc(s*sizeof(int));
  for (int i = 0; i < s; i++) {
    A[i] = i+1;
  }
  printArray(A, s);

  return A;
}


int main() {

  int x = 10;
  printf("x: %d\n", x);

  x = returnMe(x);
  printf("x: %d\n", x);


  int *xptr = &x;
  printf("xptr: %p\n", xptr);

  xptr = returnMePtr(xptr);
  printf("xptr: %p\n", xptr);

  int newX = getMe(xptr);
  printf("new x: %d\n", newX);

  void *v = getVoidPtr(xptr);
  printf("v: %p\n", v);

  int *vxp = v;
  int vx = *(vxp);
  printf("vx: %d\n", vx);

  int* bx;
  bx = goodAlloc();
  printf("bx: %d\n", *bx);
  printf("address of bx: %p\n", bx);
  free(bx);

  printf("bx: %d\n", *bx);
  printf("address of bx: %p\n", bx);

  printf("size of char: %d\n", (int)sizeof(char));
  printf("size of short: %d\n", (int)sizeof(short));
  printf("size of int: %d\n", (int)sizeof(int));
  printf("size of double: %d\n", (int)sizeof(double));

  int* A;
  A = createArrayAndFill(10);
  printf("address of A: %p\n", A);
  free(A);
  printArray(A, 10);

  showAddress();
  showAddress();

  return 0;
};
