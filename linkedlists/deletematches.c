#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

/*delete a node matching the value*/
node *delete_first_match(node *head, int delete_value, bool *was_deleted)
{
    if (head == NULL)
    {
        *was_deleted = false;
        return (NULL);
    }

    if (head->value == delete_value)
    {
        node *tmp = head->next;
        free(head);
        *was_deleted = true;
        return (tmp);
    }

    node *current = head->next;
    node *prev = head;

    while (current != NULL)
    {
        if (current->value == delete_value)
        {
            prev->next = current->next;
            free(current);
            *was_deleted = true;
            return (head);
        }
        prev = current;
        current = current->next;
    }
    *was_deleted = false;
    return (head);
}

/*delete all nodes matching the value*/
node *delete_all_matches(node *head, int delete_value, int *num_deleted)
{
    node *current = head;
    bool deleted = false;
    *num_deleted = 0;
    do
    {
        current = delete_first_match(current, delete_value, &deleted);
        if (deleted)
            *num_deleted = *num_deleted + 1;
    } while (deleted);
    return (current);
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

    printf("List before any deletions...\n");
    print_list(list1_head);

    bool deleted;

    printf("\n'delete_first_match'\n");
    list1_head = delete_first_match(list1_head, 3, &deleted);
    if (deleted)
        printf("(testing 3)\nA node with value 3 was deleted!\n");
    else
        printf("(testing 3)\nNo node was deleted!\n");
    print_list(list1_head);

    list1_head = delete_first_match(list1_head, 99, &deleted);
    if (deleted)
        printf("(testing 99)\nA node with value 99 was deleted!\n");
    else
        printf("(testing 99)\nNo node was deleted!\n");
    print_list(list1_head);

    int num_deleted;

    printf("\n'delete_all_matches'\n");
    list1_head = delete_all_matches(list1_head, 10, &num_deleted);
    printf("%d 10s deleted\n", num_deleted);
    print_list(list1_head);
}
