/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablabib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:30:21 by ablabib           #+#    #+#             */
/*   Updated: 2025/01/16 11:30:36 by ablabib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	checker_rotate_a(t_stack **a)
{
	t_stack	*last_node;
	int		len;

	len = stack_len(*a);
	if (a == NULL || !*a || len == 1)
		return ;
	last_node = find_last_node(*a);
	last_node->next = *a;
	*a = (*a)->next;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

void	checker_rotate_b(t_stack **b)
{
	t_stack	*last_node;
	int		len;

	len = stack_len(*b);
	if (b == NULL || !*b || len == 1)
		return ;
	last_node = find_last_node(*b);
	last_node->next = *b;
	*b = (*b)->next;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

void	checker_rotate_a_b(t_stack **a, t_stack **b)
{
	checker_rotate_a(a);
	checker_rotate_b(b);
}
