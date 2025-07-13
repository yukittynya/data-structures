#ifndef LIB_H
#define LIB_H

typedef struct ListNode {
    struct ListNode* next;
    int data;
} ListNode;

typedef struct {
    ListNode* head;
    unsigned int count;
} LinkedList;

LinkedList* create_list();
ListNode* new_node(int data);

void append(LinkedList* list, int data);
void prepend(LinkedList* list, int data);

void delete(LinkedList* list, int data);

void print_list(LinkedList* list);

#endif // !LIB_H
