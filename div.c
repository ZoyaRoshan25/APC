#include "apc_main.h"
 
int division(list *head1, list *tail1, list *head2, list *tail2, list **headR, list **tailR)
{
    list *temp;
    list *remHead = NULL;
    list *remTail = NULL;

    list *tempDivHead = NULL;
    list *tempDivTail = NULL;

    int qdigit;

    // Division by zero 
    if (head2 == NULL)
    {
        printf("Division by zero is not possible\n");
        return FAILURE;
    }

    //Check if divisor is zero 
    temp = head2;

    while (temp != NULL)
    {
        if (temp->data != 0)
            break;

        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Division by zero is not possible\n");
        return FAILURE;
    }

    // If dividend is zero 
    temp = head1;

    while (temp != NULL && temp->data == 0)
        temp = temp->next;

    if (temp == NULL)
    {
        insert_at_first(headR, tailR, 0);
        return SUCCESS;
    }

    temp = head1;

    while (temp != NULL)
    {
        // remainder = remainder * 10 + current digit 

        if (remHead == NULL)
        {
            insert_at_last(&remHead, &remTail, temp->data);
        }
        else
        {
            insert_at_last(&remHead, &remTail, temp->data);
        }

        // Remove leading zeros 
        while (remHead != NULL &&
               remHead->data == 0 &&
               remHead->next != NULL)
        {
            list *del = remHead;

            remHead = remHead->next;
            remHead->prev = NULL;

            free(del);
        }

        if (remHead == NULL)
            remTail = NULL;

        qdigit = 0;

        while (compare_lists(remHead, head2) >= 0)
        {
            tempDivHead = NULL;
            tempDivTail = NULL;

        subtraction(remHead, remTail,head2, tail2,&tempDivHead, &tempDivTail);

        delete_list(&remHead, &remTail);

        remHead = tempDivHead;
        remTail = tempDivTail;

        qdigit++;
    }

        // Store quotient digit 
        insert_at_last(headR, tailR, qdigit);

        temp = temp->next;
    }

    // Remove leading zeros from quotient 
    while (*headR != NULL &&
           (*headR)->data == 0 &&
           (*headR)->next != NULL)
    {
        list *del = *headR;

        *headR = (*headR)->next;
        (*headR)->prev = NULL;

        free(del);
    }

    if (*headR == NULL)
        insert_at_first(headR, tailR, 0);

    // remHead contains the remainder 

    return SUCCESS;
}