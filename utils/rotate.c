#include "../push_swap.h"


void rotate_a(t_stack **a)
{
    t_stack *last_node;
    int     len;

    len = stack_len(*a);
    if (a == NULL || !*a || len == 1)
        return;
    last_node = find_last_node(*a);
    last_node->next = *a;
    *a = (*a)->next;
    last_node->next->prev = last_node;
    last_node->next->next = NULL;
    write(1, "ra\n",3);
}
void rotate_b(t_stack **b)
{
    t_stack *last_node;
    int     len;

    len = stack_len(*b);
    if (b == NULL || !*b || len == 1)
        return;
    last_node = find_last_node(*b);
    last_node->next = *b;
    *b = (*b)->next;
    last_node->next->prev = last_node;
    last_node->next->next = NULL;
    write(1, "rb\n",3);
}
void rotate_a_b(t_stack **a,t_stack **b)
{
    rotate_a(a);
    rotate_b(b);
    write(1, "rr\n",3);
}