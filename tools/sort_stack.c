#include "../push_swap.h"
#include <limits.h>

int chunk_range(int size)
{
    int range;

    if (!size)
        return (0);
    if (size <= 6)
        range = 2;
    if (size <= 16)
        range = 3;
    else if (size <= 100)
        range = 3;
    else if (size <= 500)
        range = 30;
    else
        range = 45;
    return (range);
}

void push_back_to_a(t_stack **b,t_stack **a)
{
    if (!*b)
        return;
    while (*b)
    {
        t_max_cost max;
        int b_len = stack_len(*b);
        if (!b_len)
            return;
        max = find_max(*b,b_len);
        if (max.moves != -1 && (max.poss <= b_len / 2))
        {
            while (max.poss-- > 0)
                rotate_b(b);
        }
        else
            while(max.poss++ < b_len)
                r_rotate_b(b);
        ft_push_to_a(a, b);
    }
}

int	is_reverse(t_stack **a)
{
	t_stack	*tmp;
	int		len;
	int		j;

	j = 0;
	tmp = *a;
	len = stack_len(*a);
	while ((tmp)->next)
	{
		if ((tmp)->value > (tmp)->next->value)
			j++;
		tmp = (tmp)->next;
	}
    j++;
	if (j == len)
        r_rotate_a(a);
	else
        rotate_a(a);
}

void push_to_a_chunk_range(t_stack **a,t_stack **b,int *i,t_chunk currect_chunk)
{
    if ((*a) && is_in_chunk((*a)->value, currect_chunk))
    {
        if(stack_len(*b) >= 2)
            if ((*b)->next && (*b)->value < (*b)->next->value)
                swap_b(b);
        ft_push_to_b(a, b);
        *i += 1;
    }
    else if ((*a)->value < currect_chunk.start)
    {
        ft_push_to_b(a,b);
        rotate_b(b);
        *i += 1;            
    }
    else
        is_reverse(a);
}

void sort_stack(t_stack **a, t_stack **b)
{
    int size;
    int chunk;
    int *sorted;
    t_chunk currect_chunk;
    int i;

    size = stack_len(*a);
    sorted = sort_list(*a);
    if (!sorted || !*a)
    {
        free(sorted);
        return;
    }
    chunk = chunk_range(size); 
    i = 0;
    while (*a)
    {
        if (i > size - chunk)
            i = size - chunk;
        currect_chunk.start = sorted[i];
        currect_chunk.end = sorted[MIN((i + 1) + (chunk - 1), size - 1)];
        push_to_a_chunk_range(a,b,&i,currect_chunk);  
    }
    push_back_to_a(b,a);
    free(sorted);
}
