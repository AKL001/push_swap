#include "../push_swap.h"
#include <limits.h>

int find_min(t_stack *stack)
{
    int min = INT_MAX;
    while (stack)
    {
        if (stack->value < min)
            min = stack->value;
        stack = stack->next;
    }
    return min;
}

int find_max(t_stack *stack)
{
    int max = INT_MIN;
    while (stack)
    {
        if (stack->value > max)
            max = stack->value;
        stack = stack->next;
    }
    return max;
}
int is_in_chunk(int num, t_chunk chunk)
{
    return (num >= chunk.start && num <= chunk.end);
}
int has_numbers_in_chunk(t_stack *stack, t_chunk chunk)
{
    t_stack *tmp = stack;
    
    while (tmp)
    {
        if (is_in_chunk(tmp->value, chunk))
            return 1;
        tmp = tmp->next;
    }
    return 0;
}
void move_to_position(t_stack **stack, int target_pos)
{
    int size = stack_len(*stack);
    
    if (target_pos <= size / 2)
    {
        // Use rotate if target is in upper half
        while (target_pos--)
            rotate_b(stack);
    }
    else
    {
        // Use reverse rotate if target is in lower half
        while (target_pos++ < size)
            r_rotate_b(stack);
    }
}
t_cost find_from_top(t_stack *a, t_chunk chunk)
{
    t_cost cost = {-1, INT_MAX, 0};
    t_stack *tmp = a;
    int pos = 0;
    int mid = stack_len(a) / 2;
    
    while (tmp && pos <= mid)
    {
        if (is_in_chunk(tmp->value, chunk))
        {
            cost.index = pos;
            cost.moves = pos;
            cost.is_ra = 1;
            return cost;
        }
        pos++;
        tmp = tmp->next;
    }
    return cost;
}
int find_min_pos(t_stack *stack)
{
    int min = INT_MAX;
    int pos = 0;
    int min_pos = 0;
    t_stack *tmp = stack;
    
    while (tmp)
    {
        if (tmp->value < min)
        {
            min = tmp->value;
            min_pos = pos;
        }
        pos++;
        tmp = tmp->next;
    }
    return min_pos;
}

// Find position of maximum value in stack
int find_max_pos(t_stack *stack)
{
    int max = INT_MIN;
    int pos = 0;
    int max_pos = 0;
    t_stack *tmp = stack;
    
    while (tmp)
    {
        if (tmp->value > max)
        {
            max = tmp->value;
            max_pos = pos;
        }
        pos++;
        tmp = tmp->next;
    }
    return max_pos;
}
int find_target_pos(t_stack *b, int value)
{
    t_stack *tmp = b;
    int pos = 0;
    int target_pos = 0;
    int found = 0;
    
    // If stack B is empty
    if (!b)
        return 0;
        
    // Find position where value should be inserted
    while (tmp)
    {
        if (tmp->next && tmp->value > value && tmp->next->value < value)
        {
            target_pos = pos + 1;
            found = 1;
            break;
        }
        pos++;
        tmp = tmp->next;
    }
    
    // If no position found, place at top if smallest, bottom if largest
    if (!found)
    {
        if (value < find_min(b))
            target_pos = find_min_pos(b);
        else if (value > find_max(b))
            target_pos = find_max_pos(b);
    }
    
    return target_pos;
}
// Find the best number to move from bottom half
t_cost find_from_bottom(t_stack *a, t_chunk chunk)
{
    t_cost cost = {-1, INT_MAX, 0};
    t_stack *tmp = a;
    int stack_size = stack_len(a);
    int pos = 0;
    int mid = stack_size / 2;
    
    while (tmp)
    {
        if (pos > mid && is_in_chunk(tmp->value, chunk))
        {
            cost.index = pos;
            cost.moves = stack_size - pos;
            cost.is_ra = 0;
            return cost;
        }
        pos++;
        tmp = tmp->next;
    }
    return cost;
}

// Main sorting function
void sort_stack(t_stack **a, t_stack **b)
{
    int size = stack_len(*a);
    int chunk_count = (size <= 100) ? 5 : 11;
    int chunk_size = size / chunk_count;
    int *sorted = sort_array_copy(*a, size);
    t_chunk current_chunk;
    int i = 0;
    // Process each chunk
    // for (int i = 0; i < chunk_count; i++)
    // {
    while (size > 3)
    {
        current_chunk.start = sorted[i * chunk_size];
        current_chunk.end = sorted[(i + 1) * chunk_size - 1];
        
        // Process numbers in current chunk
        while (has_numbers_in_chunk(*a, current_chunk))
        {
            // Find best numbers from top and bottom
            t_cost top = find_from_top(*a, current_chunk);
            t_cost bottom = find_from_bottom(*a, current_chunk);
            
            // Choose the one requiring fewer moves
            if (top.moves <= bottom.moves && top.index != -1)
            {
                // Move number to top using ra
                while (top.moves--)
                    rotate_a(a);
            }
            else if (bottom.index != -1)
            {
                // Move number to top using rra
                while (bottom.moves--)
                    r_rotate_a(a);
            }
            
            // Find target position in B and move accordingly
            if (*b)
            {
                int target = find_target_pos(*b, (*a)->value);
                move_to_position(b, target);
            }
            
            // Push to B
            ft_push_to_b(a, b);
        }
        i++;
        size--;
    }
    if(size == 3)
        tiny_sort(a);
    // Push back to A in sorted order
    while (*b)
    {
        int max_pos = find_max_pos(*b);
        int size_b = stack_len(*b);
        
        if (max_pos <= size_b / 2)
            while (max_pos--)
                rotate_b(b);
        else
            while (max_pos++ < size_b)
                r_rotate_b(b);
                
        ft_push_to_a(a, b);
    }
    
    free(sorted);
}

