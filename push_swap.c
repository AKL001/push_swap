/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablabib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:24:45 by ablabib           #+#    #+#             */
/*   Updated: 2025/01/18 12:06:11 by ablabib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (1);
	stack_init(&a, argv + 1);
	if (!is_sorted(a))
	{
		if (stack_len(a) <= 3)
			tiny_sort(&a);
		else if (stack_len(a) == 5 || stack_len(a) == 4)
			holy_sort(&a, &b);
		else
			sort_stack(&a, &b);
	}
	free_stack(&a);
	free_stack(&b);
	return (0);
}
