#include "apc_main.h"

void insert_at_last(list **head, list **tail, int data)
{
    list *new = malloc(sizeof(list));
    if(!new)
    {
        printf("Memory is not allocated for new node\n");
    }
    new->data = data;
    new->prev = NULL;
    new->next = NULL;

    if(*head == NULL)
    {
        *head = new;
        *tail = new;
        return;
    }

    new->prev = *tail;
    (*tail)->next = new;
    *tail = new;

}

void insert_at_first(list **head, list **tail, int data)
{
    list *new = malloc(sizeof(list));

    if (new == NULL)
        return;

    new->data = data;
    new->prev = NULL;
    new->next = NULL;

    if (*head == NULL)
    {
        *head = new;
        *tail = new;
        return;
    }

    new->next = *head;
    (*head)->prev = new;
    *head = new;
}