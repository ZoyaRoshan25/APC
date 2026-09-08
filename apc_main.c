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
   argv[2][0] != '*' &&
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

    convert_to_list(argv[1],&head1,&tail1);
    convert_to_list(argv[3],&head2,&tail2);

    switch (argv[2][0])
    {
        case '+':
            addition(&tail1, &tail2, &headR, &tailR);
            break;

        case '-':
            subtraction(head1, tail1, head2, tail2,&headR, &tailR);
            break;

        case '*':
            //multiplication(tail1, tail2, &headR, &tailR);
            break;

        case '/':
            //division(head1, tail1, head2, tail2,&headR, &tailR);
            break;
    }

    /* Print result */
    print_list(headR);

    return 0;
}