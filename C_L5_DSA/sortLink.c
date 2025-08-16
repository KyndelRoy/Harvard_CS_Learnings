// Implements a sorted linked list of numbers (without CS50 library)

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
} node;

int main(void)
{
    node *list = NULL; // start with empty list

    // Build list
    for (int i = 0; i < 3; i++)
    {
        // Allocate memory for a new node
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            fprintf(stderr, "Memory allocation failed\n");
            return 1;
        }

        // Ask the user for a number (standard C way)
        printf("Number: ");
        scanf("%d", &n->number);

        n->next = NULL;

        // Case 1: If list is empty
        if (list == NULL)
        {
            list = n;
        }
        // Case 2: If number belongs at beginning of list
        else if (n->number < list->number)
        {
            n->next = list;
            list = n;
        }
        // Case 3: Insert somewhere later in list
        else
        {
            for (node *ptr = list; ptr != NULL; ptr = ptr->next)
            {
                // End of list → append
                if (ptr->next == NULL)
                {
                    ptr->next = n;
                    break;
                }

                // Middle of list → insert before larger number
                if (n->number < ptr->next->number)
                {
                    n->next = ptr->next;
                    ptr->next = n;
                    break;
                }
            }
        }
    }

    // Print all numbers in sorted order
    printf("\nSorted numbers:\n");
    for (node *ptr = list; ptr != NULL; ptr = ptr->next)
    {
        printf("%i\n", ptr->number);
    }

    // Free memory
    node *ptr = list;
    while (ptr != NULL)
    {
        node *next = ptr->next;
        free(ptr);
        ptr = next;
    }

    return 0;
}
