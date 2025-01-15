#include "../push_swap.h"
#include <limits.h>

int MIN(int a, int b)
{
    if (a < b)
        return (a);
    else
        return (b);
}

int is_in_chunk(int num, t_chunk chunk)
{
    return (num >= chunk.start && num <= chunk.end);
}

t_max_cost find_max(t_stack *stack,int size)
{
    t_max_cost max;
    int pos;

    max.value = INT_MIN;
    max.moves = -1;
    max.poss = -1;
    pos = 0;
    while (stack)
    {
        if (stack->value > max.value)
        {
            if (pos > size / 2)
                max.moves = size - pos;
            else
                max.moves  = pos;
            max.value = stack->value;
            max.poss = pos;
        }
        pos++;
        stack = stack->next;
    }
    return max;
}

int is_sorted(t_stack *stack)
{
    t_stack *current;

    if (!stack || !stack->next)
        return 1;
        
    current = stack;
    while (current->next)
    {
        if (current->value > current->next->value)
            return 0;
        current = current->next;
    }
    return 1;
}
