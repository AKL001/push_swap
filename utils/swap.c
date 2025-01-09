#include "../push_swap.h"


void swap_a(t_stack **a)
{
    int len;

    len = stack_len(*a);
    if (!*a || !a || len == 1)
        return;
    *a = (*a)->next;
    (*a)->prev->prev = *a;
    (*a)->prev->next = (*a)->next;
    if ((*a)->next)
        (*a)->next->prev = (*a)->prev;
    


}