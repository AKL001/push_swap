#include "WALO.h"
// Helper function to swap integers
// static void swap(int *a, int *b)
// {
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }


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
// Quick sort implementation
static void quick_sort(int *arr, int low, int high)
{
    if (low < high)
    {
        // Use middle element as pivot to handle already sorted arrays better
        int pivot = arr[(low + high) / 2];
        int i = low - 1;
        int j = high + 1;
        
        while (1)
        {
            do {
                i++;
            } while (arr[i] < pivot);
            
            do {
                j--;
            } while (arr[j] > pivot);
            
            if (i >= j)
                break;
                
            swap(&arr[i], &arr[j]);
        }
        
        quick_sort(arr, low, j);
        quick_sort(arr, j + 1, high);
    }
}

int *sort_array_copy(t_stack *stack, int size)
{
    int *arr;
    int i;
    t_stack *tmp;
    
    arr = (int *)malloc(sizeof(int) * size);
    if (!arr)
        return NULL;
    i = 0;
    tmp = stack;
    while (tmp)
    {
        arr[i] = tmp->value;
        i++;
        tmp = tmp->next;
    }
    quick_sort(arr, 0, size - 1);
    
    return arr;
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