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

#include "../push_swap.h"

void	error_clean(t_stack **a, t_stack **b, char *action)
{
	if (action)
		free(action);
	free_stack(a);
	free_stack(b);
	write(2, "Error\n", 6);
	exit(1);
}
