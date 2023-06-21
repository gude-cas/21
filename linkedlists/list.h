#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

typedef struct node
{
    int value;
    struct node *next;
} node;

void print_list(node *head);
node *insert_at_tail(node *head, int new_value);
node *insert_at_head(node *head, int new_value);
node *delete_at_head(node *head);
node *delete_at_tail(node *head);
int list_length(node *head);
int is_member(node *anode, int find_value);
int count_matches(node *anode, int find_value);
void replace_matches(node *anode, int find_value, int replace_value);
node *delete_first_match(node *head, int delete_value, bool *was_deleted);
node *delete_all_matches(node *head, int delete_value, int *num_deleted);
node *efficient_delete_match(node *head, int delete_value, int *num_deleted);
node *append_list(node *head1, node *head2);
node *reverse_list(node *head);
void sort_list(node *head);
void delete_duplicates(node *head);
node *insert_after(node *head, int new_value, int after_value);
node *delete_list(node *anode);
void add_lists(node *list1, node *list2);
node *duplicate_list(node *anode);
node *merge_sorted_lists(node *list1, node *list2);
