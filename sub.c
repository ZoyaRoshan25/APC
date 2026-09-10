#include "apc_main.h"

int subtraction(list *head1, list *tail1,list *head2, list *tail2,list **headR, list **tailR)
{
    list *temp1;
    list *temp2;
    int borrow = 0;
    int data1;
    int data2;
    int diff;
    int result;

    result = compare_lists(head1, head2);

    // Both numbers are equal 
    if (result == 0)
    {
        insert_at_first(headR, tailR, 0);
        return SUCCESS;
    }

    // If operand1 is greater 
    if (result == 1)
    {
        temp1 = tail1;
        temp2 = tail2;
    }
    else
    {
        /* If operand2 is greater */
        temp1 = tail2;
        temp2 = tail1;
    }

    // Subtract from right to left 
    while (temp1 != NULL)
    {
        data1 = temp1->data;
        data2 = 0;

        if (temp2 != NULL)
        {
            data2 = temp2->data;
            temp2 = temp2->prev;
        }

        data1 = data1 - borrow;

        if (data1 < data2)
        {
            data1 = data1 + 10;
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }

        diff = data1 - data2;

        insert_at_first(headR, tailR, diff);

        temp1 = temp1->prev;
    }

    // Remove leading zeros 
    while (*headR != NULL && (*headR)->data == 0 && (*headR)->next != NULL)
    {
        list *temp = *headR;

        *headR = (*headR)->next;
        (*headR)->prev = NULL;

        free(temp);
    }

    return SUCCESS;
}