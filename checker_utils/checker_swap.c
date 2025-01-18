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

void	checker_swap_a(t_stack **a)
{
	int		len;
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	if (!a || !*a || !(*a)->next)
		return ;
	first = *a;
	second = (*a)->next;
	third = second->next;
	*a = second;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	first->next = third;
	if (third)
		third->prev = first;
}

void	checker_swap_b(t_stack **b)
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
}

void	checker_swap_a_b(t_stack **a, t_stack **b)
{
	checker_swap_a(a);
	checker_swap_b(b);
}
