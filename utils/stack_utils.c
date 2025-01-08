#include "../push_swap.h"

t_stack     *find_last_node(t_stack *head)
{
    if (head == NULL)
        return (NULL);
    while(head->next)
        head = head->next;
    return (head);
}

void    append_node(t_stack **stack,int nbr)
{
    t_stack *last_node;
    t_stack *node;

    if (stack == NULL)
        return;
    node = malloc(sizeof(t_stack));
    if (!node)
        return;
    node->next = NULL;
    node->value = nbr;
    // append first node have no prev 
    if (*stack == NULL)
    {
        *stack = node;
        node->prev = NULL;
    }
    else
    {
        last_node = find_last_node(*stack);
        last_node->next = node;
        node->prev = last_node;
    }
}

int     stack_len(t_stack *stack)
{
    int count;

    if(stack == NULL)
        return 0;
    count = 0;
    while(stack)
    {
        count++;
        stack = stack->next;
    }
    return (count);
}