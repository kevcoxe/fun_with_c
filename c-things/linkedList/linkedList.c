
#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"
#include "node.h"


void insertNode(struct Node** head_ref, int new_data) {
  struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
  new_node->data = new_data;
  new_node->next = *head_ref;
  *head_ref = new_node;
};


void deleteNode(struct Node** head_ref, int data) {
  struct Node* temp = *head_ref, *prev;

  if (temp != NULL && temp->data == data) {
    *head_ref = temp->next;
    free(temp);
    return;
  };

  while (temp != NULL && temp->data != data) {
    prev = temp;
    temp = temp->next;
  };

  if (temp == NULL) return;

  prev->next = temp->next;

  free(temp);

  return;
};


void printList(struct Node** head_ref) {

  struct Node* ptr;
  ptr = *head_ref;

  while (ptr != NULL) {
    printf("%d", ptr->data);
    ptr = ptr->next;
    if (ptr != NULL) {
      printf(" -> ");
    } else {
      printf(" -> NULL");
    };
  };
  printf("\n");
};


struct LinkedList createLinkedList(void) {
  struct Node* head = NULL;
  struct LinkedList newLinkedList = { head, insertNode, deleteNode, printList };

  return newLinkedList;
};

