#include "apc_main.h"

int multiplication(list *tail1, list *tail2, list **headR, list **tailR)
{
    list *temp1;
    list *temp2;
    list *result;
    int carry;
    int product;
    int position = 0;

    //If either number is 0 
    if ((tail1 != NULL && tail1->data == 0 && tail1->prev == NULL) ||
        (tail2 != NULL && tail2->data == 0 && tail2->prev == NULL))
    {
        insert_at_first(headR, tailR, 0);
        return SUCCESS;
    }

    insert_at_first(headR, tailR, 0);

    temp2 = tail2;

    while (temp2 != NULL)
    {
        carry = 0;

        // Move to the end of current result position 
        temp1 = tail1;

        //Temporary list for current multiplication 
        list *tempHead = NULL;
        list *tempTail = NULL;

        //Add zeros according to position
        for (int i = 0; i < position; i++)
        {
            insert_at_first(&tempHead, &tempTail, 0);
        }

        //Multiply every digit of first number
        while (temp1 != NULL)
        {
            product = (temp1->data * temp2->data) + carry;

            insert_at_first(&tempHead, &tempTail, product % 10);

            carry = product / 10;

            temp1 = temp1->prev;
        }

        //Add remaining carry 
        if (carry != 0)
        {
            insert_at_first(&tempHead, &tempTail, carry);
        }

        
        //   Add the temporary result to final result.
        list *p1 = *tailR;
        list *p2 = tempTail;

        list *newHead = NULL;
        list *newTail = NULL;

        carry = 0;

        while (p1 != NULL || p2 != NULL || carry != 0)
        {
            int data1 = 0;
            int data2 = 0;

            if (p1 != NULL)
            {
                data1 = p1->data;
                p1 = p1->prev;
            }

            if (p2 != NULL)
            {
                data2 = p2->data;
                p2 = p2->prev;
            }

            product = data1 + data2 + carry;

            insert_at_first(&newHead, &newTail, product % 10);

            carry = product / 10;
        }

        // Delete old result 
        while (*headR != NULL)
        {
            list *del = *headR;

            *headR = (*headR)->next;

            free(del);
        }

        *tailR = NULL;

        //Copy new result 
        *headR = newHead;
        *tailR = newTail;

        // Delete temporary list 
        while (tempHead != NULL)
        {
            list *del = tempHead;

            tempHead = tempHead->next;

            free(del);
        }

        temp2 = temp2->prev;
        position++;
    }

    return SUCCESS;
}