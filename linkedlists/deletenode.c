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
    while(current != NULL)
    {
        printf("Node %d: %d\n", i, current->value);
        current = current->next;
        i++;
    }
}

node *insert_at_tail(node *head, int new_value)
{
    node *new_node = malloc(sizeof(node));
    new_node->value = new_value;
    if(head == NULL)
        return(new_node);
    else
    {
        node *current = head;
        while(current->next != NULL)
            current = current->next;
        current->next = new_node;
        return(head);
    }
}

node *insert_at_head(node *head, int new_value)
{
    node *new_node = malloc(sizeof(node));
    new_node->value = new_value;
    if(head == NULL)
        return(new_node);
    else
    {
        new_node->next = head;
        return(new_node);
    }
}

node * delete_at_head(node *head)
{
    if(head == NULL)
        return(NULL);
    else
    {
        node *new_head = head->next;
        free(head);
        return(new_head);
    }
}

node *delete_at_tail(node *head)
{
    if(head == NULL)
        return(NULL);
    else if(head->next == NULL)
    {
        free(head);
        return(NULL);
    }
    else
    {
        node *current = head;
        node *prev = NULL;
        while(current->next != NULL)
        {
            prev = current;
            current = current->next;
        }
        prev->next = NULL;
        free(current);
        return(head);
    }
}

int main(void)
{
    node *list1_head = NULL;

    list1_head = insert_at_head(list1_head, 7);
    list1_head = insert_at_head(list1_head, 5);
    list1_head = insert_at_head(list1_head, 3);

    list1_head = insert_at_tail(list1_head, 10);
    list1_head = insert_at_tail(list1_head, 12);
    list1_head = insert_at_tail(list1_head, 14);

    printf("\nBefore delete(head):\n\n");
    print_list(list1_head);

    list1_head = delete_at_head(list1_head);
    list1_head = delete_at_head(list1_head);

    printf("\nAfter delete(head):\n\n");
    print_list(list1_head);

    printf("\nBefore delete(tail):\n\n");
    print_list(list1_head);

    list1_head = delete_at_tail(list1_head);
    list1_head = delete_at_tail(list1_head);

    printf("\nAfter delete(tail):\n\n");
    print_list(list1_head);


} 