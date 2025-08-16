#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
} node;

int main(void)
{
    // Memory for numbers
    node *list = NULL;

    // Build list
    for (int i = 0; i < 3; i++)
    {
        // Allocate node for number
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return 1;
        }
        n->number = i;
        n->next = NULL;

        // Prepend node to list
        n->next = list;
        list = n;
    }

    // Print list
    for (node *current = list; current != NULL; current = current->next)
    {
        printf("%i\n", current->number);
    }
    
    return 0;
}