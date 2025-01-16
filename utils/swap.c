/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablabib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:33:30 by ablabib           #+#    #+#             */
/*   Updated: 2025/01/16 11:33:32 by ablabib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_a(t_stack **a)
{
	int	len;

	len = stack_len(*a);
	if (!*a || !a || len == 1)
		return ;
	*a = (*a)->next;
	(*a)->prev->prev = (*a);
	if ((*a)->next)
	{
		(*a)->prev->next = (*a)->next;
		(*a)->next->prev = (*a)->prev;
	}
	(*a)->next = (*a)->prev;
	(*a)->prev = NULL;
	write(1, "sa\n", 3);
}

void	swap_b(t_stack **b)
{
	int		len;
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	if (!b || !*b || !(*b)->next)
		return ;
	first = *b;
	second = (*b)->next;
	third = second->next;
	*b = second;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	first->next = third;
	if (third)
		third->prev = first;
	write(1, "sb\n", 3);
}

void	swap_a_b(t_stack **a, t_stack **b)
{
	swap_a(a);
	swap_b(b);
	write(1, "ss\n", 3);
}
