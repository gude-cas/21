#include "list.h"

int main(void)
{
    srand(time(NULL));
    node *list1 = NULL;
    node *list2 = NULL;
    int i = 0;
    while (i < 10)
    {
        list1 = insert_at_head(list1, rand() % 99);
        i++;
    }
    i = 0;
    while (i < 10)
    {
        list2 = insert_at_head(list2, rand() % 99);
        i++;
    }
    sort_list(list1);
    sort_list(list2);
    printf("\nList1:\n");
    print_list(list1);
    printf("\nList2:\n");
    print_list(list2);
    node *newhead = merge_sorted_lists(list1, list2);
    printf("\nMerged list:\n");
    print_list(newhead);
}
