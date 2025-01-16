/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sorts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablabib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:12:22 by ablabib           #+#    #+#             */
/*   Updated: 2025/01/16 11:12:50 by ablabib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <limits.h>

t_stack	*find_highest(t_stack *a)
{
	t_stack	*max;

	if (!a)
		return (NULL);
	max = a;
	while (a != NULL)
	{
		if (a->value > max->value)
			max = a;
		a = a->next;
	}
	return (max);
}

void	tiny_sort(t_stack **a)
{
	t_stack	*big_node;

	big_node = find_highest(*a);
	if (*a == big_node)
		rotate_a(a);
	else if ((*a)->next == big_node)
		r_rotate_a(a);
	if ((*a)->value > (*a)->next->value)
		swap_a(a);
}

t_min_cost	find_min(t_stack *stack, int size)
{
	t_min_cost	min;
	int			pos;

	min.value = INT_MAX;
	min.moves = -1;
	min.poss = -1;
	pos = 0;
	while (stack)
	{
		if (stack->value < min.value)
		{
			if (pos > size / 2)
				min.moves = size - pos;
			else
				min.moves = pos;
			min.value = stack->value;
			min.poss = pos;
		}
		pos++;
		stack = stack->next;
	}
	return (min);
}

void	holy_sort(t_stack **a, t_stack **b)
{
	t_min_cost	min;
	int			len;

	if (!*a)
		return ;
	len = stack_len(*a);
	while (len > 3)
	{
		min = find_min(*a, len);
		if ((*a)->value == min.value)
		{
			ft_push_to_b(a, b);
			len--;
		}
		min = find_min(*a, len);
		if ((*a)->value != min.value && (min.poss <= len / 2) && len > 3)
			rotate_a(a);
		if ((*a)->value != min.value && (min.poss > len / 2) && len > 3)
			r_rotate_a(a);
	}
	if (len == 3)
		tiny_sort(a);
	push_back_to_a(b, a);
	exit(0);
}
