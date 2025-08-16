#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

int main(void){
    Node *list = NULL;

    for (int i = 0; i < 3; i++) {
        Node *n = malloc(sizeof(Node));

        if (n == NULL){
            fprintf(stderr, "Memory allocation failed\n");
            return 1;
        }
        n->data = i; // Assign data to the new node
        n->next = list;
        list = n; // Insert node at the beginning of the list
    }

    for (Node *current = list; current != NULL; current = current->next) {
        printf("%d\n", current->data); // Print each node's data
    }

    while (list != NULL){
        Node *tmp = list->next; // Store next node
        free(list); // Free current node
        list = tmp; // Move to next node
    }
}