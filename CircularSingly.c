#include <stdio.h>
#include <stdlib.h>

struct DNode {
    int data;
    struct DNode* next;
    struct DNode* prev;
};

// Function to create a new node
struct DNode* createDNode(int data) {
    struct DNode* newNode = (struct DNode*)malloc(sizeof(struct DNode));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to append a node at the end
void append(struct DNode** head_ref, int data) {
    struct DNode* newNode = createDNode(data);
    if (*head_ref == NULL) {
        *head_ref = newNode;
        return;
    }
    struct DNode* last = *head_ref;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = newNode;
    newNode->prev = last;
}

// Function to prepend a node at the beginning
void prepend(struct DNode** head_ref, int data) {
    struct DNode* newNode = createDNode(data);
    newNode->next = *head_ref;
    if (*head_ref != NULL) {
        (*head_ref)->prev = newNode;
    }
    *head_ref = newNode;
}

// Function to delete a node by value
void deleteNode(struct DNode** head_ref, int key) {
    struct DNode* temp = *head_ref;
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }
    if (temp == NULL) return;
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        *head_ref = temp->next;
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    free(temp);
}

// Function to print the doubly linked list
void printList(struct DNode* node) {
    while (node != NULL) {
        printf("%d <-> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Driver code
int main() {
    struct DNode* head = NULL;
    append(&head, 1);
    append(&head, 2);
    prepend(&head, 0);
    printList(head);    // Output: 0 <-> 1 <-> 2 <-> NULL
    deleteNode(&head, 1);
    printList(head);    // Output: 0 <-> 2 <-> NULL
    return 0;
}
