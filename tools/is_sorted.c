#include "../push_swap.h"
// Check if stack is sorted in ascending order
int is_sorted(t_stack *stack)
{
    t_stack *current;
    
    // Handle empty stack or single element
    if (!stack || !stack->next)
        return 1;
        
    current = stack;
    while (current->next)
    {
        // If current value is greater than next value, stack is not sorted
        if (current->value > current->next->value)
            return 0;
        current = current->next;
    }
    return 1;
}

// Optional: Check if stack is sorted in descending order
int is_reverse_sorted(t_stack *stack)
{
    t_stack *current;
    
    if (!stack || !stack->next)
        return 1;
        
    current = stack;
    while (current->next)
    {
        if (current->value < current->next->value)
            return 0;
        current = current->next;
    }
    return 1;
}