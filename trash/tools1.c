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
// void sort_stack(t_stack **a, t_stack **b)
// {
//     int size = stack_len(*a);
//     int chunk_count = (size <= 100) ? 5 : 11;
//     int chunk_size = size / chunk_count;
//     int *sorted = sort_array_copy(*a, size);
//     t_chunk current_chunk;
//     int i = 0;

//     // Process each chunk
//     // for (int i = 0; i < chunk_count; i++)
//     // {
//     while (--size > 3)
//     {
//         // printf("size in sort stack -> %d\n",size);

//         current_chunk.start = sorted[i * chunk_size];
//         // current_chunk.end = sorted[(i + 1) * chunk_size - 1];
//         current_chunk.end = sorted[(i + 1) * chunk_size];

        
//         // Process numbers in current chunk
//         while (has_numbers_in_chunk(*a, current_chunk))
//         {
//             // Find best numbers from top and bottom
//             t_cost top = find_from_top(*a, current_chunk);
//             t_cost bottom = find_from_bottom(*a, current_chunk);
            
//             // Choose the one requiring fewer moves
//             if (top.moves <= bottom.moves && top.index != -1)
//             {
//                 // Move number to top using ra
//                 while (top.moves--)
//                     rotate_a(a);
//             }
//             else if (top.index != -1)
//             {
//                 // Move number to top using rra
//                 while (bottom.moves--)
//                     r_rotate_a(a);
//             }
            
//             // Find target position in B and move accordingly
//             if (*b)
//             {
//                 int target = find_target_pos(*b, (*a)->value);
//                 move_to_position(b, target);
//             }
            
//             // Push to B
//             ft_push_to_b(a, b);
//         }
//         i++;
//         // size--;
//     }
//     if(size == 3)
//     {
//     // printf("size after push => %d\n",size);
//         tiny_sort(a);

//     //     printf("end of tiny sort\n");
//     // while((*a))
//     // {
//     //     printf("a stack left over after  %d\n",(*a)->value);
//     //     (*a) = (*a)->next;
//     // }
//     }
//     // Push back to A in sorted order
//     // printf("------- Stack B ------\n");
//     // while(*b)
//     // {
//     //    while((*b))
//     //     {
//     //         printf("%d\n",(*b)->value);
//     //         (*b) = (*b)->next;
//     //     } 
//     // }
//     while (*b)
//     {
//         int max_pos = find_max_pos(*b);
//         int size_b = stack_len(*b);
        
//         if (max_pos <= size_b / 2)
//             while (max_pos--)
//                 rotate_b(b);
//         else
//             while (max_pos++ < size_b)
//                 r_rotate_b(b);
                
//         ft_push_to_a(a, b);
//     }
//     free(sorted);
// }

// Helper function for minimum value
int MIN(int a, int b)
{
    return (a < b) ? a : b;
}
// void sort_stack(t_stack **a, t_stack **b)
// {
//     int size = stack_len(*a);
//     // Adjust chunk count based on input size for better performance
//     // int chunk_count = (size <= 100) ? 5 : (size <= 250) ? 8 : 11;
//     // int chunk_size = size / chunk_count;
//     int chunk_range;
//     int *sorted = sort_array_copy(*a, size);
//     t_chunk current_chunk;

//     if (size <= 16)
//         chunk_range = 3;
//     else if (size <= 100)
//         chunk_range = 13;
//     else if (size <= 500)
//         chunk_range = 30;
//     else
//         chunk_range = 45;

//     int remaining = size;

