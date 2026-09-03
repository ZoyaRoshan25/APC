#include <stdio.h>

typedef struct node 
{
    int data;
    struct node *prev;
    struct node *next;
}list;

void insert_at_last(list **head, list **tail, int data)
{
    list *new = malloc(sizeof(list));
    if(!new)
        return 0;
    new->data = data;
    new->prev = NULL;
    new->next = NULL;

    if(*head == NULL)
    {
        *head = new;
        *tail = new;
        return;
    }

    new->(*prev) = *tail;
    (*tail)
}
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

    if(argv[2] != '+' || argv[2] != '-' || argv[2] != '*' || argv[2] == '/')
    {
        printf("Invalid operator\n");
        return 0;
    }

    list *head1 = NULL;
    list *tail1= NULL;

    list *head2 = NULL;
    list *tail2 = NULL;

    convert_to_list(argv[1],&head1,&tail1);
    convert_to_list(argv[1],&head1,&tail2);


}