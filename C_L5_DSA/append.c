#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
} node;

int main(void)
{
    node *list = NULL;

    // Build list of 3 nodes
    for (int i = 0; i < 3; i++)
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            fprintf(stderr, "Memory allocation failed\n");
            return 1;
        }

        n->number = i;
        n->next = NULL;

        if (list == NULL)
        {
            list = n;   // First node
        }
        else
        {
            for (node *ptr = list; ptr != NULL; ptr = ptr->next)
            {
                if (ptr->next == NULL)
                {
                    ptr->next = n;   // Append at end
                    break;
                }
            }
        }
    }

    // Print list
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