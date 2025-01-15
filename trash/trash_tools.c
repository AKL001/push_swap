#include "../push_swap.h"
#include <limits.h>


static int find_best_position(t_stack *b, int value);
static int find_closest_in_range(t_stack *stack, int start, int end);
static int should_double_reverse_rotate(t_stack *b, int value);
static int should_double_rotate(t_stack *b, int value);
static void optimize_b_placement(t_stack **b, int value);
int MIN(int a, int b)
{
    return (a < b) ? a : b;
}
// Helper function for checking numbers in range
static int has_numbers_in_range(t_stack *stack, int start, int end)
{
    while (stack)
    {
        if (stack->value >= start && stack->value <= end)
            return 1;
        stack = stack->next;
    }
    return 0;
}

// Optimized find closest function
static int find_closest_in_range(t_stack *stack, int start, int end)
{
    int top_pos = -1;
    int bottom_pos = -1;
    int pos = 0;
    t_stack *tmp = stack;
    
    // Find both top and bottom positions in one pass
    while (tmp)
    {
        if (tmp->value >= start && tmp->value <= end)
        {
            if (top_pos == -1)
                top_pos = pos;
            bottom_pos = pos;
        }
        pos++;
        tmp = tmp->next;
    }
    
    if (top_pos == -1)
        return -1;
    
    // Return the position that requires fewer moves
    int total_len = pos;  // This is our stack length
    return (top_pos <= (total_len - bottom_pos)) ? top_pos : total_len;
}

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
// Optimized B placement
static void optimize_b_placement(t_stack **b, int value)
{
    if (!*b)
        return;

    int current_size = stack_len(*b);
    int best_pos = find_best_position(*b, value);

    if (best_pos <= current_size / 2)
    {
        while (best_pos-- > 0)
            rotate_b(b);
    }
    else
    {
        while (best_pos++ < current_size)
            r_rotate_b(b);
    }
}

// Helper to find best position in B
static int find_best_position(t_stack *b, int value)
{
    int pos = 0;
    int best_pos = 0;
    int current_pos = 0;
    int max = INT_MIN;
    t_stack *tmp = b;

    // Find position where value should go
    while (tmp)
    {
        if (tmp->value > max)
        {
            max = tmp->value;
            best_pos = current_pos;
        }
        if (tmp->value > value && (pos == 0 || tmp->value < b->value))
            pos = current_pos;
        current_pos++;
        tmp = tmp->next;
    }

    return (value > max) ? best_pos : pos;
}

static int should_double_rotate(t_stack *b, int value)
{
    if (!b || !b->next)
        return 0;
    int target_pos = find_best_position(b, value);
    return (target_pos == 1);
}

static int should_double_reverse_rotate(t_stack *b, int value)
{
    if (!b)
        return 0;
    int size = stack_len(b);
    int target_pos = find_best_position(b, value);
    return (target_pos == size - 1);
}

void sort_stack(t_stack **a, t_stack **b)
{
    int size = stack_len(*a);
    int chunk_range;
    int *sorted;
    int remaining;
    int i = 0;

    // Set chunk range based on initial size
    if (size <= 16)
        chunk_range = 3;
    else if (size <= 100)
        chunk_range = 13;
    else if (size <= 500)
        chunk_range = 30;
    else
        chunk_range = 45;

    sorted = sort_array_copy(*a, size);
    if (!sorted || !*a)
    {
        free(sorted);
        return;
    }

    remaining = size;
    
    // Process chunks until 3 elements remain
    while (remaining > 3)
    {
        // Recalculate current stack size
        int current_size = stack_len(*a);
        
        // Calculate chunk boundaries for current iteration
        int chunk_start = sorted[i * chunk_range];
        int chunk_end = sorted[MIN((i + 1) * chunk_range, size - 1)];
        
        // Process current chunk
        while (has_numbers_in_range(*a, chunk_start, chunk_end))
        {
            // Recalculate size for each operation
            current_size = stack_len(*a);
            int pos = find_closest_in_range(*a, chunk_start, chunk_end);
            
            if (pos <= current_size / 2)
            {
                while (pos > 0)
                {
                    if (*b && should_double_rotate(*b, (*a)->value))
                        rotate_a_b(a, b);
                    else
                        rotate_a(a);
                    pos--;
                }
            }
            else
            {
                while (pos < current_size)
                {
                    if (*b && should_double_reverse_rotate(*b, (*a)->value))
                        rr_rotate(a, b);
                    else
                        r_rotate_a(a);
                    pos++;
                }
            }
            
            optimize_b_placement(b, (*a)->value);
            ft_push_to_b(a, b);
            remaining--;

            // Break if we reach 3 elements
            if (remaining <= 3)
                break;
        }
        i++;
        
        // Reset chunk index if we've gone too far
        if (i * chunk_range >= size)
            i = 0;
    }

    // Handle remaining elements
    if (remaining <= 3)
        tiny_sort(a);

    while (*b)
    {
        int max_pos = find_max_pos(*b);
        int b_size = stack_len(*b);
        
        // Choose optimal direction
        if (max_pos > b_size / 2)
            while (max_pos++ < b_size)
                r_rotate_b(b);
        else
            while (max_pos-- > 0)
                rotate_b(b);
        
        ft_push_to_a(a, b);
    }
    
    free(sorted);
}
