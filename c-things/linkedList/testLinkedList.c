
#include <stdio.h>
#include "linkedList.h"


int main() {
  struct LinkedList myList = createLinkedList();

  myList.insert(&myList.head, 4);
  myList.insert(&myList.head, 3);
  myList.insert(&myList.head, 2);
  myList.insert(&myList.head, 1);

  myList.display(&myList.head);

  myList.delete(&myList.head, 3);
  myList.delete(&myList.head, 1);

  myList.display(&myList.head);

  return 0;
};
