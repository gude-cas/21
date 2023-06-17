#include "../linkedlists.h"

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

// int main(void)
// {
//     node *list1_head = NULL;

//     list1_head = insert_at_head(list1_head, 7);
//     list1_head = insert_at_head(list1_head, 5);
//     list1_head = insert_at_head(list1_head, 3);

//     list1_head = insert_at_tail(list1_head, 10);
//     list1_head = insert_at_tail(list1_head, 12);
//     list1_head = insert_at_tail(list1_head, 14);

//     print_list(list1_head);
// }