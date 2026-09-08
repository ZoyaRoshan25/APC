#include "apc_main.h"

void print_list(list *head)
{
    while (head != NULL)
    {
        printf("%d", head->data);
        head = head->next;
    }

    printf("\n");
}
