#include "../push_swap.h"

// typedef struct s_push_swap
// {
//     int value;
//     struct s_push_swap  *prev;
//     struct s_push_swap  *next;
// } t_stack;

void ft_push_to_a(t_stack **a, t_stack **b)
{
    t_stack *tmp;

    if (*b == NULL) // If b is empty, do nothing
        return;
    tmp = (*b);
    *b = (*b)->next;
    if (*b)  // If b is not empty after the move, set the previous pointer of the new top of b to NULL
        (*b)->prev = NULL;
    tmp->next = *a;  // Set the next of the node from b to the current top of a
    if (*a)          // If a is not empty, set the previous pointer of the current top of a to the new element
        (*a)->prev = tmp;
    *a = tmp;  // Set a to point to the new top element, which was taken from b
    tmp->prev = NULL;  // The previous pointer of the new top element of a is NULL
}
