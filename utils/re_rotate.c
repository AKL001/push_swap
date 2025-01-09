#include "../push_swap.h"


void r_rotate_a(t_stack **a)
{
    t_stack *last_node;
    int     len;

    len = stack_len(*a);
    if (a == NULL || !*a || len == 1)
        return;
    last_node = find_last_node(*a);
    last_node->prev->next = NULL;
    last_node->next = (*a);
    last_node->prev = NULL;
    *a = last_node;
    last_node->next->prev = last_node;
    write(1, "rra\n",4);
}

void r_rotate_b(t_stack **b)
{
    t_stack *last_node;
    int     len;

    len = stack_len(*b);
    if (b == NULL || !*b || len == 1)
        return;
    last_node = find_last_node(*b);
    last_node->prev->next = NULL;
    last_node->next = (*b);
    last_node->prev = NULL;
    *b = last_node;
    last_node->next->prev = last_node;
    write(1, "rrb\n",4);
}

void r_rotate_a_b(t_stack **a,t_stack **b)
{
    r_rotate_a(a);
    r_rotate_a(b);
    write(1, "rrr\n",4);
}