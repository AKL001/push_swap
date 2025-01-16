/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablabib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:29:21 by ablabib           #+#    #+#             */
/*   Updated: 2025/01/16 11:29:54 by ablabib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_push_to_a(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (*b == NULL)
		return ;
	tmp = (*b);
	*b = (*b)->next;
	if (*b)
		(*b)->prev = NULL;
	tmp->next = *a;
	if (*a)
		(*a)->prev = tmp;
	*a = tmp;
	tmp->prev = NULL;
	write(1, "pa\n", 3);
}

void	ft_push_to_b(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (*a == NULL)
		return ;
	tmp = (*a);
	*a = (*a)->next;
	if (*a)
		(*a)->prev = NULL;
	tmp->next = *b;
	if (*b)
		(*b)->prev = tmp;
	*b = tmp;
	tmp->prev = NULL;
	write(1, "pb\n", 3);
}
