#include "lib.h"

#include <stdio.h>
#include <stdlib.h>

LinkedList* create_list() {
    LinkedList* list = (LinkedList*) malloc(sizeof(LinkedList));

    list -> head = NULL;
    list -> count = 0;

    return list;
}

ListNode* new_node(int data) {
    ListNode* node = (ListNode*) malloc(sizeof(ListNode));

    node -> next = NULL;
    node -> data = data;

    return node;
}

void append(LinkedList* list, int data) {
    if (list -> head == NULL) {
        list -> head = new_node(data);
        list -> count++;

        return;
    }

    ListNode* current = list -> head;

    while (current -> next != NULL) {
        current = current -> next;
    } 

    current -> next = new_node(data);
    list -> count++;
}

void prepend(LinkedList* list, int data) {
    ListNode* node = new_node(data);

    node -> next = list -> head;
    list -> head = node;
    list -> count++;
}

void delete(LinkedList* list, int data) {
    if (list -> head == NULL) {
        return;
    }

    ListNode* current = list -> head;

    if (current -> data == data) {
        list -> head = current -> next;
        list -> count--;
        free(current);
    }

    ListNode* previous = current;

    while (current -> next != NULL) {
        if (current -> data == data) {
            previous -> next = current -> next;
            list -> count--;

            free(current);
            return;
        } 
        
        previous = current;
        current = current -> next;
    }
}

bool exists(LinkedList* list, int data) {
    if (list -> head == NULL) {
        return false;
    }

    ListNode* current = list -> head;

    while (current != NULL) {
        if (current -> data == data) {
            return true;
        }

        current = current -> next;
    }

    return false;
}

void print_list(LinkedList* list) {
    ListNode* root = list -> head;

    printf("List has %d nodes\n", list -> count);

    while (root != NULL) {
        if (root -> next == NULL) {
            printf("%d\n", root -> data);
            break;
        } else {
            printf("%d -> ", root -> data);
        }

        root = root -> next;
    }

}
