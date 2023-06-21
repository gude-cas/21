#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

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

/*efficiently delete all nodes matching the value*/
node *efficient_delete_match(node *head, int delete_value, int *num_deleted)
{
    if (head == NULL)
        return (NULL);
    node *current, *tmp, *new_head;
    current = head;
    *num_deleted = 0;
    while (current->value == delete_value)
    {
        tmp = current;
        current = current->next;
        free(tmp);
        *num_deleted = *num_deleted + 1;
        if (current == NULL)
            return (NULL);
    }
    new_head = current;
    while (current->next != NULL)
    {
        if (current->next->value == delete_value)
        {
            tmp = current->next;
            current->next = current->next->next;
            free(tmp);
            *num_deleted = *num_deleted + 1;
        }
        else
            current = current->next;
    }
    return (new_head);
}

/*joining two lists*/
node *append_list(node *head1, node *head2)
{
    if(head1 == NULL)
        return(head2);
    node *current = head1;
    while(current->next != NULL)
        current = current->next;
    current->next = head2;
    return(head1);
}

/*reversing a list*/
node *reverse_list(node *head)
{
    if(head == NULL)
        return(NULL);
    if(head->next == NULL)
        return(head);
    node *current = head;
    node *next_node = head->next;
    current->next = NULL;
    while(next_node != NULL)
    {
        node *tmp =  next_node->next;
        next_node->next = current;
        current = next_node;
        next_node = tmp;
    }
    return(current);
}

/*sorting list using bubble sort*/
void sort_list(node *head)
{
    if(head == NULL)
        return ;
    if(head->next == NULL)
        return ;
    bool swapped = false;
    do
    {
        swapped = false;
        node *current = head;
        node *prev = NULL;
        while(current->next != NULL)
        {
            prev = current;
            current = current->next;
            if(current != NULL)
            {
                if(current->value < prev->value)
                {
                    int tmp;
                    tmp = prev->value;
                    prev->value = current->value;
                    current->value = tmp;
                    swapped = true;
                }
            }
        }
    } while(swapped);
}

/*deleting duplicate values*/
void delete_duplicates(node *head)
{
    if(head == NULL)
        return ;
    if(head->next == NULL)
        return ;
    node *current1, *current2, *duplicate;
    current1 = head;
    while(current1 != NULL && current1->next != NULL)
    {
        current2 = current1;
        while(current2->next != NULL)
        {
            if(current1->value == current2->next->value)
            {
                duplicate = current2->next;
                current2->next = current2->next->next;
                free(duplicate);
            }
            else
                current2 = current2->next;
        }
        current1 = current1->next;
    }
}

/*insert after a given value*/
node *insert_after(node *head, int new_value, int after_value)
{
	node *new_node = malloc(sizeof(node));
	new_node->value = new_value;
	if(head == NULL)
		return(new_node);
	else
	{
		node *current = head;
		while(current->next != NULL)
		{
			if(current->value == after_value)
			{
				new_node->next = current->next;
				current->next = new_node;
				return(head);
			}
			else
				current = current->next;
		}
		new_node->next = current->next;
		current->next = new_node;
		return(head);
	}
}

node *delete_list(node *anode)
{
    if(anode != NULL)
    {
        delete_list(anode->next);
        free(anode);
    }
    return(NULL);
}

/*add list2 values to list1*/
void add_lists(node*list1, node*list2)
{
    if(list1 == NULL  || list2 == NULL)
        return ;
    list1->value = list1->value + list2->value;
    add_lists(list1->next, list2->next);
}

int main(void)
{
    node *list1, *list2;
    list1 = NULL;
    list2 = NULL;

    int i = 1;
    while(i <= 5)
    {
        list1 = insert_at_head(list1, i);
        i++;
    }
    i = 8;
    while(i >= 4)
    {
        list2 = insert_at_head(list2, i);
        i--;
    }
    printf("\nList1:\n");
    print_list(list1);
    printf("\nList 2:\n");
    print_list(list2);
    add_lists(list1, list2);
    printf("\nList1 after add:\n");
    print_list(list1);
}