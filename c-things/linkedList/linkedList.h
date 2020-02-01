
struct LinkedList {
  struct Node* head;
  void (*insert)(struct Node**, int);
  void (*delete)(struct Node**, int);
  void (*display)(struct Node**);
};


void insertNode(struct Node**, int);
void deleteNode(struct Node**, int);
void printList(struct Node**);

struct LinkedList createLinkedList(void);

