#ifndef LINKEDLISTS_H
#define LINKEDLISTS_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *next;
} node;

void print_list(node *head);
node *insert_at_head(node *head, int new_value);
node *insert_at_tail(node *head, int new_value);
node * delete_at_head(node *head);
node *delete_at_tail(node *head);
int list_length(node *head);

#endif