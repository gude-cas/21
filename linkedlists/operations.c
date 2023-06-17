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

node *insert_at_tail(node *head, int new_value)
{
    node *new_node = malloc(sizeof(node));
    new_node->value = new_value;
    if (head == NULL)
        return (new_node);
    else
    {
        node *current = head;
        while (current->next != NULL)
            current = current->next;
        current->next = new_node;
        return (head);
    }
}

node *insert_at_head(node *head, int new_value)
{
    node *new_node = malloc(sizeof(node));
    new_node->value = new_value;
    if (head == NULL)
        return (new_node);
    else
    {
        new_node->next = head;
        return (new_node);
    }
}

node *delete_at_head(node *head)
{
    if (head == NULL)
        return (NULL);
    else
    {
        node *new_head = head->next;
        free(head);
        return (new_head);
    }
}

node *delete_at_tail(node *head)
{
    if (head == NULL)
        return (NULL);
    else if (head->next == NULL)
    {
        free(head);
        return (NULL);
    }
    else
    {
        node *current = head;
        node *prev = NULL;
        while (current->next != NULL)
        {
            prev = current;
            current = current->next;
        }
        prev->next = NULL;
        free(current);
        return (head);
    }
}

/*same as list_length but recursive*/
// int recursive_length(node *anode)
// {
//     if(anode == NULL)
//         return(0);
//     else
//         return (1 + recursive_length(anode->next));
// }

int list_length(node *head)
{
    node *current;
    current = head;
    int i = 0;
    while (current != NULL)
    {
        current = current->next;
        i++;
    }
    return (i);
}

/*finding a value in a node on the list*/
int is_member(node *anode, int find_value)
{
    if (anode == NULL)
        return (0);
    else if (anode->value == find_value)
        return (1);
    else
        return (is_member(anode->next, find_value));
}

/*count the amount of nodes with a matching value*/
int count_matches(node *anode, int find_value)
{
    if (anode == NULL)
        return (0);
    else if (anode->value == find_value)
        return (1 + count_matches(anode->next, find_value));
    else
        return (count_matches(anode->next, find_value));
}

/*replace the value of a node*/
void replace_matches(node *anode, int find_value, int replace_value)
{
    if (anode != NULL)
    {
        if (anode->value == find_value)
            anode->value = replace_value;
        replace_matches(anode->next, find_value, replace_value);
    }
}

int main(void)
{
    node *list1_head = NULL;

    list1_head = insert_at_head(list1_head, 7);
    list1_head = insert_at_head(list1_head, 7);
    list1_head = insert_at_head(list1_head, 5);
    list1_head = insert_at_head(list1_head, 3);

    list1_head = insert_at_tail(list1_head, 10);
    list1_head = insert_at_tail(list1_head, 12);
    list1_head = insert_at_tail(list1_head, 10);
    list1_head = insert_at_tail(list1_head, 14);
    list1_head = insert_at_tail(list1_head, 10);

    print_list(list1_head);

    printf("\n'list_length'");
    printf("\nLength: %d\n", list_length(list1_head));

    printf("\n'is_member'");
    if (is_member(list1_head, 5))
        printf("\n5 is in the list!");
    else
        printf("\n5 is not in the list!");

    if (is_member(list1_head, 8))
        printf("\n8 is in the list!");
    else
        printf("\n8 is not in the list!\n");

    printf("\n'count_matches'\n");
    printf("Number of 7s: %d\n", count_matches(list1_head, 7));
    printf("Number of 8s: %d\n", count_matches(list1_head, 8));
    printf("Number of 10s: %d\n", count_matches(list1_head, 10));

    replace_matches(list1_head, 10, 18);

    printf("\n'replace_matches'");
    printf("\nList after replacement(10s for 18s):\n");
    print_list(list1_head);
}
