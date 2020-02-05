#include <stdlib.h>
#include "functions.h"


int returnMe(int num) {
  return num;
}

int* returnMePtr(int *ptr) {
  return ptr;
}

int getMe(int *ptr) {
  return *(ptr);
}

void* getVoidPtr(int *x) {
  return x;
}

int* goodAlloc(void) {
  int *x = (int*)malloc(sizeof(int));
  *x = 10;
  return x;
}
