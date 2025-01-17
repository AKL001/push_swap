/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablabib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:27:24 by ablabib           #+#    #+#             */
/*   Updated: 2025/01/16 11:28:52 by ablabib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>
#include <stdio.h>

static long	ft_atol(char *str)
{
	long	res;
	int		i;
	int		sign;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (res * sign);
}

void	stack_init(t_stack **a, char **argv)
{
	long	nbr;
	int		i;
	int		j;
	char	**av;

	i = 0;
	while (argv[i])
	{
		av = ft_split(argv[i],' ');
		if (!av)
			ft_error(a, NULL);
		j = 0;
		while (av[j])
		{
			nbr = ft_atol(av[j]);
			if (nbr > INT_MAX || nbr < INT_MIN
				|| error_repetition(*a, (int)nbr))
				ft_error(a, av);
			if (append_node(a, (int)nbr))
				ft_error(a, av);
			j++;
		}
		free_av(av);
		i++;
	}
}
