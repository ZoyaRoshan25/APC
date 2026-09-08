#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUCCESS 0
#define FAILURE -1

typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
}list;

/* List functions */
void insert_at_last(list **head, list **tail, int data);
void insert_at_first(list **head, list **tail, int data);
void print_list(list *head);

/* Conversion */
void convert_to_list(char *str, list **head, list **tail);

/* Operations */
int addition(list **tail1, list **tail2, list **headR, list **tailR);
int subtraction(list *head1, list *tail1, list *head2, list *tail2, list **headR, list **tailR);
int multiplication(list *tail1, list *tail2, list **headR, list **tailR);
int division(list *head1, list *tail1,list *head2, list *tail2,list **headR, list **tailR);

#endif