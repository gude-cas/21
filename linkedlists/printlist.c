#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *next;
} node;

void print_list(node *head)
{
    node *current;
    current = head;
    int i = 1;
    while (current != NULL)
    {
        printf("Node %d: %d\n", i, current->value);
        current = current->next;
        i++;
    }
}

int main(void)
{
    node a;
    node b;
    node c;
    a.value = 5;
    b.value = 6;
    c.value = 7;
    a.next = &b;
    b.next = &c;
    c.next = NULL;

    print_list(&a);
}