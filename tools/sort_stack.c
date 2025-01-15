#include "../push_swap.h"
#include <limits.h>


// t_max_cost find_min(t_stack *stack)
// {
//     int min = INT_MAX;

//     while (stack)
//     {
//         if (stack->value < min)
//             min = stack->value;
//         stack = stack->next;
//     }
//     return min;
// }

t_max_cost find_max(t_stack *stack,int size)
{
    t_max_cost max = {INT_MIN , -1 , -1};
    // t_stack *tmp = stack;
    int pos = 0;

    while (stack)
    {
        if (stack->value > max.value)
        {
            if (pos > size / 2)
            {
                max.value = stack->value;
                max.moves = size - pos;
                max.poss = pos;
            }
            else
            {
                max.value = stack->value;
                max.moves  = pos;
                max.poss = pos;
            }
        }
        pos++;
        stack = stack->next;
    }
    return max;
}



int chunk_range(int size)
{
    int range;

    if (!size)
        return (0);
    if (size <= 16)
        range = 3;
    else if (size <= 100)
        range = 13;
    else if (size <= 500)
        range = 30;
    else
        range = 45;
    return (range);
}
int is_in_chunk(int num, t_chunk chunk)
{
    return (num >= chunk.start && num <= chunk.end);
}

int MIN(int a, int b)
{
    return (a < b) ? a : b;
}

int number_in_chunk(t_stack *stack, t_chunk chunk)
{
    t_stack *tmp = stack;
    
    // if (remaining <= 3)
    //     return 0;
    while (tmp)
    {
        if (is_in_chunk(tmp->value, chunk))
            return 1;
        tmp = tmp->next;
    }
    return 0;
}
t_cost find_from_bottom(t_stack *a, t_chunk chunk,int size)
{
    t_cost cost = {-1, INT_MAX, 0};
    t_stack *tmp = a;
    // int size = stack_len(a);
    int pos = 0;
    
    while (tmp)
    {
        if (pos > size / 2 && is_in_chunk(tmp->value, chunk))  // Check only bottom half
        {
            cost.index = pos;
            cost.moves = size - pos;  // Calculate reverse rotations needed
            cost.is_ra = 0;
            // return cost;
        }
        pos++;
        tmp = tmp->next;
    }
    return cost;
}
t_cost find_from_top(t_stack *a, t_chunk chunk,int size)
{
    t_cost cost = {-1, INT_MAX, 0};
    t_stack *tmp = a;
    int pos = 0;
    // int size = stack_len(a);
    
    while (tmp && pos <= size / 2)  // Check only top half
    {
        if (is_in_chunk(tmp->value, chunk))
        {
            cost.index = pos;
            cost.moves = pos;
            cost.is_ra = 1;
            // return cost;
        }
        pos++;
        tmp = tmp->next;
    }
    return cost;
}
int find_min_value(t_stack *stack)
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

// Helper to find the max value in stack
int find_max_value(t_stack *stack)
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
t_min_cost find_min(t_stack *stack, int size)
{
    t_min_cost min = {INT_MAX, -1, -1};
    int pos = 0;
    
    while (stack)
    {
        if (stack->value < min.value)
        {
            if (pos > size / 2)
            {
                min.value = stack->value;
                min.moves = size - pos;
                min.poss = pos;
            }
            else
            {
                min.value = stack->value;
                min.moves = pos;
                min.poss = pos;
            }
        }
        pos++;
        stack = stack->next;
    }
    return min;
}
// void smart_push_to_b(t_stack **a,t_stack **b)
// {
//     if (!*a)
//         return;
//     if (!*b)
//         ft_push_to_b(a,b);
//     int num_to_push = (*a)->value;
//     int b_len = stack_len(*b);
//     t_min_cost is_min;

//     is_min = find_min(*b,b_len);
//     if((*b)->value != is_min.value)
//     {
//         if (is_min.poss <= b_len / 2)
//             while(is_min.poss-- > 0)
//                 rotate_b(b);
//         else
//             while(is_min.poss++ < b_len)
//                 r_rotate_b(b);
//     }
//     ft_push_to_b(a,b);
// }
void smart_push_to_b(t_stack **a,t_stack **b)
{
    if (!*a)
        return;
    if (!*b)
        ft_push_to_b(a,b);
    int num_to_push = (*a)->value;
    int b_len = stack_len(*b);
    t_max_cost max;

    max = find_max(*b,b_len);
    if((*b)->value != max.value)
    {
        if (max.poss <= b_len / 2)
            while(max.poss-- > 0)
                rotate_b(b);
        else
            while(max.poss++ < b_len)
                r_rotate_b(b);
    }
    ft_push_to_b(a,b);
}