//     // Guard against empty stack or memory allocation failure
//     if (!sorted || !*a)
//     {
//         free(sorted);
//         return;
//     }
//     // printf("-------------stack A --------\n");
//     // while ((*a))
//     // {   
//     //     printf("%d\n",(*a)->value);
//     //     (*a) = (*a)->next;
//     // }
//     // printf("---------SORTED LIST------\n");
//     // int j = 0;
//     // while(sorted[j])
//     // {
//     //     printf("%d\n",sorted[j]);
//     //     j++;
//     // }
//     // printf("chunk range => %d\n",chunk_range);
//     // current_chunk.start = sorted[0 * 3];
//     // current_chunk.end = sorted[MIN(1 * chunk_range, size - 1)];
//     // printf("------chunk %d -----\n",0);
//     printf("chunk start => %d\n",sorted[0 * 3]);
//     //         printf("chunk END => %d\n",sorted[1 * 3]);
//     int less = size;
//     // Process chunks until 3 elements remain
//     int i = 0;
//     while (less > 3)
//     {
//         // Calculate chunk boundaries
//         current_chunk.start = sorted[i * chunk_range];
//         current_chunk.end = sorted[MIN((i + 1) * chunk_range , size - 1)];
            
//         // while(sorted[i])
//         // {
//             printf("------chunk %d -----\n",i);
//             printf("chunk start => %d\n",current_chunk.start);
//             printf("chunk END => %d\n",current_chunk.end);
//         // }        
//         // Process current chunk
//         while (has_numbers_in_chunk(*a, current_chunk) && remaining > 3)
//         {
//             t_cost top = find_from_top(*a, current_chunk);
//             t_cost bottom = find_from_bottom(*a, current_chunk);
            
//             // Only proceed if we found a valid number to move
//             if (top.index == -1 && bottom.index == -1)
//                 break;
//             // Choose optimal rotation direction
//             if (top.index != -1 && (top.moves <= remaining / 2))
//             {
//                 while (top.moves-- > 0)
//                     rotate_a(a);
//             }
//             else if (bottom.index != -1)
//             {
//                 int moves = bottom.moves;
//                 while (moves-- > 0)
//                     r_rotate_a(a);
//             }
            
//             // Optimize B stack positioning
//             // if (*b)
//             // {
//             //     int target = find_target_pos(*b, (*a)->value);
//             //     int b_size = stack_len(*b);
                
//             //     // Choose optimal direction for B stack rotation
//             //     if (target > b_size / 2)
//             //         while (target++ < b_size)
//             //             r_rotate_b(b);
//             //     else
//             //         while (target-- > 0)
//             //             rotate_b(b);
//             // }
            
//             if ((*b)->next && ((*b)->value < (*b)->next->value))
//                 swap_b(b);
//             ft_push_to_b(a, b);
//             remaining--;
//         }
//         i++;
//         less--;
//     }

//     // Handle remaining 3 elements
//     if (remaining == 3)
//         tiny_sort(a);
//     // printf("------- Stack B ------\n");
//     // while(*b)
//     // {
//     //    while((*b))
//     //     {
//     //         printf("%d\n",(*b)->value);
//     //         (*b) = (*b)->next;
//     //     } 
//     // }
//     // Optimize pushing back to A
//     while (*b)
//     {
//         // int max_pos = find_max_pos(*b);
//         // int b_size = stack_len(*b);
        
//         // // Choose optimal direction
//         // if (max_pos > b_size / 2)
//         //     while (max_pos++ < b_size)
//         //         r_rotate_b(b);
//         // else
//         //     while (max_pos-- > 0)
//         //         rotate_b(b);
        
//         ft_push_to_a(a, b);
//     }

//     free(sorted);
// }

// void sort_stack(t_stack **a, t_stack **b)
// {
//     int size = stack_len(*a);
//     int chunk_range;
//     int *sorted = sort_array_copy(*a, size);
//     t_chunk current_chunk;
    
//     if (!sorted || !*a)
//     {
//         free(sorted);
//         return;
//     }

//     if (size <= 16)
//         chunk_range = 3;
//     else if (size <= 100)
//         chunk_range = 13;
//     else if (size <= 500)
//         chunk_range = 30;
//     else
//         chunk_range = 45;

//     int remaining = size;
//     // int less = size;
//     int i = 0;

//     while (remaining > 3)
//     {
//         current_chunk.start = sorted[i * chunk_range];
//         current_chunk.end = sorted[MIN((i + 1) * chunk_range, size - 1)];
//         printf("------remaining => %d\n",remaining);
        
