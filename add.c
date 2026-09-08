#include "apc_main.h"

int addition(list **tail1, list **tail2, list **headR, list **tailR)
{
    int sum, carry = 0;
    list *temp1 = *tail1;
    list *temp2 = *tail2;

    while(temp1 != NULL || temp2 != NULL || carry != 0)
    {
        int data1 = 0;
        int data2 = 0;

        if (temp1 != NULL)
        {
            data1 = temp1->data;
            temp1 = temp1->prev;
        }

        if (temp2 != NULL)
        {
            data2 = temp2->data;
            temp2 = temp2->prev;
        }

        sum = data1 + data2 + carry;

        insert_at_first(headR, tailR, sum % 10);

        carry = sum / 10; 
    }

    return SUCCESS;
} 