void push_back_to_a(t_stack **b,t_stack **a)
{
    if (!*b)
        return;
    // int i = 0;
    while (*b)
    {
        t_max_cost max;
        int b_len = stack_len(*b);
        if (!b_len)
            return;
        max = find_max(*b,b_len);
        // printf("the %d max => %d\n",i++,max.value);
        if (max.moves != -1 && (max.poss <= b_len / 2))
        {
            while (max.poss-- > 0)
                rotate_b(b);
        }
        else
            while(max.poss++ < b_len)
                r_rotate_b(b);
        // else if (max.moves != -1)
        // {
        //     while (max.moves-- > 0)
        //         r_rotate_b(b);
        // }
        ft_push_to_a(a, b);
    }
}

int	is_reverse(t_stack **a)
{
	t_stack	*tmp;
	int		len;
	int		i;

	i = 0;
	tmp = *a;
	len = stack_len(*a);
	while ((tmp)->value > (tmp)->next->value)
	{
			i++;
		tmp = (tmp)->next;
	}
	i++;
	if (i == len)
    {
        printf("its rra\n");
        return 1;
    }
		// r_rotate_a(a);
	else
    {
        printf("its ra \n");
        return 0;
    }
		// rotate_a(a);
}

void sort_stack(t_stack **a, t_stack **b)
{
    int size;
    int chunk;
    int *sorted;
    int remaining;
    int max;
    t_chunk currect_chunk;
    t_cost top;
    t_cost bottom;
    int i;


    size = stack_len(*a);
    sorted = sort_array_copy(*a, size);
    if (!sorted || !*a)
    {
        free(sorted);
        return;
    }
    remaining = stack_len(*a);
    chunk = chunk_range(size); 
    i = 0;
    // while (remaining >= 0)
    while (*a)
    {
        if (i > size - chunk)
            i = size - chunk;
        currect_chunk.start = sorted[i];
        currect_chunk.end = sorted[MIN((i + 1) + (chunk - 1), size - 1)];
        // printf("chunk  %d range [%d;%d]\n",i,currect_chunk.start,currect_chunk.end);
        if ((*a) && is_in_chunk((*a)->value, currect_chunk) || (*a)->value < currect_chunk.start)
        {
            if(stack_len(*b) >= 2)
                if ((*b)->next && (*b)->value < (*b)->next->value)
                    swap_b(b);
            ft_push_to_b(a, b);
            i++;
            // smart_push_to_b(a,b);
        }
        if(is_reverse(a))
            r_rotate_a(a);
        else
            rotate_a(a);
        // else
        //     rotate_a(a);
            // check_revers(a);
        // i++;
        // i++;
        // remaining--;
    }
    // printf("------ BACK TO A ------\n");
    push_back_to_a(b,a);
    // printf("======== STACK B ==========\n");
    // while(*b)
    // {
    //     printf("%d\n",(*b)->value);
    //     (*b) = (*b)->next; 
    // }
    // while (remaining >= 0)
    // {
    //     currect_chunk.start = sorted[i * chunk];
    //     currect_chunk.end = sorted[MIN((i + 1) * chunk, size -1)];
    //     printf("chunk range [%d;%d]\n",currect_chunk.start,currect_chunk.end);
    //     while(number_in_chunk(*a,currect_chunk) && remaining >= 0)
    //     {
    //         // if(remaining <= 3)
    //         //     break;
    //         printf("remainind => %d\n",remaining);
            
    //         // remaining--;
    //         top = find_from_top(*a,currect_chunk,remaining);
    //         bottom = find_from_bottom(*a,currect_chunk,remaining);

    //         if (top.index == -1 && bottom.index == -1)
    //             break;

    //         // if (top.index != -1 && (top.moves <= bottom.moves))
    //         // {
    //         //     while (top.moves-- > 0)
    //         //         rotate_a(a);
    //         // }
    //         // else if (bottom.index != -1)
    //         // {
    //         //     while (bottom.moves-- > 0)
    //         //         r_rotate_a(a);
    //         // }
            
    //         if (*b && (*b)->next && ((*b)->value < (*b)->next->value))
    //             swap_b(b);
    //         ft_push_to_b(a, b);
    //         remaining--;
    //     }
    //     i++;
    // }
    // if (remaining == 2)
    //     tiny_sort(a);
    // printf("----------STACK B----- \n");
    // while(*b)
    // {
    //     printf("%d\n",(*b)->value);
    //     (*b) = (*b)->next;
    // }
    // printf("------ NOW after tiny sort ------\n");
    // push_back_to_a(b,a);
    // printf("ok ok \n");
    free(sorted);
}
