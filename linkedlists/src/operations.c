#include "../linkedlists.h"

int list_length(node *head)
{
    node *current;
    current = head;
    int i = 0;
    while(current != NULL)
    {
        current = current->next;
        i++;
    }
    return(i);
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

    printf("\nLinked list length: %d\n", list_length(list1_head));
    
    printf("\nBefore delete:\n\n");
    print_list(list1_head);

    list1_head = delete_at_head(list1_head);

    printf("\nAfter delete(head):\n\n");
    print_list(list1_head);

    list1_head = delete_at_tail(list1_head);

    printf("\nAfter delete(tail):\n\n");
    print_list(list1_head);
} 