//         while (has_numbers_in_chunk(*a, current_chunk))
//         {
//             // Recalculate positions each iteration
//             printf("???remaining => %d\n",remaining);
//             t_cost top = find_from_top(*a, current_chunk);
//             t_cost bottom = find_from_bottom(*a, current_chunk);
//             printf("chunk %d range => [%d ; %d ]\n",i,current_chunk.start,current_chunk.end);
//             printf("----------------\n"); 
//             printf("top index %d , top moves %d \n",top.index,top.moves);
//             printf("bottom index %d, bottom moves %d\n",bottom.index, bottom.moves);

//             if (top.index == -1 && bottom.index == -1)
//                 break;

//             // Store moves in local variables to avoid modifying original values
//             if (top.index != -1 && (top.moves <= remaining / 2))
//             {
//                 int moves = top.moves;
//                 while (moves-- > 0)
//                     rotate_a(a);
//             }
//             else if (bottom.index != -1)
//             {
//                 int moves = bottom.moves;
//                 while (moves-- > 0)
//                     r_rotate_a(a);
//             }
            
//             // Push element and update stack B if needed
//             if (*b && (*b)->next && ((*b)->value < (*b)->next->value))
//                 swap_b(b);
//             ft_push_to_b(a, b);
//             remaining--;
//         }
//         i++;
//         // less--;
//     }
//     // printf()
//     if (remaining == 3)
//         tiny_sort(a);

//     while (*b)
//         ft_push_to_a(a, b);

//     free(sorted);
// }

void sort_stack(t_stack **a, t_stack **b)
{
    int size = stack_len(*a);
    int chunk_range;
    int *sorted = sort_array_copy(*a, size);
    t_chunk current_chunk;
    
    if (!sorted || !*a)
    {
        free(sorted);
        return;
    }

    if (size <= 16)
        chunk_range = 3;
    else if (size <= 100)
        chunk_range = 13;
    else if (size <= 500)
        chunk_range = 30;
    else
        chunk_range = 45;

    int remaining = size;
    int i = 0;

    // Process all but 3 elements
    while (remaining > 3)
    {
        current_chunk.start = sorted[i * chunk_range];
        current_chunk.end = sorted[MIN((i + 1) * chunk_range - 1, size - 1)];
        
        while (has_numbers_in_chunk(*a, current_chunk) && remaining > 3)
        {
            t_cost top = find_from_top(*a, current_chunk);
            t_cost bottom = find_from_bottom(*a, current_chunk);
            
            if (top.index == -1 && bottom.index == -1)
                break;

            if (top.index != -1 && (top.moves <= bottom.moves))
            {
                int moves = top.moves;
                while (moves-- > 0)
                    rotate_a(a);
            }
            else if (bottom.index != -1)
            {
                int moves = bottom.moves;
                while (moves-- > 0)
                    r_rotate_a(a);
            }
            
            // Before pushing to B, optimize B's position
            if (*b)
            {
                int target = find_target_pos(*b, (*a)->value);
                int b_size = stack_len(*b);
                
                // Optimize B position
                if (target > b_size / 2)
                {
                    while (target++ < b_size)
                        r_rotate_b(b);
                }
                else
                {
                    while (target-- > 0)
                        rotate_b(b);
                }
            }
            
            ft_push_to_b(a, b);
            
            // Only swap if needed and if we have at least 2 elements
            if (*b && (*b)->next && ((*b)->value < (*b)->next->value))
                swap_b(b);
                
            remaining--;
        }
        i++;
    }

    // Handle remaining elements
    if (remaining == 3)
        tiny_sort(a);

    // Push back to A in sorted order
    while (*b)
    {
        int max_pos = find_max_pos(*b);
        int b_size = stack_len(*b);
        
        // Choose optimal direction for rotation
        if (max_pos > b_size / 2)
        {
            while (max_pos++ < b_size)
                r_rotate_b(b);
        }
        else
        {
            while (max_pos-- > 0)
                rotate_b(b);
        }
        
        ft_push_to_a(a, b);
    }

    free(sorted);
}