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

// Delete complete list 
void delete_list(list **head, list **tail)
{
    list *temp;

    while (*head != NULL)
    {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }

    *tail = NULL;
}

// Copy one list into another
void copy_list(list *src, list **head, list **tail)
{
    while (src != NULL)
    {
        insert_at_last(head, tail, src->data);
        src = src->next;
    }
}

int compare_lists(list *head1, list *head2)
{
    int count1 = 0;
    int count2 = 0;

    list *temp1 = head1;
    list *temp2 = head2;

    //Count digits 
    while (temp1 != NULL)
    {
        count1++;
        temp1 = temp1->next;
    }

    while (temp2 != NULL)
    {
        count2++;
        temp2 = temp2->next;
    }

    // Compare number of digits 
    if (count1 > count2)
        return 1;

    if (count1 < count2)
        return -1;

    // Same number of digits - compare digit by digit 
    temp1 = head1;
    temp2 = head2;

    while (temp1 != NULL)
    {
        if (temp1->data > temp2->data)
            return 1;

        if (temp1->data < temp2->data)
            return -1;

        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    return 0;
}