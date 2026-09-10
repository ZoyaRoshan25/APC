#include <stdio.h>
#include "apc_main.h"
#include <stdlib.h>

void convert_to_list(char *str, list **head, list **tail)
{
    int i = 0;
    while(str[i] != '\0')
    {
        insert_at_last(head, tail, str[i]-'0');
        i++;
    }
}

int main(int argc, char *argv[])
{
    if(argc != 4)
    {
        printf("usage: a.out <operand1> <operator> <opernd2>\n");
        return 0;
    }

    if(argv[2][0] != '+' &&
   argv[2][0] != '-' &&
   argv[2][0] != 'x' &&
   argv[2][0] != '/')
    {
        printf("Invalid operator\n");
        return 0;
    }

    list *head1 = NULL;
    list *tail1= NULL;

    list *head2 = NULL;
    list *tail2 = NULL;

    list *headR = NULL;
    list *tailR = NULL;

    int sign1 = 1;
    int sign2 = 1;
    int result_sign = 1;
    int cmp;

    //Get sign of operand 1 
    if (argv[1][0] == '-')
        sign1 = -1;

    //Get sign of operand 2
    if (argv[3][0] == '-')
        sign2 = -1;
   
    if (argv[1][0] == '+' || argv[1][0] == '-')
        convert_to_list(argv[1] + 1, &head1, &tail1);
    else
        convert_to_list(argv[1], &head1, &tail1);

    if (argv[3][0] == '+' || argv[3][0] == '-')
        convert_to_list(argv[3] + 1, &head2, &tail2);
    else
        convert_to_list(argv[3], &head2, &tail2);

    switch (argv[2][0])
    {
        case '+':
            // +op1 + +op2
            if (sign1 == 1 && sign2 == 1)
            {
                addition(tail1, tail2,&headR, &tailR);
                result_sign = 1;
            }
            // -op1 + -op2 
            else if (sign1 == -1 && sign2 == -1)
            {
                addition(tail1, tail2,&headR, &tailR);
                result_sign = -1;
            }
            // +op1 + -op2 
            else if (sign1 == 1 && sign2 == -1)
            {
                cmp = compare_lists(head1, head2);

                if (cmp == 0)
                {
                    insert_at_first(&headR, &tailR, 0);
                    result_sign = 1;
                }
                else if (cmp > 0)
                {
                    subtraction(head1, tail1,head2, tail2,&headR, &tailR);
                    result_sign = 1;
                }
                else
                {
                    subtraction(head2, tail2,head1, tail1,&headR, &tailR);
                    result_sign = -1;
                }
            }
            // -op1 + +op2 
            else
            {
                cmp = compare_lists(head1, head2);

                if (cmp == 0)
                {
                    insert_at_first(&headR, &tailR, 0);
                    result_sign = 1;
                }
                else if (cmp > 0)
                {
                    subtraction(head1, tail1,head2, tail2,&headR, &tailR);
                    result_sign = -1;
                }
                else
                {
                    subtraction(head2, tail2,head1, tail1,&headR, &tailR);
                    result_sign = 1;
                }
            }
            break;

        case '-':
            // +op1 - +op2 
            if (sign1 == 1 && sign2 == 1)
            {
                cmp = compare_lists(head1, head2);

                if (cmp == 0)
                {
                    insert_at_first(&headR, &tailR, 0);
                    result_sign = 1;
                }
                else if (cmp > 0)
                {
                    subtraction(head1, tail1,head2, tail2,&headR, &tailR);
                    result_sign = 1;
                }
                else
                {
                    subtraction(head2, tail2,head1, tail1,&headR, &tailR);
                    result_sign = -1;
                }
            }
            // +op1 - -op2
            else if (sign1 == 1 && sign2 == -1)
            {
                addition(tail1, tail2,&headR, &tailR);
                result_sign = 1;
            }
            // -op1 - +op2 
            else if (sign1 == -1 && sign2 == 1)
            {
                addition(tail1, tail2,&headR, &tailR);
                result_sign = -1;
            }
            // -op1 - -op2 
            else
            {
                cmp = compare_lists(head1, head2);

                if (cmp == 0)
                {
                    insert_at_first(&headR, &tailR, 0);
                    result_sign = 1;
                }
                else if (cmp > 0)
                {
                    subtraction(head1, tail1,head2, tail2,&headR, &tailR);
                    result_sign = -1;
                }
                else
                {
                    subtraction(head2, tail2,head1, tail1,&headR, &tailR);
                    result_sign = 1;
                }
            }
            break;

        case 'x':
            multiplication(tail1, tail2, &headR, &tailR);
            if (headR != NULL)
            {
                if (sign1 == sign2)
                    result_sign = 1;
                else
                    result_sign = -1;
            }
            break;

        case '/':
            division(head1, tail1, head2, tail2,&headR, &tailR);
            if (headR != NULL)
            {
                if (sign1 == sign2)
                    result_sign = 1;
                else
                    result_sign = -1;
            }
            break;
    }

    if (result_sign == -1 && !(headR != NULL && headR->data == 0 && headR->next == NULL))
    {
        printf("-");
    }

    print_list(headR);

    return 0;
}