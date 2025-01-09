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

    if (*b == NULL)
        return;
    tmp = (*b);                                             
    *b = (*b)->next;
    if (*b)  
        (*b)->prev = NULL;
    tmp->next = *a; 
    if (*a)         
        (*a)->prev = tmp;
    *a = tmp;           
    tmp->prev = NULL;
    write(1, "pa\n",3);
}
void ft_push_to_b(t_stack **a, t_stack **b)
{
    t_stack *tmp;

    if (*a == NULL)
        return;
    tmp = (*a);
    *a = (*a)->next;
    if (*a)  
        (*a)->prev = NULL;
    tmp->next = *b; 
    if (*b)         
        (*b)->prev = tmp;
    *b = tmp;
    tmp->prev = NULL;  
    write(1, "pb\n",3);
}
