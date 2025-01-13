#include "../push_swap.h"
#include <limits.h>

int find_position(t_stack *stack, int value)
{
    int pos = 0;
    t_stack *tmp = stack;
    
    while (tmp)
    {
        if (tmp->value == value)
            return pos;
        pos++;
        tmp = tmp->next;
    }
    return -1;
}

int calculate_moves(t_stack *stack, int pos)
{
    int size = stack_len(stack);
    
    if (pos <= size / 2)
        return pos;
    return (size - pos) * -1;  // Negative indicates rra
}

// Structure to hold chunk information
typedef struct s_chunk {
    int start;
    int end;
} t_chunk;

// Structure to hold position costs
typedef struct s_cost {
    int index;      // Position in stack
    int moves;      // Number of moves needed
    int is_ra;      // 1 for ra, 0 for rra
} t_cost;

int is_in_chunk(int num, t_chunk chunk)
{
    return (num >= chunk.start && num <= chunk.end);
}

// Helper function to check if chunk has numbers in stack
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

// Helper functions for finding min/max
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
// Find number's position in stack
int get_position(t_stack *stack, int value)
{
    int pos = 0;
    t_stack *tmp = stack;
    
    while (tmp)
    {
        if (tmp->value == value)
            return pos;
        pos++;
        tmp = tmp->next;
    }
    return -1;
}

// Check if number is within chunk range

typedef struct s_cost {
    int index;      // Position in stack
    int moves;      // Number of moves needed
    int is_ra;      // 1 for ra, 0 for rra
} t_cost;

typedef struct s_chunk {
    int start;
    int end;
} t_chunk;

// Find the best number to move from top half
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
// Find position of minimum value in stack
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

// Move stack to specific position using optimal rotation
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

// Find target position in stack B
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